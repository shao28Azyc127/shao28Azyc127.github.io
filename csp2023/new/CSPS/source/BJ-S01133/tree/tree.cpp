#define NDEBUG
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = s; i <= t; ++i)
#define per(i, s, t) for(int i = t; i >= s; --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 5;
const int M = N * 200;

int n;
ll a[N], b[N], c[N];
vector<int> adj[N];
int f[N];
int rt[N], mx[M], sum[M], ls[M], rs[M], tt;
int trash[M], tp;
bool ok;
int siz[N];

inline int newnode() {
	int t = tp ? trash[tp--] : ++tt;
	mx[t] = sum[t] = ls[t] = rs[t] = 0;
	return t;
}

inline __int128 calc(int i, int t) {
	if(c[i] >= 0) {
		return b[i] * t + (__int128)c[i] * t * (t+1) / 2;
	} else {
		ll t0 = (b[i]-1) / (-c[i]);
		if(t0 >= t) {
			return b[i] * t + (__int128)c[i] * t * (t+1) / 2;
		} else {
			return b[i] * t0 + (__int128)c[i] * t0 * (t0+1) / 2 + (t - t0);
		}
	}
}

inline void pushup(int o) {
	mx[o] = max(mx[ls[o]], mx[rs[o]]);
	sum[o] = sum[ls[o]] + sum[rs[o]];
}

inline void merge(int& o1, int o2, int l, int r) {
	if(!o1 || !o2) {
		o1 += o2;
		return;
	}
	if(l == r) {
		mx[o1] = (sum[o1] += sum[o2]);
		trash[++tp] = o2;
		return;
	}
	int mid = l + r >> 1;
	merge(ls[o1], ls[o2], l, mid);
	merge(rs[o1], rs[o2], mid+1, r);
	pushup(o1);
	trash[++tp] = o2;
}

inline int find2(int o, int l, int r) {
	if(l == r) {
		assert(mx[o] == 2);
		assert(sum[o] == mx[o]);
		sum[o] = mx[o] = 1;
		return l;
	}
	int mid = l + r >> 1;
	if(mx[ls[o]] == 2) {
		int res = find2(ls[o], l, mid);
		assert(res != -1);
		pushup(o);
		return res;
	}
	if(mx[rs[o]] == 2) {
	   	int res = find2(rs[o], mid+1, r);
		assert(res != -1);
		pushup(o);
		return res;
	}
	pushup(o);
	return -1;
}

inline void print(int o, int l, int r) {
	if(!o) return;
	if(l == r) {
		return;
	}
	int mid = l + r >> 1;
	print(ls[o], l, mid);
	print(rs[o], mid+1, r);
}

inline int find1(int o, int l, int r) {
	if(l == r) {
		assert(mx[o] == 1);
		return l;
	}
	int mid = l + r >> 1;
	if(mx[ls[o]] == 1) return find1(ls[o], l, mid);
	if(mx[rs[o]] == 1) return find1(rs[o], mid+1, r);
	return 1e9;
}

inline void ins0(int& o, int l, int r) {
	if(!o) o = newnode();
	if(l == r) {
		assert(sum[o] == 0);
		sum[o] = mx[o] = 1;
		return;
	}
	int mid = l + r >> 1;
	if(sum[rs[o]] != r-mid) ins0(rs[o], mid+1, r);
	else ins0(ls[o], l, mid);
	pushup(o);
}

bool hasins;
inline void ins(int& o, int ql, int qr, int l, int r) {
	if(hasins) return;
	if(sum[o] == r-l+1) return;
	if(!o) o = newnode();
	if(ql <= l && r <= qr) {
		if(sum[o] != r-l+1) {
			hasins = 1;
			ins0(o, l, r);
		}
		return;
	}
	int mid = l + r >> 1;
	if(mid < qr) ins(rs[o], ql, qr, mid+1, r);
	if(ql <= mid) ins(ls[o], ql, qr, l, mid);
	pushup(o);
}

inline void dfs(int u, int fa) {
	if(!ok) return;
	rt[u] = 0;
	for(int v : adj[u]) if(v != fa) {
		dfs(v, u);
		merge(rt[u], rt[v], 1, n);

		assert(mx[rt[u]] <= 2);
		while(mx[rt[u]] == 2) {
			int p = find2(rt[u], 1, n);
			assert(p != -1);
			hasins = 0;
			ins(rt[u], 1, p, 1, n);
			if(!hasins) {
				ok = 0;
				return;
			}
		}
	}
	int mi = find1(rt[u], 1, n);
	f[u] = min(f[u], mi - 1);
	if(f[u] <= 0) {
		ok = 0;
		return;
	}
	if(f[u] <= n) {
		hasins = 0;
		ins(rt[u], 1, f[u], 1, n);
	}
}

bool check(int t) {
	tt = tp = 0;
	rep(i, 1, n) {
		int L = 1, R = n-1;
		int res = -1;
		auto sum = calc(i, t);
		if(sum - calc(i, n-1) >= a[i]) {
			f[i] = n;
			continue;
		}
		while(L <= R) {
			int mid = (L + R) >> 1;
			if(sum - calc(i, mid-1) >= a[i]) res = mid, L = mid + 1;
			else R = mid - 1;
		}
		if(res == -1) return 0;
		f[i] = res;
	}
	if(*min_element(f + 1, f + n + 1) == n) return 1;
	ok = 1;
	dfs(1, 0);
	return ok;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);

	cin >> n;
	rep(i, 1, n) cin >> a[i] >> b[i] >> c[i];
	rep(i, 1, n-1) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int L = n, R = 1e9;
	int res = -1;
	while(L <= R) {
		int mid = (L + R) >> 1;
		if(check(mid)) res = mid, R = mid - 1;
		else L = mid + 1;
	}
	cout << res << "\n";

	return 0;
}