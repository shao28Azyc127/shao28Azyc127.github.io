#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <deque>

using namespace std;
using ll = long long;
const ll N = 1e3 + 5, M = 1e5 + 5;

ll n, m, k, d;
ll L[M], R[M], v[M];

struct node
{
    int l, r, v;
    bool operator<(const node& rhs) const
    {
        if (r != rhs.r) return r < rhs.r;
        if (l != rhs.l) return l < rhs.l;
        return v < rhs.v;
    }
} a[M];

namespace solve1
{
    ll dp[M], best[M];
    deque<int> q;
    void init()
    {
        memset(dp, 0, sizeof(dp));
        q.clear();
    }
    ll solve()
    {
        for (int i = 1; i <= m; i++)
        {
            a[i].l = L[i], a[i].r = R[i], a[i].v = v[i];
        }
        sort(a + 1, a + m + 1);
        for (int i = 1; i <= m; i++)
        {
            if (a[i].r - a[i].l + 1 <= k)
            {
                ll last = i - 1;
                while (last > 0 && a[last].r >= a[i].l - 1) last--;
                dp[i] = best[last] + a[i].v - (a[i].r - a[i].l + 1) * d;

                while (!q.empty() && (a[q.front()].l < a[i].r - k + 1 || a[q.front()].r < a[i].l - 1)) 
                {
                    q.pop_front();
                }
                if (!q.empty())
                {
                    ll tmp = dp[q.front()] + a[i].v;
                    tmp -= (a[i].r - a[q.back()].r) * d;
                    dp[i] = max(dp[i], tmp);
                }

                while (!q.empty() && dp[q.back()] < dp[i] + d * (a[i].r - a[q.back()].r))
                {
                    q.pop_back();
                }
                q.push_back(i);
            }
            best[i] = max(best[i - 1], dp[i]);
        }
        return best[m];
    }
};

struct FT
{
    int a[N];
    void clear()
    {
        memset(a, 0, sizeof(a));
    }
    ll lowbit(ll x) { return x & -x; }
    ll query(ll pos)
    {
        ll ans = 0;
        for (ll i = pos; i >= 1; i -= lowbit(i))
        {
            ans += a[i];
        }
        return ans;
    }
    void update(ll pos, ll v)
    {
        for (ll i = pos; i <= n; i += lowbit(i))
        {
            a[i] += v;
        }
    }
} b[N];

namespace solve2
{
    ll dp[N][N];
    void init()
    {
        for (int i = 1; i <= n; i++) b[i].clear();
        memset(dp, 0, sizeof(dp));
    }
    ll solve()
    {
        for (int i = 1; i <= m; i++)
        {
            if (R[i] - L[i] + 1 > k) continue;
            b[R[i]].update(max(R[i] - k + 1, 1LL), v[i]);
            b[R[i]].update(L[i] + 1, -v[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i && j <= k; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + b[i].query(i - j + 1) - d;
            }
            for (int j = 0; j <= k; j++)
            {
                dp[i][0] = max(dp[i][0], dp[i - 1][j]);
            }
        }
        ll ans = 0;
        for (int i = 0; i <= k; i++)
        {
            ans = max(ans, dp[n][i]);
        }
        return ans;
    }
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int C, T;
    scanf("%d%d", &C, &T);
    while (T--)
    {
        scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
        for (int i = 1; i <= m; i++)
        {
            ll x, y;
            scanf("%lld%lld%lld", &x, &y, &v[i]);
            R[i] = x, L[i] = x - y + 1;
        }
        if (C <= 9)
        {
            solve2::init();
            printf("%lld\n", solve2::solve());
        }
        else
        {
            solve1::init();
            printf("%lld\n", solve1::solve());
        }
    }
    return 0;
}
