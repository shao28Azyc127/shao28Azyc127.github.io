#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 8005;
bool ok[N][N];
char s[N];
int dp[N];
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		ok[i][i - 1] = 1;
	ll ans = 0;
	for (int i = n; i; i--) {
		for (int j = i + 1; j <= n; j += 2) {
			if (s[i] == s[j] && ok[i + 1][j - 1])
				ok[i][j] = 1, ++ans;
			else {
				for (int k = i; k < j; k++)
					if (ok[i][k] && ok[k + 1][j]) {
						ok[i][j] = 1, ++ans;
						break;
					}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
