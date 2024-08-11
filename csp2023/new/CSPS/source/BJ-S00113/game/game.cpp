#include <cstdio>
#include <iostream>
using namespace std;

const int N = 8005;

int n, dp[N][N], ans;
char s[N];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    cin >> s + 1;
    for (int i = 1; i < n; i++)
        if (s[i] == s[i + 1])
            dp[i][i + 1] = 1, ans++;
    for (int len = 4; len <= n; len += 2)
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j]) dp[i][j] |= dp[i + 1][j - 1];
            for (int k = i + 2; k <= j - 1; k++) dp[i][j] |= dp[i][k - 1] & dp[k][j];
            if (dp[i][j]) ans++;
        }
    printf("%d", ans);
    return 0;
}