/*flower*/
#include <bits/stdc++.h>
int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<std::array<int, 5>> a(n);
	for(int i = 0; i < n; i ++) {
		for(int &x : a[i]) {
			std::cin >> x;
		}
	}
	int ans = 0;
	for(int s = 0; s < 1e5; s ++) {
		std::array<int, 5> cur;
		for(int x = s, i = 0; i < 5; i ++, x /= 10) cur[i] = x % 10;
		int ok = 1;
		for(int i = 0; i < n && ok; i ++) {
			if(cur == a[i]) ok = 0;
			int cnt = 0;
			auto &now = a[i];
			for(int i = 0; i < 5; i ++) {
				cnt += now[i] != cur[i];
			}
			if(cnt == 1) continue;
			if(cnt == 2) {
				for(int i = 0; i < 5; i ++) {
					if(now[i] != cur[i]) {
						if(now[i + 1] == cur[i + 1]) ok =0 ;
						else {
							if((cur[i] - now[i] + 10) % 10 == (cur[i + 1] - now[i + 1]  + 10) % 10) ;
							else ok = 0;
						}
						break;
					}
				}
			} else {
				ok = 0;
			}
		}
		ans += ok;
	}
	std::cout << ans << '\n';
	return 0;
}