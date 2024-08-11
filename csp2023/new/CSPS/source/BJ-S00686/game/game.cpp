#include <cstdio>
using namespace std;
typedef long long LL;
LL r1 = 0, n;
bool dp[10010][10010];
char s[10010];
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%lld", &n);
    getchar();
    for (int i = 0; i < n; i ++ ) {
        scanf("%c", &s[i]);
    }

    for (int i = 0; i < n - 1; i ++ ) {
        dp[i + 1][i] = true;
    }

    for (int k = 1; k < n; k += 2 ) {
        for (int i = 0; i + k < n; i ++ ) {
            int j = i + k;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i][j] || dp[i + 1][j - 1];
            }

            for (int l = i + 1; l < j - 1 && !dp[i][j]; l += 2 ) {
                dp[i][j] = dp[i][j] || (dp[i][l] && dp[l + 1][j]);
            }

            if (dp[i][j]) r1++;
        }
    }

    printf("%lld\n", r1);
    return 0;
}
