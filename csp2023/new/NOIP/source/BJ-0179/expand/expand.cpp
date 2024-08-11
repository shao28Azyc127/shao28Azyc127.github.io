#include <cstdio>
#include <cstring>

#define N 500000 + 10
#define M 2000 + 10

int x[N], y[N];
int a[N], b[N];
int f[M][M][2];

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    int c, n, m, q;
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &x[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &y[i]);

    memcpy(a, x, sizeof(x));
    memcpy(b, y, sizeof(y));
    
    f[0][0][0] = f[0][0][1] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i] > b[j])
            {
                f[i][j][0] |= f[i - 1][j][0];
                f[i][j][0] |= f[i][j - 1][0];
                f[i][j][0] |= f[i - 1][j - 1][0];
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i] < b[j])
            {
                f[i][j][1] |= f[i - 1][j][1];
                f[i][j][1] |= f[i][j - 1][1];
                f[i][j][1] |= f[i - 1][j - 1][1];
            }
        }
    
    putchar((f[n][m][0] || f[n][m][1]) + '0');

    while (q--)
    {
        memcpy(a, x, sizeof(x));
        memcpy(b, y, sizeof(y));
        int kx, ky, p, v;
        scanf("%d%d", &kx, &ky);
        while (kx--)
        {
            scanf("%d%d", &p, &v);
            a[p] = v;
        }
        while (ky--)
        {
            scanf("%d%d", &p, &v);
            b[p] = v;
        }

        memset(f, false, sizeof(f));
        f[0][0][0] = f[0][0][1] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (a[i] > b[j])
                {
                    f[i][j][0] |= f[i - 1][j][0];
                    f[i][j][0] |= f[i][j - 1][0];
                    f[i][j][0] |= f[i - 1][j - 1][0];
                }
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (a[i] < b[j])
                {
                    f[i][j][1] |= f[i - 1][j][1];
                    f[i][j][1] |= f[i][j - 1][1];
                    f[i][j][1] |= f[i - 1][j - 1][1];
                }
            }
        
        putchar((f[n][m][0] || f[n][m][1]) + '0');
    }

    putchar('\n');

    fclose(stdin);
    fclose(stdout);

    return 0;
}