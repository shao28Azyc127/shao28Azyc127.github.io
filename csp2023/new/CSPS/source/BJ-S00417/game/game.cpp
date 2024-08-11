#include <bits/stdc++.h>

inline void file () {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
}

using i64 = long long;

constexpr int N = 2e6 + 5;

int n;
char str[N];
int f[N], dep[N];
int g[N][26];
i64 ans = 0LL;

int main () {
	
	file();
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	std::cin >> n >> (str + 1);
//	std::cerr << "n = " << n << "\n";
	
	for (int i = 2; i <= n; ++ i) {
		f[i] = (str[i] == str[i - 1] ? i - 1 : g[i - 1][str[i] - 'a'] - 1);
		if (f[i] != -1) {
			ans += (dep[i] = dep[f[i] - 1] + 1);
			std::memcpy(g[i], g[f[i] - 1], sizeof g[i]);
			g[i][str[f[i] - 1] - 'a'] = f[i];
		}
	}
	std::cout << ans << "\n";
	
	return 0;
}