#include <bits/stdc++.h>
#define ll long long
using namespace std;
void file() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
}
struct tree {
	ll a, b, c;
}tr[100010];
int ans = 1e9, n, dfn[100010], rnk[100010], cnt, ct, newt[100010];
ll sum[100010];
vector <int > g[100010];
int main() {
	file();
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> tr[i].a >> tr[i].b >> tr[i].c;
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
    //dfs(1, 0);
    sum[1] += tr[1].b + tr[1].c;
		
	int newt[100010];		
    for(int day = 2; day <= n; ++day) {
		memset(newt, 0, sizeof newt);
		for(int i = 1; i <= n; ++i) {
			cnt = 0;
			if(sum[i]) {
				sum[i] += max(1ll, tr[i].b + day * tr[i].c);
			    continue;
			}
			for(int j = 0; j < g[i].size(); ++j) if(sum[g[i][j]]) {newt[++cnt] = i; break;}
		}
		sort(newt + 1, newt + 1 + cnt, greater<int>());
		sum[newt[1]] += max(1ll, tr[newt[1]].b + day * tr[newt[1]].c);
	}
	for(int i = 1; i <= n; ++i) {
		if(sum[i] >= tr[i].a) ++ct;
	}
    if(ct == n) return cout << n, 0;
    for(int day = n + 1; ;++day) {
		for(int i = 1; i <= n; ++i) sum[i] += max(tr[i].b + day * tr[i].c, 1ll);
		int ct = 0;
		for(int i = 1; i <= n; ++i) {
			if(sum[i] >= tr[i].a) ++ct;
		}
		if(ct == n) {
			cout << day;
			return 0;
		}
	}
	//cout << ans;
}
