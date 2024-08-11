#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int st[10];
int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			int x;
			scanf("%d", &x);
			st[i] = st[i] * 10 + x;
		}
	}
	int ans = 0;
	for (int i = 0; i < 1e5; i++) {
		bool flag = 1;
		for (int j = 1; j <= n; j++) {
			int dif = -1, c = 0;
			bool f = 1;
			int x = i, y = st[j];
			for (int k = 0; k < 5; k++) {
				int a = x % 10, b = y % 10;
				if (a != b) {
					if (dif == -1) {
						dif = k;
						c = (a - b + 10) % 10;
					} else {
						if (dif != k - 1) {
							f = 0;
							break;
						} else {
							if (c != (a - b + 10) % 10) {
								f = 0;
								break;
							} else {
								dif = -2;
							}
						}
					}
					//cerr << i << ' ' << j << ' ' << k << ' ' << a << ' ' << b << ' ' << dif << ' ' << c << "!\n";
				}
				x /= 10;
				y /= 10;
			}
			if (!f || dif == -1) {
				flag = 0;
				break;
			}
		}
		//if (flag)
			
			//cerr << i << '\n';
		ans += flag;
	}
	printf("%d\n", ans);
	return 0;
}
