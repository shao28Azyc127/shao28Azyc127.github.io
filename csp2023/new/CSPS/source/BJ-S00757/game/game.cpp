#include <iostream>
#include <cstdio>

using namespace std;

int n;
char str[1000006];
long long ans;
bool dp[8001][8001];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    scanf("%s", str + 1);
    str[0] = '#';
    for(int l = n - 1;l >= 1;l--) {
        if(str[l] == str[l + 1]) dp[l][l + 1] = 1;
        for(int r = l + 3;r <= n;r += 2) {
            if(str[l] == str[r] && dp[l + 1][r - 1]) dp[l][r] = 1;
            for(int i = l + 1;i + 2 <= r;i += 2) {
                if(dp[l][i] && dp[i + 1][r]) {
                    dp[l][r] = 1;
                    break;
                }
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            if(dp[i][j]) ans++;
        }
    }
    printf("%lld", ans);
    return 0;
}
