#include <bits/stdc++.h>

inline void file () {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
}

constexpr int pw[] = {1, 10, 100, 1000, 10000, 100000};
constexpr int N = 10;

int n;
int a[N];
int vis[N];
int b[5], c[5];

inline int calc () {
	return c[0] * pw[0] + c[1] * pw[1] + c[2] * pw[2] + c[3] * pw[3] + c[4] * pw[4];
}

int main () {
	
	file();
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	std::cin >> n;
	for (int i = 1, x; i <= n; ++ i) {
		for (int j = 4; j >= 0; -- j) {
			std::cin >> x;
			a[i] += pw[j] * x;
		}
	}
	
	int ans = 0;
	for (int x = 0; x < pw[5]; ++ x) {
		bool ok = 1;
		for (int i = 1; i <= n; ++ i) {
			ok &= (a[i] != x);
		}
		if (!ok) {
			continue;
		}
		
		std::memset(vis, 0, sizeof vis);
		for (int j = 0, y = x; j < 5; ++ j) {
			b[j] = y % 10;
			y /= 10;
		}
		
		for (int j = 0, y; j < 5; ++ j) {
			std::memcpy(c, b, sizeof b);
			for (int k = 0; k < 9; ++ k) {
				(c[j] += 1) %= 10;
				y = calc();
				for (int i = 1; i <= n; ++ i) {
					vis[i] |= (a[i] == y);
				}
			}
		}
		
		for (int j = 0, y; j < 4; ++ j) {
			std::memcpy(c, b, sizeof b);
			for (int k = 0; k < 9; ++ k) {
				(c[j] += 1) %= 10;
				(c[j + 1] += 1) %= 10;
				y = calc();
				for (int i = 1; i <= n; ++ i) {
					vis[i] |= (a[i] == y);
				}
			}
		}
		
		for (int i = 1; i <= n; ++ i) {
			ok &= (vis[i]);
		}
		if (ok) {
			ans ++ ;
		}
	}
	
	std::cout << ans << "\n";
	
	return 0;
}