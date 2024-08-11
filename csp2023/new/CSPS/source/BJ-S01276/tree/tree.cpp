#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#define maxn 200008
using namespace std;
struct node{
	int a,b,c,d;
	}a[maxn];
vector<int> e[maxn];
int ans=1<<30;
int vis[maxn];

int dfs(int x,int d,int z){
	//cout<<x<<' '<<d<<" "<<z<<endl;
	int y=z,xx=1<<30;
	vis[x]=1;
	while(next_permutation(e[x].begin(),e[x].end())){
		z=y;
		for(int i=0;i<(int)e[x].size();i++){
			int v=e[x][i];
			if(vis[v]==1) continue;
			z=max(z,dfs(v,d+1,max(z,d+a[x].d)));
		}
		xx=min(xx,d+a[x].d);
	}
	vis[x]=0;
	return xx;
}
int main(){	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].d=1;
		while(a[i].a>0){
			a[i].a-=max(a[i].d*a[i].c+a[i].b,1);
			a[i].d++;
		}
		a[i].d-=1;;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
		
	ans=dfs(1,1,0);
	cout<<ans;
	return 0;
}
