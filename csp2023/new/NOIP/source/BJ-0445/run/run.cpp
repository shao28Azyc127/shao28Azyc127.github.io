#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e3 + 5;
int c, T;
struct tsk {
	int y, v;
	tsk() {}
	tsk(int _y, int _v):
		y(_y), v(_v)
	{}
};
vector<tsk> tsks[maxn];
int f[maxn][maxn], mx[2 * maxn], last[2 * maxn];
signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		int n, m, k, d; cin >> n >> m >> k >> d;
		for (int i = 1; i <= n; ++i) vector<tsk>().swap(tsks[i]);
		memset(f, 0xaf, sizeof f);
		for (int i = 1; i <= m; ++i) {
			int x, y, v; cin >> x >> y >> v;
			tsks[x].push_back(tsk(y, v));
		}
		f[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int t = 1; t <= k; ++t) {
				f[i][t] = f[i - 1][t - 1] - d;
			}
			for (int l = 0; l < tsks[i].size(); ++l) {
				int y = tsks[i][l].y;
				int v = tsks[i][l].v;
				for (int t = y; t <= k; ++t) {
					f[i][t] += v;
				}
			}
			for (int t = 0; t <= k; ++t) {
				f[i][0] = max(f[i][0], f[i - 1][t]);
			}
		}
		int ans = 0;
		for (int i = 0; i <= k; ++i) {
			ans = max(ans, f[n][i]);
		}
		cout << ans << endl;
	}
	return 0;
}