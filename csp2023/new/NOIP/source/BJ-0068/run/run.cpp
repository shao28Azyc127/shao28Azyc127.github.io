#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int x[N], y[N], v[N];
vector<int> st[N];
struct tree {
	ll x, lz;
} t[N << 2];
inline void ut(int p, ll x) {
	t[p].x += x;
	t[p].lz += x;
}
inline void pd(int p) {
	ut(p << 1, t[p].lz);
	ut(p << 1 | 1, t[p].lz);
	t[p].lz = 0;
}
void upd(int p, int L, int R, int l, int r, int v) {
	if (l > R || r < L)
		return ;
	if (l <= L && R <= r) {
		ut(p, v);
	// cerr << p << ' ' << L << ' ' << R << ' ' << t[p].x << '\n';
		return ;
	}
	pd(p);
	int mid = (L + R) >> 1;
	upd(p << 1, L, mid, l, r, v);
	upd(p << 1 | 1, mid + 1, R, l, r, v);
	t[p].x = max(t[p << 1].x, t[p << 1 | 1].x);
	// cerr << p << ' ' << L << ' ' << R << ' ' << t[p].x << '\n';
}
ll qry(int p, int L, int R, int l, int r) {
	if (l > R || r < L)
		return 0;
	// cerr << p << ' ' << L << ' ' << R << ' ' << t[p].x << '\n';
	if (l <= L && R <= r)
		return t[p].x;
	pd(p);
	int mid = (L + R) >> 1;
	return max(qry(p << 1, L, mid, l, r), qry(p << 1 | 1, mid + 1, R, l, r));
}
void build(int p, int l, int r) {
	t[p].x = 0;
	if (l == r)
		return ;
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
}
ll dp[N];
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while (t--) {
		int n, m, k, d;
		scanf("%d%d%d%d", &n, &m, &k, &d);
		if (c < 15) {
			build(1, 1, n);
			for (int i = 1; i <= n; i++)
				st[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x[i], &y[i], &v[i]);
			if (c < 15)
				st[x[i]].push_back(i);
		}
		if (17 <= c && c <= 18) {
			ll ans = 0;
			for (int i = 1; i <= m; i++) {
				if (y[i] <= k)
					ans = max(ans, ans + v[i] - 1ll * y[i] * d);
			}
			printf("%lld\n", ans);
		} else if (c < 15) {
			for (int i = 1; i <= n; i++) {
				dp[i] = dp[i - 1];
				for (int j = 0; j < st[i].size(); j++) {
					upd(1, 1, n, 1, x[st[i][j]] - y[st[i][j]] + 1, v[st[i][j]]);
					// cerr << x[st[i][j]] - y[st[i][j]] + 1 << ' ' << v[st[i][j]] << "!\n";
				}
				upd(1, 1, n, 1, i, -d);
				dp[i] = max(dp[i], qry(1, 1, n, max(1, i - k + 1), i));
				upd(1, 1, n, i + 2, i + 2, dp[i]);
				// cerr << i << ' ' << dp[i] << '\n';
			}
			printf("%lld\n", dp[n]);
		} else {
			printf("0\n");
		}
	}
	return 0;
}
