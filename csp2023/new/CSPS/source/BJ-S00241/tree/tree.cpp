#include<bits/stdc++.h>
using namespace std;
int n;
struct s{
	int h;
	int j;
}d[100005];
long long a[100005],b[100005],c[100005],m=1e18,p=1e18,vis[100005];
vector <int> v[100005];
void dfs(int x,int y,long long t){
	if(x==y){
		p=min(p,t);
		return ;
	}
	for(int i=1;i<=v[x].size();i++){
		if(vis[v[x][i]]==0){
			vis[v[x][i]]=1;
			dfs(v[x][i],y,t+1);
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
		d[i].h=a[i]/max(b[i],(long long)1);
		d[i].j=i;
	}
	int u,w,o=0;
	for(int i=1;i<=n;i++){
		if(d[i].h>o){
			o=d[i].h;
			u=i;
		}
	}
	d[u].h=0;
	dfs(1,d[u].j,0);
	m=min(o+p,m);
	p=1e18;
	o=0;
	for(int i=1;i<=n;i++){
		if(d[i].h>o){
			o=d[i].h;
			w=i;
		}
	}
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}	
	dfs(1,d[w].j,0);

	m=min(o+p,m);
	printf("%lld",m);
	return 0;
}