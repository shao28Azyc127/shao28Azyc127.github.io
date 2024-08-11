#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=2e9;
bool vis[10010];
struct node{
	int v,t;
};
vector<node> adj[20010];
void dfs(int u,int tm){
	if(u==n){
		if(tm%k==0){
			ans=min(ans,tm);
		}
		return ;
	}
	vis[u]=1;
	int cnt=2e9;
	for(int i=0;i<adj[u].size();i++){
		if(vis[adj[u][i].v]==0 && tm>=adj[u][i].t){
			dfs(adj[u][i].v,tm+1);
		}
	}
	vis[u]=0;
	return ;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,a;
		cin>>u>>v>>a;
		adj[u].push_back({v,a});
		adj[v].push_back({u,a});
	}
	dfs(1,0);
	if(ans==2e9){
		cout<<-1;
	}else{
		cout<<ans;
	}
	return 0;
}
