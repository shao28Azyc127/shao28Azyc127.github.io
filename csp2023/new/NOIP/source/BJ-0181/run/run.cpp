#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long

using namespace std;

const int N = 1e3 + 5;
int c, T, n, m, k, d, x, y, z, s[N][N], f[N][N], ans;

signed main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%lld %lld", &c, &T);
    while(T--)
    {
        scanf("%lld %lld %lld %lld", &n, &m, &k, &d);
        memset(f, 0, sizeof(f));
        memset(s, 0, sizeof(s));
        ans = 0;
        for(int i = 1;i <= m;i++)
        {
            scanf("%lld %lld %lld", &x, &y, &z);
            s[x][y] += z;
        }
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= k;j++)
                s[i][j] += s[i][j-1];
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j <= k;j++)
                f[i][0] = max(f[i][0], f[i-1][j]);
            for(int j = 1;j <= k;j++)
                f[i][j] = f[i-1][j-1] - d + s[i][j];
        }
        for(int i = 0;i <= k;i++)
            ans = max(ans, f[n][i]);
        printf("%lld\n", ans);
    }
    return 0;
}

