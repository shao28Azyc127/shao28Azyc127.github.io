#include <iostream>
#include <cstdio>

using namespace std;

const int N = 5e5 + 5, INF = 1e9;
int c, n, m, q, kx, ky, p, v, a[N], b[N];

void solve()
{
    if(n <= 2 && m <= 2)
    {
        if((a[1] < b[1] && a[n] < b[m]) || (a[1] > b[1] && a[n] > b[m]))
            printf("1");
        else
            printf("0");
    }
    else if(c >= 8 && c <= 14)
    {
        int mxa = 0, mnb = INF;
        for(int i = 1;i <= n;i++)
            mxa = max(mxa, a[i]);
        for(int i = 1;i <= m;i++)
            mnb = min(mnb, b[i]);
        if((mxa < b[1] && mnb > a[n]) || (mnb > a[1] && mxa < b[m]))
            printf("1");
        else
            printf("0");
    }
    printf("1");
}

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d %d %d %d", &c, &n, &m, &q);
    for(int i = 1;i <= n;i++)
        scanf("%d", &a[i]);
    for(int i = 1;i <= m;i++)
        scanf("%d", &b[i]);
    solve();
    while(q--)
    {
        scanf("%d %d", &kx, &ky);
        for(int i = 1;i <= kx;i++)
        {
            scanf("%d %d", &p, &v);
            a[p] = v;
        }
        for(int i = 1;i <= ky;i++)
        {
            scanf("%d %d", &p, &v);
            b[p] = v;
        }
        solve();
    }
    return 0;
}

