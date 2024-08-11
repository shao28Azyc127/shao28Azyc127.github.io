#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

#define print(x) putchar(x ? '1' : '0')

using namespace std;
const int N = 2005;

int c, n, m, q, X[N], Y[N], x[N], y[N];
bool dp[N][N];

bool flag;
bool cmp(int i, int j)
{
    return (flag ? (x[i] > y[j]) : (x[i] < y[j]));
}
bool query()
{
    memset(dp, 0, sizeof(dp));
    flag = x[1] > y[1];
    if (!cmp(n, m)) return false;
    dp[1][1] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (cmp(i, j) && (dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j]))
            {
                dp[i][j] = true;
            }
        }
    }
    return dp[n][m];
}

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &X[i]);
        x[i] = X[i];
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &Y[i]);
        y[i] = Y[i];
    }
    print(query());
    while (q--)
    {
        memset(x, -1, sizeof(x));
        memset(y, -1, sizeof(y));
        int kx, ky, p, v;
        scanf("%d%d", &kx, &ky);
        for (int i = 1; i <= kx; i++)
        {
            scanf("%d%d", &p, &v);
            x[p] = v;
        }
        for (int i = 1; i <= ky; i++)
        {
            scanf("%d%d", &p, &v);
            y[p] = v;
        }
        for (int i = 1; i <= n; i++)
        {
            if (x[i] == -1) x[i] = X[i];
        }
        for (int i = 1; i <= m; i++)
        {
            if (y[i] == -1) y[i] = Y[i];
        }
        print(query());
    }
    return 0;
}
