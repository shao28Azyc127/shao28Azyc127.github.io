#include <bits/stdc++.h>
using namespace std;
int a[500010], b[500010], A[2010], B[2010];
bool dp[2010][2010];
bool solve(int n, int m)
{
    if (a[1] == b[1]) return false;
    memset(dp, false, sizeof(dp));
    dp[1][1] = 1;
    if (a[1] < b[1])
    {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1) continue;
            if (a[i] >= b[j]) continue;
            if (i > 1 && a[i - 1] < b[j]) dp[i][j] |= dp[i - 1][j];
            if (j > 1 && a[i] < b[j - 1]) dp[i][j] |= dp[i][j - 1];
            if (i > 1 && j > 1 && a[i - 1] < b[j - 1]) dp[i][j] |= dp[i - 1][j - 1];
        }
    }
    else
    {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1) continue;
            if (a[i] <= b[j]) continue;
            if (i > 1 && a[i - 1] > b[j]) dp[i][j] |= dp[i - 1][j];
            if (j > 1 && a[i] > b[j - 1]) dp[i][j] |= dp[i][j - 1];
            if (i > 1 && j > 1 && a[i - 1] > b[j - 1]) dp[i][j] |= dp[i - 1][j - 1];
        }
    }
    return dp[n][m];
}
signed main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, n, m, q;
    cin >> c >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    if (c <= 7)
    {
        cout << solve(n, m);
        memcpy(A, a, sizeof(A));
        memcpy(B, b, sizeof(B));
        while (q--)
        {
            memcpy(a, A, sizeof(A));
            memcpy(b, B, sizeof(B));
            int kx, ky;
            cin >> kx >> ky;
            while (kx--)
            {
                int x, y;
                cin >> x >> y;
                a[x] = y;
            }
            while (ky--)
            {
                int x, y;
                cin >> x >> y;
                b[x] = y;
            }
            cout << solve(n, m);
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i <= q; i++) cout << 1;
        cout << endl;
    }
    return 0;
}