#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int  N = 1e5+9;
int n;
ll a[N], b[N], c[N], now[N], ans1, ans2, d;
bool vis[N];
vector<int> g[N];
void dfs(int p, int fa){
	for(int i=1; i<=n; ++i){
		if(vis[i]) now[i] += max(b[i] + d * c[i], 1ll);
	}
	vis[p] = 1;
	++d;
	for(int i=0; i<g[p].size(); ++i){
		int x = g[p][i];
		if(x==fa) continue;
		dfs(x, p);
	}
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; ++i){
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	}
	for(int i=1; i<n; ++i){
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(1, 0);
	while(1){
		bool k = 0;
		for(int i=1; i<=n; ++i){
			if(now[i]<a[i]){
				k = 1;
				break;
			}
		}
		if(!k){
			ans1 = d;
			break;
		}
		++d;
		for(int i=1; i<=n; ++i){
			now[i] += max(1ll, b[i] + c[i] * d);
		}
	}
	memset(now, 0, sizeof(now));
	memset(vis, 0, sizeof(vis));
	d = 0;
	swap(g[1][0], g[1][1]);
	dfs(1, 0);
	while(1){
		bool k = 0;
		for(int i=1; i<=n; ++i){
			if(now[i]<a[i]){
				k = 1;
				break;
			}
		}
		if(!k){
			ans2 = d;
			break;
		}
		++d;
		for(int i=1; i<=n; ++i){
			now[i] += max(1ll, b[i] + c[i] * d);
		}
	}
	cout<<min(ans1, ans2);
	return 0;
}
