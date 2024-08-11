#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int c, n, m, q, kx, ky, x, y, a[2005], b[2005], na[2005], nb[2005], temp;
bool dp1[2005][2005], dp2[2005][2005];
void solve(int a[], int b[]) {
	dp1[0][0] = dp2[0][0] = true;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (a[i] < b[j]) {
				dp1[i][j] = dp1[i - 1][j] || dp1[i][j - 1] || dp1[i - 1][j - 1];
				dp2[i][j] = false;
			} else if (a[i] > b[j]) {
				dp1[i][j] = false;
				dp2[i][j] = dp2[i - 1][j] || dp2[i][j - 1] || dp2[i - 1][j - 1];
			} else {
				dp1[i][j] = dp2[i][j] = false;
			}
		}
	}
}
signed main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%lld%lld%lld%lld", &c, &n, &m, &q);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", a + i);
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%lld", b + i);
	}
	solve(a, b);
	putchar((dp1[n][m] || dp2[n][m]) + '0');
	while (q --) {
		scanf("%lld%lld", &kx, &ky);
		memcpy(na, a, sizeof(a));
		memcpy(nb, b, sizeof(b));
		for (int i = 1; i <= kx; i ++) {
			scanf("%lld%lld", &x, &y);
			na[x] = y;
		}
		for (int i = 1; i <= ky; i ++) {
			scanf("%lld%lld", &x, &y);
			nb[x] = y;
		}
		solve(na, nb);
		putchar((dp1[n][m] || dp2[n][m]) + '0');
	}
	putchar('\n');
	return 0;
}
