#include <bits/stdc++.h>

inline void file () {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
}

constexpr int N = 3005;

int n, m;
int mn[N], mx[N];

int main () {
	
	file();
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		mx[i] = 0, mn[i] = 25;
		std::string str;
		std::cin >> str;
		for (int j = 0; j < m; ++ j) {
			mx[i] = std::max(mx[i], str[j] - 'a');
			mn[i] = std::min(mn[i], str[j] - 'a');
		}
	}
	
	for (int i = 1; i <= n; ++ i) {
		bool ok = 1;
		for (int j = 1; j <= n; ++ j) {
			ok &= (i == j || mn[i] < mx[j]);
		}
		std::cout << ok;
	}
	std::cout << "\n";
	
	return 0;
}