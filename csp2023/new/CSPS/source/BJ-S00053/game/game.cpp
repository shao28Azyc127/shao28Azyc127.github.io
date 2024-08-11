#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e6 + 10;
int n, dp[9000][9000];
char a[N];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == a[i - 1]) dp[i][i - 1] = dp[i - 1][i] = 1;
        dp[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n - 3; i++)
        {
            int l = i, r = i + k - 1;
            if (a[l] == a[r]) dp[l][r] = dp[l + 1][r - 1];
            for (int j = l; j < r; j++)
                if (dp[l][j] == 1 && dp[j + 1][r] == 1) dp[l][r] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            if (dp[i][j]) ans++;
    }
    printf("%d", ans);
    return 0;
}
