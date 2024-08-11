#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans;
vector<int> g[10005];
bool vis[10005][10005];
void dfs(int x,int step){
	if(x==n){
		ans=max(ans,step);
		return;
	}
	for(int i=0;i<g[x].size();i++){
		dfs(g[x][i],step+1);
	}
}
void text(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	int u,v,a;
    	cin>>u>>v>>a;
    	g[u].push_back(v);
	}
	dfs(1,0);
	cout<<ans;
}
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    text();
    return 0;
}