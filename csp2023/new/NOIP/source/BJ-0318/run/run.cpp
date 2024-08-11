#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
int c, t, n, m;
LL k, d;
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
    const int MAXN = 1005, MAXM = 100005;
    struct challenge
    {
        int x, y;
        LL v;
    }cha[MAXM];
    LL dp[MAXN][MAXN];
    bool cmp(challenge x, challenge y)
    {
        return x.x < y.x;
    }
    int main()
    {
        while(t--)
        {
            n = read(), m = read(), k = read(), d = read();
            for(int i = 1; i <= m; ++i)
            {
                int x = read(), y = read(), v = read();
                cha[i] = {x, y, v};
            }
            sort(cha + 1, cha + m + 1, cmp);
            for(int i = 0; i <= n; ++i)
                for(int j = 0; j <= min(1ll * i, k); ++j) dp[i][j] = -9e18;
            dp[0][0] = 0;
            int tmp = 1;
            for(int i = 1; i <= n; ++i)
            {
                for(int j = 0; j <= min(1ll * i - 1ll, k); ++j) dp[i][0] = max(dp[i][0], dp[i - 1][j]);
                for(int j = 1; j <= min(1ll * i, k); ++j)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - d);
                while(cha[tmp].x == i)
                {
                    for(int j = cha[tmp].y; j <= min(1ll * i, k); ++j)
                        dp[i][j] += cha[tmp].v;
                    ++tmp;
                }
            }
            LL ans = -9e18;
            for(int i = 0; i <= min(1ll * n, k); ++i) ans = max(ans, dp[n][i]);
            printf("%lld\n", ans);
        }
        return 0;
    }
}
namespace Solve2
{
    const int MAXK = 105, MAXM = 100005;
    struct challenge
    {
        LL x, y, v;
    }cha[MAXM];
    LL dp[MAXM][MAXK], maxx[MAXM];
    bool cmp(challenge x, challenge y)
    {
        return x.x < y.x;
    }
    int main()
    {
        while(t--)
        {
            n = read(), m = read(), k = read(), d = read();
            for(int i = 1; i <= m; ++i)
            {
                int x = read(), y = read(), v = read();
                cha[i] = {x, y, v};
            }
            sort(cha + 1, cha + m + 1, cmp);
            for(int i = 0; i <= m; ++i)
            {
                for(int j = 0; j <= k; ++j) dp[i][j] = -9e18;
                maxx[i] = -9e18;
            }
            dp[0][0] = 0;
            maxx[0] = 0;
            int last = 0;
            for(int i = 1; i <= m; ++i)
            {
                dp[i][0] = maxx[last];
                maxx[i] = dp[i][0];
                for(int j = 1; j <= min(k, cha[i].x); ++j)
                {
                    if(j - (cha[i].x - cha[i - 1].x) >= 0) dp[i][j] = dp[i - 1][j - (cha[i].x - cha[i - 1].x)] - d * (cha[i].x - cha[i - 1].x);
                    else dp[i][j] = maxx[i - 1] - d * 1ll * j;
                    if(j >= cha[i].y) dp[i][j] += cha[i].v;
                    //printf("dp%d %d = %d\n", i, j, dp[i][j]);
                    maxx[i] = max(maxx[i], dp[i][j]);
                }
                if(cha[i + 1].x != cha[i].x) last = i;
            }
            printf("%lld\n", maxx[m]);
        }
        return 0;
    }
}
namespace Solve3
{
    const int MAXM = 100005;
    struct challenge
    {
        LL x, y, v;
    }cha[MAXM];
    LL ans = 0;
    bool cmp(challenge x, challenge y)
    {
        return x.x < y.x;
    }
    int main()
    {
        while(t--)
        {
            n = read(), m = read(), k = read(), d = read();
            for(int i = 1; i <= m; ++i)
            {
                int x = read(), y = read(), v = read();
                cha[i] = {x, y, v};
            }
            sort(cha + 1, cha + m + 1, cmp);
            ans = 0;
            for(int i = 1; i <= m; ++i)
            {
                if(cha[i].y <= cha[i].x && cha[i].y <= k && cha[i].v > d * cha[i].y) ans += cha[i].v - d * cha[i].y;
            }
            printf("%lld\n", ans);
        }
        return 0;
    }
}
int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    c = read(), t = read();
    if(c <= 9)
    {
        Solve1::main();
    }
    else if(c >= 15 && c <= 16)
    {
        Solve2::main();
    }
    else if(c >= 17 && c <= 18)
    {
        Solve3::main();
    }
    return 0;
}

