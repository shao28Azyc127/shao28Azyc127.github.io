#include <cstdio>
#define int long long
using namespace std;
int n, _count;
bool dp[8005][8005];
char s[8005];
signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld%s", &n, s + 1);
	for (int i = 1; i < n; i ++) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = true;
		}
	}
	for (int len = 3; len <= n; len ++) {
		for (int l = 1; l + len - 1 <= n; l ++) {
			int r = l + len - 1;
			if (s[l] == s[r]) {
				dp[l][r] |= dp[l + 1][r - 1];
			}
			for (int k = l; k < r; k ++) {
				dp[l][r] |= dp[l][k] && dp[k + 1][r];
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			_count += dp[i][j];
		}
	}
	printf("%lld\n", _count);
	return 0;
}
