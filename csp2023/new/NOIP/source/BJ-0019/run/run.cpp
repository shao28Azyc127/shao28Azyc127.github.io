//BJ-0019

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = (s); i <= (t); ++i)
#define per(i, s, t) for(int i = (t); i >= (s); --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 5;

int n, m, k, d;
int l[N], r[N], v[N];
ll f[N];
vector<pair<int, int>> adj[N];
ll lazy[N<<2], mx[N<<2];

inline void setlazy(int o, ll x) {
	mx[o] += x;
	lazy[o] += x;
}

inline void pushdown(int o) {
	if(lazy[o]) {
		setlazy(o << 1, lazy[o]);
		setlazy(o << 1 | 1, lazy[o]);
		lazy[o] = 0;
	}
}

inline void pushup(int o) {
	mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}

inline void add(int o, int ql, int qr, ll x, int l, int r) {
	if(ql <= l && r <= qr) return setlazy(o, x);
	pushdown(o);
	int mid = l + r >> 1;
	if(ql <= mid) add(o << 1, ql, qr, x, l, mid);
	if(mid < qr) add(o << 1 | 1, ql, qr, x, mid+1, r);
	pushup(o);
}

inline void modify(int o, int p, ll x, int l, int r) {
	if(l == r) {
		mx[o] = x;
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if(p <= mid) modify(o << 1, p, x, l, mid);
	else modify(o << 1 | 1, p, x, mid+1, r);
	pushup(o);
}

inline ll query(int o, int ql, int qr, int l, int r) {
	if(ql <= l && r <= qr) return mx[o];
	pushdown(o);
	int mid = l + r >> 1;
	ll res = 0;
	if(ql <= mid) res = max(res, query(o << 1, ql, qr, l, mid));
	if(mid < qr) res = max(res, query(o << 1 | 1, ql, qr, mid + 1, r));
	return res;
}

void solve() {
	cin >> n >> m >> k >> d;
	vector<int> a;
	rep(i, 1, m) {
		int x, y; cin >> x >> y >> v[i];
		r[i] = x, l[i] = x-y+1;
		a.pb(l[i]-1), a.pb(r[i]+1);
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = a.size();
	rep(i, 1, n) adj[i].clear();
	rep(i, 1, m) {
		l[i] = lower_bound(a.begin(), a.end(), l[i]-1) - a.begin() + 1;
		r[i] = lower_bound(a.begin(), a.end(), r[i]+1) - a.begin() + 1;
		adj[r[i]].emplace_back(l[i], v[i]);
	}
	memset(lazy, 0, sizeof lazy);
	memset(mx, 0, sizeof mx);
	int p = 1;
	ll ans = 0;
	rep(i, 1, n) {
		for(auto e : adj[i]) {
			int l = e.fi, val = e.se;
			add(1, 1, l, val, 1, n);
		}
		while(a[i-1] - a[p-1] - 1 > k) ++p;
		f[i] = max(f[i-1], query(1, p, i, 1, n) - 1ll * a[i-1] * d);
		ans = max(ans, f[i]);

		modify(1, i, f[i] + 1ll * (a[i-1] + 1) * d, 1, n);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);

	int id, t; cin >> id >> t;
	while(t--) solve();

	return 0;
}