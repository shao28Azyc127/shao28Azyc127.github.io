#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
int c, n, m, q;
int x[N], y[N], tx[N], ty[N];
bool dp[2005][2005];
int mx[2] = {0, 0}, mn[2] = {1000000000, 1000000000};
inline int calc() {
	dp[0][0] = 1;
	if (x[1] < y[1]) {
		if (x[n] >= y[m])
			return 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = (x[i] < y[j] ? (dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1]) : 0);
			}
		}
	} else {
		if (x[n] <= y[m])
			return 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = (x[i] > y[j] ? (dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1]) : 0);
			}
		}
	}
	return dp[n][m];
}
inline int chk() {
	if (x[1] == y[1] || x[n] == y[m] || mx[0] == mx[1] || mn[1] == mn[0])
		return 0;
	if ((x[1] < y[1]) ^ (x[n] < y[m]))
		return 0;
	if ((x[1] < y[1]) ^ (mx[0] < mx[1]))
		return 0;
	if ((x[1] < y[1]) ^ (mn[0] < mn[1]))
		return 0;
	return 1;
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &c, &n, &m, &q);
	mx[0] = mx[1] = 0;
	mn[0] = mn[1] = 1e9;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
		tx[i] = x[i];
		mx[0] = max(mx[0], x[i]);
		mn[0] = min(mn[0], x[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &y[i]);
		ty[i] = y[i];
		mx[1] = max(mx[1], y[i]);
		mn[1] = min(mn[1], y[i]);
	}
	int t = chk();
	if (t && c < 8) {
		printf("%d", calc());
	} else {
		printf("%d", t);
	}
	while (q--) {
		mx[0] = mx[1] = 0;
		mn[0] = mn[1] = 1e9;
		int kx, ky;
		scanf("%d%d", &kx, &ky);
		for (int i = 1; i <= n; i++)
			x[i] = tx[i];
		for (int i = 1; i <= m; i++)
			y[i] = ty[i];
		for (int i = 0; i < kx; i++) {
			int p, v;
			scanf("%d%d", &p, &v);
			x[p] = v;
			// cerr << "x:" << p << ' ' << v << '\n';
		}
		for (int i = 0; i < ky; i++) {
			int p, v;
			scanf("%d%d", &p, &v);
			y[p] = v;
			// cerr << "y:" << p << ' ' << v << '\n';
		}
		for (int i = 1; i <= n; i++)
			mx[0] = max(mx[0], x[i]), 
			mn[0] = min(mn[0], x[i]);
			// cerr << x[i] << ' ';
		// cerr << '\n';
		for (int i = 1; i <= m; i++)
			mx[1] = max(mx[1], y[i]), 
			mn[1] = min(mn[1], y[i]);
			// cerr << y[i] << ' ';
		// cerr << '\n';
		int t = chk();
		if (t && c < 8)
			printf("%d", calc());
		else
			printf("%d", t);
	}
	return 0;
}
