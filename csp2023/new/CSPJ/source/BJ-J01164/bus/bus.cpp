#include<bits/stdc++.h>
using namespace std;
vector<int> g[20010];
int a[20010][20010];
int ans=INT_MAX;
int n,m,k;
void dfs(int x,int t){
	if(x==n && x%k==0){
		ans=min(ans,t);
		return ;
	}
	for(int i=0;i<g[x].size();i++){
		int u=a[x][i];
		if(t<u) return ;
		int tx=g[x][i];
		dfs(tx,t+1);
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,a1;
		cin>>u>>v>>a1;
		g[u].push_back(v);
		a[u][v]=a1;
	}
	dfs(1,k);
	if(ans==INT_MAX) cout<<-1;
	else cout<<ans;
	return 0;
}
