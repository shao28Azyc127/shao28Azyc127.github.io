#include <bits/stdc++.h>

inline void file () {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
}

constexpr int N = 5e5 + 5;

int c, n, m, q;
int x[N], y[N];
int a[N], b[N];

int xmn[N], xmx[N], xt;
int ymx[N], ymn[N], yt;

bool check (const std::vector <int> &a, const std::vector <int> &b) {
	assert(a[0] < b[0]);
	const int n = a.size(), m = b.size();
	for (int i = 0; i < n; ++ i) {
		if (a[i] >= b[m - 1]) { return 0; }
	}
	for (int i = 0; i < m; ++ i) {
		if (b[i] <= a[n - 1]) { return 0; }
	}
	
	xmn[0] = 0, xmx[xt = 1] = 0;
	for (int i = 1; i < n; ++ i) {
		xmn[i] = (a[i] <= a[xmn[i - 1]] ? i : xmn[i - 1]);
		if (a[i] > a[xmx[xt - 1]]) {
			xmx[xt ++ ] = i;
		}
	}
	ymx[0] = 0, ymn[yt = 1] = 0;
	for (int i = 1; i < m; ++ i) {
		ymx[i] = (b[i] >= b[ymx[i - 1]] ? i : ymx[i - 1]);
		if (b[i] < b[ymn[yt - 1]]) {
			ymn[yt ++ ] = i;
		}
	}
	
	int p = 0, q = 0, i = 0, j = 0;
	for (; i < xt && a[xmx[i]] < b[q]; ++ i);
	for (; j < yt && b[ymn[j]] > a[p]; ++ j);
	assert(i >= 1), assert(j >= 1);
	while (i < xt && j < yt) {
		if (a[xmn[xmx[i] - 1]] < a[p]) {
			p = xmn[xmx[i] - 1];
			for (; j < yt && b[ymn[j]] > a[p]; ++ j);
		} else if (b[ymx[ymn[j] - 1]] > b[q]) {
			q = ymx[ymn[j] - 1];
			for (; i < xt && a[xmx[i]] < b[q]; ++ i);
		} else {
			break;
		}
	}
	
	return (i == xt || j == yt);
}

void Query () {
	if (a[1] == b[1] || a[n] == b[m] || ((a[1] < b[1]) != (a[n] < b[m]))) {
		std::cout << 0;
		return;
	}
	
	bool flg = 0;
	if (a[1] > b[1]) {
		flg = 1;
		std::swap(n, m);
		std::swap(a, b);
	}
	
	int p = std::min_element(a + 1, a + n + 1) - a;
	int q = std::max_element(b + 1, b + m + 1) - b;
	std::vector <int> v1, v2, v3, v4;
	for (int i = 1; i <= p; ++ i) {
		v1.push_back(a[i]);
	}
	for (int i = n; i >= p; -- i) {
		v3.push_back(a[i]);
	}
	for (int i = 1; i <= q; ++ i) {
		v2.push_back(b[i]);
	}
	for (int i = m; i >= q; -- i) {
		v4.push_back(b[i]);
	}
	
	bool r1 = check(v1, v2);
	bool r2 = check(v3, v4);
	if (flg) {
		std::swap(n, m);
	}
	std::cout << (r1 & r2);
}

int main () {
	
	file();
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	std::cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; ++ i) {
		std::cin >> x[i];
	}
	for (int i = 1; i <= m; ++ i) {
		std::cin >> y[i];
	}
	
	std::memcpy(a + 1, x + 1, n << 2);
	std::memcpy(b + 1, y + 1, m << 2);
	Query();
	
	while (q -- ) {
		std::memcpy(a + 1, x + 1, n << 2);
		std::memcpy(b + 1, y + 1, m << 2);
		int kx, ky, p, v;
		std::cin >> kx >> ky;
		while (kx -- ) {
			std::cin >> p >> v;
			a[p] = v;
		}
		while (ky -- ) {
			std::cin >> p >> v;
			b[p] = v;
		}
		Query();
	}
	std::cout << "\n";
	
	return 0;
}