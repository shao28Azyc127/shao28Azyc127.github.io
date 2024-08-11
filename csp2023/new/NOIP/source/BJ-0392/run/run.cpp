#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int C, T, n, m, k, x, y;
map <int, map <int, long long> > v;
long long d, xll, ans, add, f[1005][1005];

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    scanf("%d%d", &C, &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d%d%d%lld", &n, &m, &k, &d);
        ans = 0;
        v.clear();
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%lld", &x, &y, &xll);
            v[x][y] += xll;
        }
        f[0][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            f[i][0] = max(0ll, ans);
            add = 0;
            for(int j = 1; j <= min(i, k); j++)
            {
                add += v[i][j];
                f[i][j] = f[i - 1][j - 1] - d + add;
                ans = max(ans, f[i][j]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
