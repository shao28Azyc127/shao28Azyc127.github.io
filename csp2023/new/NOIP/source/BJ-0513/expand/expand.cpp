#include<bits/stdc++.h>
using namespace std;
int c, n, m, q;
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    if (1)
    {
        int x, y, cnt=1;
        scanf("%d%d", &x, &y);
        printf("%d", x!=y);
        int x1, y1;
        while (q--)
        {
            x1 = x, y1 = y;
            int kx, ky, p, v;
            scanf("%d%d", &kx, &ky);
            while (kx--)
            {
                scanf("%d%d", &p, &v);
                x1 = v;
            }
            while (ky--)
            {
                scanf("%d%d", &p, &v);
                y1 = v;
            }
            printf("%d", x1!=y1);
        }
    }
    else printf("I AK IOI ^_^\n");
    return 0;
}