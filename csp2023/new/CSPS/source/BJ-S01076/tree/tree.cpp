#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e5+5, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
int n;
LL ans;
struct Node{
	LL a, b, c;
}p[N];
vector<int> g[N];
void dfs(int u, int fa, int d){
	if(p[u].b == 0 && p[u].c == 0) ans = max(ans, p[u].a+d);
	else{
		LL x = d, h = 0;
		while(h < p[u].a){
			h += p[u].b+x*p[u].c;
			x++;
		}
		ans = max(ans, x);
	}
	for(auto v : g[u]){
		if(v != fa){
			dfs(v, u, d+1);
		}
	}
}
#define FILE "tree"
int main(){
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>p[i].a>>p[i].b>>p[i].c;
	for(int i = 1; i < n; i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1, 1);
	cout<<ans;
	return 0;
}
