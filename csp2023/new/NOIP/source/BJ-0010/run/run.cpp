#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;

int read() {
	int a = 0, b = 0; char c = getchar();
	while (c < '0' || c > '9') b ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') a = a * 10 - 48 + c, c = getchar();
	return b ? -a : a;
}

int c;
const int N = 100005;

int n, m, k, d;
struct dat { int p; ll v; };
typedef vector<dat> vdat;
vdat b[N * 2];
struct qwq { int l, r, v; } a[N];


void sol() {
	n = read(), m = read(), k = read(), d = read();
	if (c == 17 || c == 18) {
		ll ans = 0;
		for (int i = 0; i < m; ++i) {
			int x = read(), y = read(), v = read();
			if (y <= k) ans += max(0ll, v - y * (ll)d);
		}
		cout << ans << '\n';
		return;
	}
	vint t;
	for (int i = 0; i < m; ++i) {
		int x = read(), y = read(), v = read();
		int l = x - y + 1, r = x;
		a[i] = {l - 1, r, v};
		t.push_back(l - 1); t.push_back(r);
		//cerr << l - 1 << ' '  << r << " !!\n";
	}
	sort(t.begin(), t.end()); t.erase(unique(t.begin(), t.end()), t.end());
	for (int i = 0; i < m; ++i)
		a[i].l = lower_bound(t.begin(), t.end(), a[i].l) - t.begin(), a[i].r = lower_bound(t.begin(), t.end(), a[i].r) - t.begin();
	for (int i = 0; i < t.size(); ++i) b[i].clear();
	for (int i = 0; i < m; ++i)
		b[a[i].r].push_back({a[i].l, a[i].v});
	for (int i = 1; i < t.size(); ++i) sort(b[i].begin(), b[i].end(), [&](dat a, dat b) { return a.p < b.p; });
	vdat A, B;
	A.push_back({0, 0});
	for (int i = 1; i < t.size(); ++i) {
		int j = 0; ll su = 0; for (auto [p, v] : b[i]) su += v;
		ll re = (t[i] - t[i - 1]) * (ll)d;
		ll xv = 0;
		ll rxv = 0;
		for (auto [p, v] : A) {
			xv = max(xv, v);
			while (j < b[i].size() && b[i][j].p < p) su -= b[i][j].v, ++j;
			if (t[i] - t[p] <= k) {
				B.push_back({p, v - re + su});
			}
		}
		B.push_back({i, xv});
		A.swap(B); B.clear();
		//cout << re << "   ";
		//for (auto [p, v] : A) cout << p << ' ' << v << "    "; cout << '\n';
	}
	ll ans = 0;
	for (auto [p, v] : A) ans = max(ans, v);
	cout << ans << '\n';
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	c = read(); int T = read();
	while (T--) sol();
	
	return 0;
}