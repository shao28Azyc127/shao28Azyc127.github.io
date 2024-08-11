// 50pts
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 9, S3 = 8009;
int n;
char s[N];
bool dp[S3][S3];
LL ans = 0;
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, s + 1);
    if (n <= 800) {
        for (int l = 2; l <= n; l += 2) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1, lst = i;
                for (int k = i + 1; k <= j; k++) {
                    if (s[k] == s[lst] && (dp[lst + 1][k - 1] || lst == k - 1)) {
                        lst = k + 1, k++;
                    }
                }
                if (lst > j) dp[i][j] = 1, ans++;
            }
        }
    } else {
        for (int i = n - 1; i >= 1; i--) {
            int lst = i;
            for (int j = i + 1; j <= n; j++) {
                if (s[j] == s[lst] && (lst + 1 == j || dp[lst + 1][j - 1])) {
                    lst = j + 1, dp[i][j] = 1, ans++, j++;
                }
            }
        }
    }
    printf("%lld\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
