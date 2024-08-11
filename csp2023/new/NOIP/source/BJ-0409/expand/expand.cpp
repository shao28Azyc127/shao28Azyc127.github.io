#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5e5 + 5;

int c, n, m, q, kx, ky, px, vx, a[N], b[N], tmpa[N], tmpb[N];

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    if (c == 1)
    {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
        printf("1");
        for (int i = 1; i <= q; i++)
        {
            scanf("%d%d", &kx, &ky);
            for (int i = 1; i <= kx; i++) scanf("%d%d", &px, &vx);
            for (int i = 1; i <= ky; i++) scanf("%d%d", &px, &vx);
            printf("1");
        }
    }
    else
    {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
        if (a[1] == b[1] || a[n] == b[m]) printf("0");
        else if (a[1] < b[1] && a[n] > b[m]) printf("0");
        else if (a[1] > b[1] && a[n] < b[m]) printf("0");
        else printf("1");
        for (int i = 1; i <= q; i++)
        {
            scanf("%d%d", &kx, &ky);
            memcpy(tmpa, a, sizeof a);
            memcpy(tmpb, b, sizeof b);
            for (int j = 1; j <= kx; j++)
            {
                scanf("%d%d", &px, &vx);
                tmpa[px] = vx;
            }
            for (int j = 1; j <= ky; j++)
            {
                scanf("%d%d", &px, &vx);
                tmpb[px] = vx;
            }
            if (tmpa[1] == tmpb[1] || tmpa[n] == tmpb[m]) printf("0");
            else if (tmpa[1] < tmpb[1] && tmpa[n] > tmpb[m]) printf("0");
            else if (tmpa[1] > tmpb[1] && tmpa[n] < tmpb[m]) printf("0");
            else printf("1");
        }
    }
    return 0;
}