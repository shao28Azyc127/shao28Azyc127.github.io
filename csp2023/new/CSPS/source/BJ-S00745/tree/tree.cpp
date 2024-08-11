#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 25;
int n, a[maxn], d[maxn], b[maxn], c[maxn], ans = 1e9;
vector<int> g[maxn];
bool vis[maxn];
int calc(int x, int i) {
	return x * b[i] - ((x * (x + 1)) / 2) * c[i];
}
inline void dfs(int p, int cnt) {
	if (cnt == n) {
		int cur = 0;
		for (int i = 1; i <= n; ++i) {
			if (c[i] < 0) {
				int k = -(b[i] / c[i]);
				int pre = calc(k, i) - calc(d[i] - 1, i);
				if (pre < a[i]) {
					cur = max(cur, a[i] - pre + k);
				} else {
					for (int j = 1; j <= k; ++j) {
						if (calc(j, i) - calc(d[i] - 1, i) < a[i]) {
							cur = max(cur, j);
							break;
						}
					}
				}
			} else {
				int day = d[i], now = 0;
				while (now < a[i]) {
					now += b[i] + c[i] * day;
					++day;
				}
				cur = max(cur, day - 1);
			}
		}
		ans = min(ans, cur);
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) continue;
		for (int j = 0; j < g[i].size(); ++j) {
			int v = g[i][j];
			if (!vis[v]) {
				vis[v] = true;
				d[v] = cnt + 1;
				dfs(v, cnt + 1);
				vis[v] = false;
			}
		}
	}
}
signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n > 20) {
		for (int i = 1; i <= n; ++i) d[i] = i;int cur = 0;
		for (int i = 1; i <= n; ++i) {
			if (c[i] < 0) {
				int k = -(b[i] / c[i]);
				int pre = calc(k, i) - calc(d[i] - 1, i);
				if (pre < a[i]) {
					cur = max(cur, a[i] - pre + k);
				} else {
					for (int j = 1; j <= k; ++j) {
						if (calc(j, i) - calc(d[i] - 1, i) < a[i]) {
							cur = max(cur, j);
							break;
						}
					}
				}
			} else {
				int day = d[i], now = 0;
				while (now < a[i]) {
					now += b[i] + c[i] * day;
					++day;
				}
				cur = max(cur, day - 1);
			}
		}
		ans = min(ans, cur);
		cout << ans << endl;
		return 0;
	}
	vis[1] = true;
	d[1] = 1;
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}