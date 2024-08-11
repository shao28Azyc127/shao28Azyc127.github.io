#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1000;
long long dp[maxn][maxn];
char s[maxn];
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1; 
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] += dp[i + 1][j - 1]; 
            for (int k = i; k < j; k++) {
                dp[i][j] += dp[i][k] * dp[k + 1][j]; 
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans += dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
