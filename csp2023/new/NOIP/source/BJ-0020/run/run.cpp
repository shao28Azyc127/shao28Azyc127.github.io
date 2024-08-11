#include <bits/stdc++.h>

inline void file () {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
}

using i64 = long long;

constexpr int M = 1e5 + 5;
constexpr i64 inf64 = 0x3f3f3f3f3f3f3f3f;

int n, m, k, d;
std::array <int, 3> rng[M];
int s[2 * M], t;
i64 f[2 * M], g[2 * M];

struct Sgt {
	i64 mx[M << 3], tg[M << 3];
	inline void pushup (int x) {
		mx[x] = std::max(mx[x << 1], mx[x << 1 | 1]);
	}
	inline void modify (int x, i64 v) {
		mx[x] += v, tg[x] += v;
	}
	inline void pushdown (int x) {
		if (tg[x]) {
			modify(x << 1, tg[x]);
			modify(x << 1 | 1, tg[x]);
			tg[x] = 0LL;
		}
	}
	
	void build (int x, int l, int r) {
		mx[x] = tg[x] = 0LL;
		if (l == r) {
			return;
		}
		int mid = l + r >> 1;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
	}
	
	void update (int x, int ul, int ur, int l, int r, i64 v) {
		if (l >= ul && r <= ur) {
			modify(x, v);
			return;
		}
		pushdown(x); int mid = l + r >> 1;
		if (ul <= mid) {
			update(x << 1, ul, ur, l, mid, v);
		}
		if (ur > mid) {
			update(x << 1 | 1, ul, ur, mid + 1, r, v);
		}
		pushup(x);
	}
	
	i64 query (int x, int ql, int qr, int l, int r) {
		if (l >= ql && r <= qr) {
			return mx[x];
		}
		pushdown(x); int mid = l + r >> 1;
		if (qr <= mid) {
			return query(x << 1, ql, qr, l, mid);
		} else if (ql > mid) {
			return query(x << 1 | 1, ql, qr, mid + 1, r);
		} else {
			return std::max(query(x << 1, ql, qr, l, mid), query(x << 1 | 1, ql, qr, mid + 1, r));
		}
	}
} sgt;

void solve () {
	std::cin >> n >> m >> k >> d;
	s[0] = 0, s[t = 1] = n;
	for (int i = 1, x, y, v; i <= m; ++ i) {
		std::cin >> x >> y >> v;
		rng[i] = {x - y, x, v};
		s[++ t] = x - y, s[++ t] = x;
	}
	
	std::sort(s, s + t + 1);
	t = std::unique(s, s + t + 1) - s - 1;
//	for (int i = 0; i <= t; ++ i) {
//		std::cerr << s[i] << " \n"[i == t];
//	}
//	std::cerr << "t = " << t << " " << s[t] << " " << s[t + 1] << "\n";
	sgt.build(1, 1, t);
	
	f[0] = g[0] = 0LL;
	std::sort(rng + 1, rng + m + 1, [&](const std::array <int, 3> &lhs, const std::array <int, 3> &rhs) {
		return lhs[1] < rhs[1];
	});
	for (int i = 1, j = 1, lim = 1; i <= t; ++ i) {
		sgt.update(1, 1, i, 1, t, -1LL * d * (s[i] - s[i - 1]));
		if (i >= 2) {
			sgt.update(1, i, i, 1, t, g[i - 2]);
		}
		
		for (; j <= m && rng[j][1] == s[i]; ++ j) {
			auto [l, r, v] = rng[j];
			l = std::lower_bound(s, s + t, l) - s;
			sgt.update(1, 1, l + 1, 1, t, v);
		}
		
		for (; s[i] - s[lim - 1] > k; lim ++ );
		f[i] = (lim > i ? -inf64 : sgt.query(1, lim, i, 1, t));
		g[i] = std::max(g[i - 1], f[i]);
	}
	
	std::cout << g[t] << "\n";
}

int main () {
	
	file();
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	int c, t;
	std::cin >> c >> t;
	while (t -- ) {
		solve();
	}
	
	return 0;
}