#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;
int n, ans, res;
int a[N][6], now[N];

bool chk(int x, int y, int c, int d) {
	/*
	int ch1 = (x - y + 10) % 10, ch2 = (c - d + 10) % 10;
	int ch3 = 10 - (x - y), ch4 = 10 - (c - d);
	*/
	int ch1 = x - c, ch2 = y - d;
	if (ch1 < 0) ch1 += 10;
	if (ch2 < 0) ch2 += 10;
	if (ch1 == ch2)  return false;
	return true;
}

bool check() {
	for (int j = 1; j <= n; j ++ ) {
		bool flag = false;
		for (int i = 1; i <= 4; i ++ ) {
			if (a[j][i + 1] == now[i + 1] || chk(a[j][i], now[i], a[j][i + 1], now[i + 1]) || a[j][i] == now[i]) continue;
			bool st = true;
			for (int k = 1; k <= 5; k ++ ) {
				if (k == i + 1 || k == i) continue;
				if (a[j][k] != now[k]) {
					st = false;
					break;
				}
			}
			if (st) {
				flag = true;
				break;
			}
		}
		for (int i = 1; i <= 5; i ++ ) {
			if (a[j][i] - now[i] == 0) continue;
			bool st = true;
			for (int k = 1; k <= 5; k ++ ) {
				if (k == i) continue;
				if (a[j][k] != now[k]) {
					st = false;
					break;
				}
			}
			if (st) {
				flag = true;
				break;
			}
		}
		if (!flag) return false;
	}
	return true;
}

void dfs(int u) {
	if (u == 6) {
		if (check()) {
			ans ++;	
		}
		return;
	}
	for (int i = 0; i < 10; i ++ ) {
		now[u] = i;
		dfs(u + 1);
	}
}

int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= 5; j ++ ) cin >> a[i][j];
	dfs(1);
	cout << ans << endl;
	return 0;
}
