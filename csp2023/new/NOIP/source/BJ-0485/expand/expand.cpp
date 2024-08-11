#include <cstdio>
#include <iostream>

using namespace std;

const int NR = 5e5;
int c, n, m, q;
int f[NR], g[NR];

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    scanf("%d%d%d%d", &c, &n, &m, &q);
    if (c == 1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int tempa = a, tempb = b;
        printf("%d", ((a != b) ? 1 : 0));
        for (int i = 1; i <= q; i++)
        {
            int x , y;
            scanf("%d%d", &x, &y);
            for (int j = 1; j <= x; j++)
            {
                int temp;
                scanf("%d%d", &temp, &a);
            }
            for (int j = 1; j <= y; j++)
            {
                int temp;
                scanf("%d%d", &temp, &b);
            }
            printf("%d", ((a != b) ? 1 : 0));
        }
    }
    return 0;
}
