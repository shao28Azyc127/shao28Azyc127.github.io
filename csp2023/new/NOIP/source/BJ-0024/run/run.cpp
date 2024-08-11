#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int c, t;
int n, m, k, d;
int l[N], r[N], v[N];

vector<int> val;
int idx(int x) { return lower_bound(val.begin(), val.end(), x) - val.begin() + 1;}
vector<array<int, 2>> vec[N << 2];

ll dp[N << 2];

#define lc (p << 1)
#define rc (lc | 1)
ll mx[N << 4], tg[N << 4];
void init(int n) { memset(mx, 0, n << 5), memset(tg, 0, n << 5);}
void add(int p, ll v) { mx[p] += v, tg[p] += v;}
void modify(int p, int sl, int sr, int ql, int qr, ll v) {
	if (sl >= ql && sr <= qr) return add(p, v);
	if (tg[p]) add(lc, tg[p]), add(rc, tg[p]), tg[p] = 0;
	int mid = (sl + sr) >> 1;
	if (ql <= mid) modify(lc, sl, mid, ql, qr, v);
	if (mid < qr) modify(rc, mid + 1, sr, ql, qr, v);
	mx[p] = max(mx[lc], mx[rc]);
}
inline ll query(int p, int sl, int sr, int ql, int qr) {
	if (sl >= ql && sr <= qr) return mx[p];
	if (tg[p]) add(lc, tg[p]), add(rc, tg[p]), tg[p] = 0;
	int mid = (sl + sr) >> 1; ll ret = 0;
	if (ql <= mid) ret = max(ret, query(lc, sl, mid, ql, qr));
	if (mid < qr) ret = max(ret, query(rc, mid + 1, sr, ql, qr));
	return ret;
}

inline int read() {
	char ch = getchar(); int x = 0;
	while (ch < '0' || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	c = read(), t = read();	
	while (t--) {
		n = read(), m = read(), k = read(), d = read();
		for (int i = 1; i <= m; ++i) {
			r[i] = read();
			int y = read();
			v[i] = read();
			l[i] = r[i] - y + 1;
		}
		
		val.clear();
		for (int i = 1; i <= m; ++i) val.push_back(l[i]), val.push_back(r[i]), val.push_back(l[i] - 1), val.push_back(l[i] - 2);
		sort(val.begin(), val.end()), val.erase(unique(val.begin(), val.end()), val.end());
		
		int len = val.size();
		for (int i = 1; i <= len; ++i) vec[i].clear();
		for (int i = 1; i <= m; ++i) vec[idx(r[i])].push_back({idx(l[i]), v[i]});
		
		init(len); ll ans = 0;
		for (int i = 2; i <= len; ++i) {
			dp[i] = dp[i - 1];
			int p = upper_bound(val.begin(), val.end(), val[i - 1] - k) - val.begin() + 1;
			for (auto &u: vec[i]) {
				int l = u[0], v = u[1];
				modify(1, 0, len, 0, l, v);
			}
			modify(1, 0, len, 0, i, -1ll * (val[i - 1] - val[i - 2]) * d);
			dp[i] = max(dp[i], query(1, 0, len, p, i));
			if (i + 2 <= len) modify(1, 0, len, i + 2, i + 2, dp[i]);
			ans = max(ans, dp[i]);
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}