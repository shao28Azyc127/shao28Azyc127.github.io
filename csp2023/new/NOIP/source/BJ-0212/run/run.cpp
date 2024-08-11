#include<bits/stdc++.h>
#define N 100010
#define INF ((ll)1 << 54)
#define ll long long
using namespace std;

int n, m, k, d, c, T, x[N], y[N], v[N];
struct seg
{
    int l, r, v;
}a[N];

bool operator < (seg a, seg b)
{
    return a.r < b. r;
}

ll f[1010][1010];

void solve1()
{
    ll ans = 0;
    for(int i = 1; i <= m; ++i)
        if(y[i] <= k && (ll)d * (ll)y[i] < v[i]) ans = ans + (ll)v[i] - (ll)d * (ll)y[i];
    printf("%lld\n", ans);
}

void solve2()
{
    //clear!
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            f[i][j] = -INF;
    for(int i = 1; i <= m; ++i)
        a[i].l = x[i] - y[i] + 1, a[i].r = x[i], a[i].v = v[i];
    sort(a + 1, a + m + 1);
    int p = 0;
    f[0][0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        while(i > a[p + 1].r) ++p;
        for(int j = 0; j < i && j <= k; ++j) f[i][0] = max(f[i][0], f[i - 1][j]);
        for(int j = 1; j <= i && j <= k; ++j)
        {
            f[i][j] = f[i - 1][j - 1] - d;
            int t = p + 1;
            while(a[t].r == i)
            {
                if(a[t].r - a[t].l + 1 <= j) f[i][j] += a[t].v;
                ++t;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= k; ++i) ans = max(ans, f[n][i]);
    printf("%lld\n", ans);
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while(T--)
    {
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for(int i = 1; i <= m; ++i) scanf("%d%d%d", &x[i], &y[i], &v[i]);
        if(c == 17 || c == 18) solve1();
        else solve2();
    }
    return 0;
}