#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e3 + 5;
int x[maxn], y[maxn], cpyx[maxn], cpyy[maxn];
bool f[maxn][maxn];int c, n, m, d; 
bool check() {
	memset(f, false, sizeof f);
	bool flag = false;
	if (x[1] < y[1]) {
		flag = true;
		for (int i = 1; i <= n; ++i) x[i] = -x[i];
		for (int j = 1; j <= m; ++j) y[j] = -y[j];
	}
	f[0][0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if ((f[i - 1][j - 1] || f[i - 1][j] || f[i][j - 1]) && y[j] < x[i]) {
				f[i][j] = true;
			}
		}
	}
	return f[n][m];
}
signed main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> d;
	for (int i = 1; i <= n; ++i) cin >> cpyx[i];
	for (int j = 1; j <= m; ++j) cin >> cpyy[j];

	for (int i = 1; i <= n; ++i) x[i]=cpyx[i];
	for (int j = 1; j <= m; ++j) y[j] = cpyy[j];
	cout << check();
	while (d--) {

	for (int i = 1; i <= n; ++i) x[i]=cpyx[i];
	for (int j = 1; j <= m; ++j) y[j] = cpyy[j];
		int kx, ky; cin >> kx >> ky;
		for (int i = 1; i <= kx; ++i) {
			int p, dx; cin >> p >> dx;
			x[p] = dx;
		}
		for (int i = 1; i <= ky; ++i) {
			int p, dy; cin >> p >> dy;
			y[p] = dy;
		}
		cout << check();
	}
	return 0;
}