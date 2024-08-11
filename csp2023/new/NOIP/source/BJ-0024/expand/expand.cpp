#include <bits/stdc++.h>
using namespace std;
using vint = vector<int>;

const int N = 5e5 + 10, M = 2e3 + 10;

int c, n, m, q;
int x[N], y[N];

int dp[M][M];
bool check() {
	if (x[1] == y[1]) return 0;
	memset(dp, 0, sizeof dp); dp[1][1] = 1;
	if (x[1] < y[1]) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) if (x[i] < y[j]) {
				dp[i][j] |= dp[i - 1][j] | dp[i][j - 1];
			}
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) if (x[i] > y[j]) {
				dp[i][j] |= dp[i - 1][j] | dp[i][j - 1];
			}
		}
	}
	return dp[n][m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	for (int i = 1; i <= m; ++i) cin >> y[i];
	
	cout << check();
	                
	while (q--) {
		int kx, ky;
		cin >> kx >> ky;
		while (kx--) {
			int p, v;
			cin >> p >> v;
			x[p] = v;
		}
		while (ky--) {
			int p, v;
			cin >> p >> v;
			y[p] = v;
		}
		cout << check();
	}
	
	cout << "\n";
	
	return 0;
}