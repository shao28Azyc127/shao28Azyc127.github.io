#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n;
const int MAXX = 1e5+5;
vector<int> Adj[MAXX];
typedef long long ll;
ll a[MAXX],b[MAXX],c[MAXX];
bool cmp(int x,int y){
	return a[x] > a[y];
}
ll t = 0ll;
ll vis[MAXX];
//queue<int> q;
void dfs(int x){
	//cout<<x<<" ";
	for(int i=0;i<(int)Adj[x].size();i++){
		int v = Adj[x][i];
		if(!vis[v]){
			t++;
			vis[v] = t;
			dfs(v);
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		//cout<<i<<" ";
		sort(Adj[i].begin(),Adj[i].end(),cmp);
		//for(int j=0;j<(int)Adj[i].size();j++)cout<<Adj[i][j]<<" ";
		//cout<<endl;
	}
	t++;
	vis[1] = t;
	dfs(1);
	for(int i=1;i<=n;i++){
		ll h = 0ll;
		for(ll j=vis[i];j<=t;j++){
			h += max(b[i]+j*c[i],1ll);
		}
		if(h >= a[i])continue;
		else{
			while(h < a[i]){
				t++;
				h += max(b[i]+t*c[i],1ll);
			}
		}
	}
	printf("%lld",t);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
