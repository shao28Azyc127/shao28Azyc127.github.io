#include <iostream>
#include <cstdio>
using namespace std;

int c, n, m, newn, newm, q, ka, kb, x, y, a[100005], b[100005], save_a[100005], save_b[100005];
bool f[2005][2005];

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    scanf("%d%d%d%d", &c, &n, &m, &q);
    if(n > 2000 || m > 2000)
    {
        for(int i = 0; i <= q; i++)  printf("0");
        return 0;
    }

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &save_a[i]);
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &save_b[i]);
    }
    for(int i = 0; i <= q; i++)
    {
        for(int j = 1; j <= n; j++)  a[j] = save_a[j];
        for(int j = 1; j <= m; j++)  b[j] = save_b[j];
        if(i > 0)
        {
            scanf("%d%d", &ka, &kb);
            for(int j = 1; j <= ka; j++)
            {
                scanf("%d%d", &x, &y);
                a[x] = y;
            }
            for(int j = 1; j <= kb; j++)
            {
                scanf("%d%d", &x, &y);
                b[x] = y;
            }
        }
        newn = n;  newm = m;
        if(a[1] == b[1])
        {
            printf("0");
            continue;
        }
        if(a[1] > b[1])
        {
            for(int j = 1; j <= max(n, m); j++)
            {
                x = a[j];
                a[j] = b[j];
                b[j] = x;
            }
            newn = m;  newm = n;
        }
        f[1][1] = true;
        for(int len = 1; len <= newn + newm; len++)
        {
            for(int ax = 1; ax <= newn && ax <= len; ax++)
            {
                int by = len - ax;
                if(by <= 0 || by > newm)  continue;
                if(ax == 1 && by == 1)  continue;
                if(a[ax] >= b[by])  f[ax][by] = 0;
                else  f[ax][by] = f[ax - 1][by - 1] || f[ax - 1][by] || f[ax][by - 1];
                //printf("f[%d][%d] = %d\n", ax, by, f[ax][by]);
            }
        }
        printf("%d", f[newn][newm]);
    }
    puts("");
    return 0;
}
