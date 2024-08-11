#include <bits/stdc++.h>
using namespace std;
#define int long long
int v[5005][5005];
struct node {
	int l, r, z;
	bool operator <(const node &x) const {
		return r < x.r;
	}
}a[50005];
int dp[5005][5005], f[5005];
signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int C, T;
	cin >> C >> T;
	if (C == 10 || C == 11) {
		while (T--) {
			int n, m, k, d, ans = 0;
			cin >> n >> m >> k >> d;
			for (int i = 1; i <= m; i++) {
				int x, y, z;
				cin >> x >> y >> z;
				a[i] = (node){x - y + 1, x, z};
			}
			sort(a + 1, a + 1 + m);
			for (int i = 1; i <= m; i++) {
				f[i] = 0;
				for (int j = 1; j <= i; j++) {
					if (a[i].r - a[j].l + 1 > k) continue;
					int num = 0, num1 = 0;
					for (int l = 1; l <= i; l++) {
						if (a[l].r <= a[i].r && a[l].l >= a[j].l) num += a[l].z;
						if (a[l].r < a[j].l - 1) num1 = max(num1, f[l]);
					}
					f[i] = max(f[i], num + num1 - (a[i].r - a[j].l + 1) * d);
					ans = max(ans, f[i]);
				}
			}
			cout << ans << '\n';
		}
	}
	else {
		while (T--) {
			int n, m, k, d;
			cin >> n >> m >> k >> d;
			for (int i = 1; i <= m; i++) {
				int x, y, z;
				cin >> x >> y >> z;
				if (y > k) continue;
				v[x][y] += z;
			}
			for (int i = 1; i <= k; i++) dp[0][i] = -1e18;
			for (int i = 1; i <= n; i++) {
				dp[i][0] = dp[i - 1][0];
				for (int j = 1; j <= k; j++) {
					dp[i][j] = dp[i - 1][j - 1] - d;
					dp[i][0] = max(dp[i][0], dp[i - 1][j]);
				}
				int num = 0;
				for (int l = 1; l <= k; l++) {
					num += v[i][l];
					dp[i][l] += num;
					v[i][l] = 0;
				}
			}
			int ans = 0;
			for (int i = 0; i <= k; i++) {
				ans = max(ans, dp[n][i]);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}