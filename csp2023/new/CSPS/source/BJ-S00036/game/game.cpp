#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 8000 + 5;
LL b[N], tot, dp[N][N];
int n;
string s;
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    cin >> s;
    s = '.' + s;
    for(int i = 1; i <= n; i++) dp[i][i] = 0;
    for(int i = 2; i <= n; i++) {
        if (s[i] == s[i-1]) dp[i-1][i] = 1;
    }
    for(int len = 4; len <= n; len+=2) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = 0;
            if (len % 2 == 0 && s[l] == s[r]) dp[l][r] = dp[l+1][r-1];
            if (dp[l][r]) continue;
            for(int k = l; k < r; k++) {
                if (dp[l][k] && dp[k+1][r]) {
                    dp[l][r] = 1;
                    break;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            tot += dp[i][j];
        }
    }
    printf("%lld\n", tot);
    return 0;
}
