#include <bits/stdc++.h>

inline void file () {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
}

using i64 = long long;
using i128 = __int128_t;

constexpr int N = 1e5 + 5;

int n;
i64 a[N]; int b[N], c[N], p[N], t[N];
i128 pres[N];
std::vector <int> adj[N];

inline i128 S (int x, int k) {
	return (c[x] >= 0 || p[x] > k ? 1LL * b[x] * k + (i128)c[x] * (1LL * k * (k + 1) / 2) : pres[x] + (k - p[x] + 1));
/*
	if (c[x] >= 0 || (c[x] < 0 && p[x] > k)) {
		return 1LL * b[x] * k + (i128)c[x] * (1LL * k * (k + 1) / 2);
	} else {
//		assert(k >= p[x]);
		return pres[x] + (k - p[x] + 1);
	}
*/
}

void dfs (int x, int par) {
	for (auto y : adj[x]) {
		if (y == par) {
			continue;
		}
		dfs(y, x);
		t[x] = std::min(t[x], t[y] - 1);
	}
}

bool check (int mid) {
	for (int i = 1; i <= n; ++ i) {
		int l = 0, r = mid;
		const __int128_t diff = S(i, mid) - a[i];
		while (l < r) {
			int m = l + r + 1 >> 1;
			if (S(i, m - 1) <= diff) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		t[i] = r;
	}
	
	dfs(1, 0);
	std::sort(t + 1, t + n + 1);
	for (int i = 1; i <= n; ++ i) {
		if (t[i] < i) {
			return 0;
		}
	}
	return 1;
}

int main () {
	
	file();
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	std::cin >> n;
	for (int i = 1; i <= n; ++ i) {
		std::cin >> a[i] >> b[i] >> c[i];
		if (c[i] < 0) {
			p[i] = (b[i] - c[i] - 2) / (-c[i]);
			pres[i] = 1LL * b[i] * (p[i] - 1) + (i128)c[i] * (1LL * (p[i] - 1) * p[i] / 2);
		}
	}
	
	int l = n, r = (int)1e9 + 10;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	
	std::cout << r << "\n";
	
	return 0;
}