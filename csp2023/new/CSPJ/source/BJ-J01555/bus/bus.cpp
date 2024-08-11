#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2e4+5, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
int n, m, k, ans = INF;
struct Edge{
	int v, t;
	inline Edge(int x, int y){ v = x, t = y;}
	inline Edge(){ v = 0, t = INF;}
};
vector<Edge> g[N];\
bitset<100> vis[N];
bitset<100> lim, nxt, nul;
bool vs[N];
void add(int u, int v, int t){
	g[u].push_back(Edge(v, t));
}
void dfs(int u, int d, int wt){
	//cout<<vis[u]<<' '<<u<<' '<<d<<' '<<wt<<endl;
	if(u == n && d%k == 0){
		if(wt%k) wt = (wt/k+1)*k;
		//cout<<d<<' '<<wt<<endl;
		ans = min(ans, d+wt);
	}
	int v, t;
	for(auto e : g[u]){
		v = e.v, t = e.t;
		nxt = ((vis[u]<<1)|(vis[u]>>(k-1)))&lim;
		if((nxt^vis[v]) != nul){
			vis[v] |= nxt;
			dfs(v, d+1, max(wt, max(0, t-d)));
		}
	}
}
#define FILE "bus"
int main(){
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	int u, v, t;
	for(int i = 1; i <= m; i++){
		cin>>u>>v>>t;
		add(u, v, t);
	}
	vis[1][0] = 1;
	for(int i = 0; i < k; i++)
		lim[i] = 1;
	dfs(1, 0, 0);
	if(vis[n][0] == 0) cout<<"NO";
	else cout<<ans;
	return 0;
}
