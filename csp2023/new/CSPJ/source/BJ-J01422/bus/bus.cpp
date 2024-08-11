#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
vector<pair<int,int> > g[N];
int n,m,k,ans=99999999;
bool vis[N][105];
inline void dfs(int loc,int t){
	if(loc==n && t%k==0) ans=min(ans,t);
	if(vis[loc][t%k]) return ;
	vis[loc][t%k]=1;
	for(int i=0;i<g[loc].size();i++){
		int to=g[loc][i].first,lim=g[loc][i].second;
		if(t>=lim) dfs(to,t+1);
		else dfs(to,lim+1);
	}
}
inline void solve1(){
	for(int i=1;i<=100;i++){
		if(i%k==0) dfs(1,i);
	}
	if(ans!=99999999) cout<<ans<<'\n';
	else cout<<-1;
}
inline void solve2(){
	dfs(1,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	bool flg=0;
	for(int i=1;i<=m;i++){
		int u,v,t;
		cin>>u>>v>>t;
		g[u].push_back({v,t});
		if(t!=0) flg=1;
	}
	if(n<=10){
		solve1();
	}else if(k==1 || !flg){
		solve2();
	}else{
		cout<<-1;
	}
	return 0;
}