#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
int c, n, m, q;
int read()
{
    int x = 0, flag = 1;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') flag = 0;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return flag ? x : -x;
}
namespace Solve1
{
    const int MAXN = 2005;
    int f1[MAXN][MAXN], g1[MAXN][15], f2[MAXN][MAXN], g2[MAXN][15], qp[15], lg[MAXN];
    int F[MAXN], F0[MAXN], G[MAXN], G0[MAXN];
    int query1(int l, int r)
    {
        int k = lg[r - l + 1];
        return max(g1[l][k], g1[r - qp[k] + 1][k]);
    }
    int query2(int l, int r)
    {
        int k = lg[r - l + 1];
        return min(g2[l][k], g2[r - qp[k] + 1][k]);
    }
    void solve()
    {
        /*for(int j = 1; j <= n; ++j) printf("%d ", F[j]);
        puts("");
        for(int j = 1; j <= m; ++j) printf("%d ", G[j]);
        puts("");*/
        memset(f1, 0, sizeof(f1));
        memset(f2, 0, sizeof(f2));
        lg[1] = 0;
        for(int i = 2; i <= m; ++i) lg[i] = lg[i >> 1] + 1;
        for(int i = 1; i <= m; ++i)
            g1[i][0] = g2[i][0] = G[i];
        for(int k = 1; k <= 14; ++k)
        {
            for(int i = 1; i + qp[k] - 1 <= m; ++i)
            {
                g1[i][k] = max(g1[i][k - 1], g1[i + qp[k - 1]][k - 1]);
                g2[i][k] = min(g2[i][k - 1], g2[i + qp[k - 1]][k - 1]);
            }
        }
        //printf("111\n");
        for(int i = 1; i <= n; ++i)
        {
            int tmp = 0;
            for(int j = 1; j <= (i == 1 ? 1 : m); ++j)
            {
                tmp = max(tmp, f1[i - 1][j]);
                //printf("tmp=%d\n", tmp);
                if(tmp >= (i > 1 ? max(j - 1, 1) : 0))
                {
                    if(F[i] <= G[j]) continue;
                    int l = j, r = m, res = j;
                    while(l <= r)
                    {
                        int mid = (l + r) >> 1;
                        if(query1(j, mid) < F[i])
                        {
                            res = mid;
                            l = mid + 1;
                        }
                        else r = mid - 1;
                    }
                    f1[i][j] = res;
                    //printf("can\n");
                }
                //printf("f1 %d %d = %d\n", i, j, f1[i][j]);
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            int tmp = 0;
            for(int j = 1; j <= (i == 1 ? 1 : m); ++j)
            {
                tmp = max(tmp, f2[i - 1][j]);
                if(tmp >= (i > 1 ? max(j - 1, 1) : 0))
                {
                    if(F[i] >= G[j]) continue;
                    int l = j, r = m, res = j;
                    while(l <= r)
                    {
                        int mid = (l + r) >> 1;
                        if(query2(j, mid) > F[i])
                        {
                            res = mid;
                            l = mid + 1;
                        }
                        else r = mid - 1;
                    }
                    f2[i][j] = res;
                }
                //printf("f2 %d %d = %d\n", i, j, f2[i][j]);
            }
        }
        bool flag = 0;
        for(int i = 1; i <= m; ++i)
        {
            if(f1[n][i] == m || f2[n][i] == m)
            {
                flag = 1;
                break;
            }
        }
        if(flag) putchar('1');
        else putchar('0');
    }
    int main()
    {
        for(int i = 1; i <= n; ++i) F[i] = read();
        for(int i = 1; i <= m; ++i) G[i] = read();
        qp[0] = 1;
        for(int i = 1; i <= 14; ++i) qp[i] = qp[i - 1] << 1;
        //printf("111\n");
        solve();
        for(int i = 1; i <= n; ++i) F0[i] = F[i];
        for(int i = 1; i <= m; ++i) G0[i] = G[i];
        //printf("222\n");
        for(int i = 1; i <= q; ++i)
        {
            int kx = read(), ky = read();
            for(int j = 1; j <= kx; ++j)
            {
                int p = read(), v = read();
                F[p] = v;
            }
            for(int j = 1; j <= ky; ++j)
            {
                int p = read(), v = read();
                G[p] = v;
            }
            solve();
            for(int j = 1; j <= n; ++j) F[j] = F0[j];
            for(int j = 1; j <= m; ++j) G[j] = G0[j];
        }
        puts("");
        return 0;
    }
}
namespace Solve2
{
    const int MAXN = 500005;
    int g[MAXN][25], qp[25], lg[MAXN];
    int F[MAXN], F0[MAXN], G[MAXN], G0[MAXN];
    int query(int l, int r)
    {
        int k = lg[r - l + 1];
        return max(g[l][k], g[r - qp[k] + 1][k]);
    }
    void solve()
    {
        lg[1] = 0;
        for(int i = 2; i <= m; ++i) lg[i] = lg[i >> 1] + 1;
        for(int i = 1; i <= m; ++i)
            g[i][0] = G[i];
        for(int k = 1; k <= 20; ++k)
        {
            for(int i = 1; i + qp[k] - 1 <= m; ++i)
            {
                g[i][k] = max(g[i][k - 1], g[i + qp[k - 1]][k - 1]);
            }
        }
        int j = 1;
        bool flag = 1;
        for(int i = 1; i <= n - 1; ++i)
        {
            if(G[j] <= F[i])
            {
                ++j;
                if(G[j] <= F[i])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)
        {
            if(query(j + 1, m) > F[n]) putchar('1');
            else putchar('0');
        }
        else putchar('0');
    }
    int main()
    {
        for(int i = 1; i <= n; ++i) F[i] = read();
        for(int i = 1; i <= m; ++i) G[i] = read();
        qp[0] = 1;
        for(int i = 1; i <= 20; ++i) qp[i] = qp[i - 1] << 1;
        //printf("111\n");
        solve();
        for(int i = 1; i <= n; ++i) F0[i] = F[i];
        for(int i = 1; i <= m; ++i) G0[i] = G[i];
        //printf("222\n");
        for(int i = 1; i <= q; ++i)
        {
            int kx = read(), ky = read();
            for(int j = 1; j <= kx; ++j)
            {
                int p = read(), v = read();
                F[p] = v;
            }
            for(int j = 1; j <= ky; ++j)
            {
                int p = read(), v = read();
                G[p] = v;
            }
            solve();
            for(int j = 1; j <= n; ++j) F[j] = F0[j];
            for(int j = 1; j <= m; ++j) G[j] = G0[j];
        }
        puts("");
        return 0;
    }
}
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    c = read(), n = read(), m = read(), q = read();
    if(c <= 7)
    {
        Solve1::main();
    }
    else
    {
        Solve2::main();
    }
    return 0;
}
