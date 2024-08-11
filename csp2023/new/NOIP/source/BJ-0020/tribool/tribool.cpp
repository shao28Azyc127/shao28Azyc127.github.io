#include <bits/stdc++.h>

inline void file () {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
}

constexpr int N = 1e5 + 5;

int n, m;
int val[N];
bool opp[N], vis[N];
int fa[N], siz[N], out[N];

void solve () {
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		val[i] = i, opp[i] = vis[i] = 0;
		fa[i] = -1, siz[i] = 1, out[i] = 0;
	}
	for (int t = m, i, j; t; -- t) {
		char op;
		std::cin >> op;
		if (op == '+') {
			std::cin >> i >> j;
			val[i] = val[j], opp[i] = opp[j];
		} else if (op == '-') {
			std::cin >> i >> j;
			val[i] = val[j], opp[i] = (opp[j] ^ 1);
		} else {
			std::cin >> i;
			val[i] = (op == 'T' ? -1 : (op == 'F' ? -2 : -3));
			opp[i] = 0;
		}
	}
	
	for (int i = 1; i <= n; ++ i) {
		if (val[i] > 0 && val[i] != i) {
			fa[i] = val[i];
			out[fa[i]] ++ ;
		}
//		std::cerr << i << " " << fa[i] << "\n";
	}
	
	std::queue <int> q;
	for (int i = 1; i <= n; ++ i) {
		if (!out[i]) {
			q.push(i);
		}
	}
	
	int ans = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		if (fa[x] != -1) {
			vis[x] = 1;
			out[fa[x]] -- ;
			siz[fa[x]] += siz[x];
			if (!out[fa[x]]) {
				q.push(fa[x]);
			}
		}
	}
	
	for (int x = 1; x <= n; ++ x) {
		if (vis[x]) {
			continue;
		}
		bool s = 0;
		std::vector <int> v;
		for (int y = x; y != -1 && (!vis[y]); y = fa[y]) {
			v.push_back(y);
			vis[y] = 1;
			s ^= opp[y];
		}
		
		if (v.size() == 1) {
			if (val[x] == -3 || (val[x] == x && opp[x])) {
				ans += siz[x];
			}
		} else if (s) {
			for (auto x : v) {
				ans += siz[x];
			}
		}
	}
	
	std::cout << ans << "\n";
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