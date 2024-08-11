#include<bits/stdc++.h>
#define N 500010
using namespace std;

int c, n, m, q, a[N], b[N], x[N], y[N];

void solve1()
{
    if((x[1] < y[1] && x[n] < y[m]) || (x[1] > y[1] && x[n] > y[m])) printf("1");
    else printf("0");
}

int ymax[N], xmin[N];

void solve2()
{
    int ymin = y[m], xmax = x[n];
    for(int i = 1; i <= m; ++i) ymin = min(ymin, y[i]);
    for(int i = 1; i <= n; ++i) xmax = max(xmax, x[i]);
    if(x[n] >= ymin || xmax >= y[m]) printf("0");
    else printf("1");
}

void presolve()
{
    for(int i = 1; i <= n; ++i) x[i] = a[i];
    for(int i = 1; i <= m; ++i) y[i] = b[i];
    if(c == 1) printf("1");
    if(c == 2) solve1();
    if(8 <= c && c <= 14) solve2();
}

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++i) scanf("%d", &b[i]);
    presolve();
    int kx, ky, p, v;
    while(q--)
    {
        scanf("%d%d", &kx, &ky);
        for(int i = 1; i <= n; ++i) x[i] = a[i];
        for(int i = 1; i <= m; ++i) y[i] = b[i];
        for(int i = 1; i <= kx; ++i)
        {
            scanf("%d%d", &p, &v);
            x[p] = v;
        }
        for(int i = 1; i <= ky; ++i)
        {
            scanf("%d%d", &p, &v);
            y[p] = v;
        }
        if(c == 1) printf("1");
        if(c == 2) solve1();
        if(8 <= c && c <= 14) solve2();
    }
    return 0;
}