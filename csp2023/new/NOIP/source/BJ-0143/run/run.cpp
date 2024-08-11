#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, M = 1e5 + 10;
#define int long long
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int C, T;
int n, m, k, d, maxn;
int f[N][N];
int l[M], r[M], v[M];
set<pair<int, int> > s[N];
set<pair<int, int> >::iterator it;
signed main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    C = read(), T = read();
    while (T--)
    {
        n = read(), m = read(), k = read(), d = read();
        if (C >= 10)
        {
            int ans = 0;
            for (int i = 1; i <= m; i++)
            {
                int x = read(), y = read();
                v[i] = read();
                if (y > k) continue;
                if (v[i] > d * y) ans += v[i] - d * y;
            }
            printf("%lld\n", ans);
            continue;
        }
        memset(f, -0x3f, sizeof(f));
        maxn = 0;
        for (int i = 1; i <= n; i++) s[i].clear();
        for (int i = 1; i <= m; i++)
        {
            int x = read(), y = read();
            v[i] = read();
            r[i] = x; l[i] = y;
            s[r[i]].insert(make_pair(y, v[i]));
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i][0] = maxn;
            int cur = 0;
            it = s[i].begin();
            for (int j = 1; j <= min(i, k); j++)
            {
                f[i][j] = f[i - 1][j - 1] - d;
                while (it != s[i].end() && j >= (*it).first) cur += (*it).second, it++;
                f[i][j] += cur;
                maxn = max(maxn, f[i][j]);
            }
        }
        printf("%lld\n", maxn);
    }
    return 0;
}