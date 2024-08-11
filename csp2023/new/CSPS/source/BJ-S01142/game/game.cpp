#include <bits/stdc++.h>
using namespace std;

int n, a[2001000];
bool dp[2000][2000];
int main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        char ch; scanf(" %c", &ch);
        a[i] = ch - 'a' + 1;
        if(i != 1 && a[i] == a[i - 1]) dp[i - 1][i] = 1;
    }
    for(int l = 4; l <= n; l += 2)
    for(int i = 1, j = l; j <= n; i++, j++) {
        if(a[i] == a[j]) dp[i][j] |= dp[i + 1][j - 1];
        for(int k = i + 1; k <= j; k += 2)
                dp[i][j] |= (dp[i][k] & dp[k + 1][j]);
    } long long ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j += 2)
            ans += dp[i][j];
    printf("%lld", ans);
    return 0;
}
