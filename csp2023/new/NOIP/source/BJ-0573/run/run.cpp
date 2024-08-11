#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

int n, m, k, d;

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    int c, T;
    scanf("%d%d", &c, &T);

    while (T -- )
    {
        // init();
        scanf("%d%d%d%d", &n, &m, &k, &d);
        LL res = 0;
        for (int i = 1; i <= m; i ++ )
        {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            if (x < y || y > k) continue;
            res += max((LL)0, w - (LL)y * d);
        }
        printf("%lld\n", res);
    }

    return 0;
}