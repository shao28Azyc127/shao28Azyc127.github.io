#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int cnt = 0, f = 1;
	char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') {
		f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		cnt = (cnt << 1) + (cnt << 3) + (c ^ 48);
		c = getchar();
	}
	return cnt * f;
}
inline void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x ^ 48);
		return;
	}
	write(x / 10);
	putchar(x % 10 ^ 48);
}
int cnt[10][10][10][10][10];
int a[10][5];
int d[5];
void solve(int x) {
	for (int i = 0; i < 5; i++) {
		d[i] = a[x][i];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j <= 9; j++) {
			d[i] = (d[i] + j) % 10;
			cnt[d[0]][d[1]][d[2]][d[3]][d[4]]++;
			d[i] = a[x][i];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 9; j++) {
			d[i] = (d[i] + j) % 10;
			d[i + 1] = (d[i + 1] + j) % 10;
			cnt[d[0]][d[1]][d[2]][d[3]][d[4]]++;
			d[i] = a[x][i];
			d[i + 1] = a[x][i + 1];
		}
	}
}
signed main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = read();
		}
	}
	// puts("awa");
	for (int i = 1; i <= n; i++) solve(i);
	int ans = 0;
	// puts("awa");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					for (int o = 0; o < 10; o++) {
						if (cnt[i][j][k][l][o] == n) ans++;
					}
				}
			}
		}
	}
	// puts("awa");
	write(ans); putchar('\n');
	return 0;
}