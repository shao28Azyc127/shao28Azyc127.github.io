#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <tuple>
#include <vector>

#define wzc(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)

using i64 = int64_t;

const size_t M = 1e5 + 8;

inline int rng()
{
    static int seed = 0xdeadbeef;
    seed ^= (seed >> 7);
    seed ^= (seed << 13);
    seed ^= (seed >> 5);
    return seed;
}

struct node
{
    int sz, wt;
    int key, v;
    node *l, *r;

    node() {}
    node(int key, int v) : sz(v), wt(rng()), key(key), v(v), l(nullptr), r(nullptr) {}

    inline void update()
    {
        sz = v + (l ? l -> sz : 0) + (r ? r -> sz : 0);
    }
}
tr[M]; int tcnt;

inline void clear()
{
    tcnt = 0;
}

template <typename... T>
inline node *newnode(T... x)
{
    tr[tcnt] = node(x...);
    return &tr[tcnt++];
}

inline node *merge(node *u, node *v)
{
    if (u == nullptr) return v;
    if (v == nullptr) return u;
    if (u -> wt < v -> wt)
    {
        u -> r = merge(u -> r, v); u -> update();
        return u;
    }
    else
    {
        v -> l = merge(u, v -> l); v -> update();
        return v;
    }
}

inline std::pair<node*, node*> split(node *u, int k)
{
    if (u == nullptr) return {nullptr, nullptr};
    if (u -> key < k)
    {
        auto [v1, v2] = split(u -> r, k);
        u -> r = v1; u -> update();
        return {u, v2};
    }
    else
    {
        auto [v1, v2] = split(u -> l, k);
        u -> l = v2; u -> update();
        return {v1, u};
    }
}

inline int query(node *u, int k) // sum values for key >=k
{
    if (u == nullptr) return 0;
    if (u -> key < k)
        return query(u -> r, k);
    else
        return query(u -> l, k) + u -> v + (u -> r ? u -> r -> sz : 0);
}

int n, m, k; i64 d;
// {left, right, value}
using int3 = std::tuple<int, int, int>;
int3 c[M];
i64 dp[M];

i64 solve()
{
    std::sort(c, c + m, [](int3 x, int3 y) -> bool { return std::get<1>(x) < std::get<1>(y); });
    std::vector<int> l, r;
    for (int i = 0; i < m; i++)
        l.push_back(std::get<0>(c[i])), r.push_back(std::get<1>(c[i]));
    std::sort(l.begin(), l.end()); l.erase(std::unique(l.begin(), l.end()), l.end());
    r.erase(std::unique(r.begin(), r.end()), r.end());

    clear();
    node *rt = nullptr;
    int ci = 0, li = 0; i64 ans = 0;
    for (int i = 0; i < int(r.size()); i++)
    {
        int t = r[i]; dp[i] = ans;
        while (ci < m && std::get<1>(c[ci]) == t)
        {
            auto [u, v] = split(rt, std::get<0>(c[ci]));
            rt = merge(u, merge(newnode(std::get<0>(c[ci]), std::get<2>(c[ci])), v));
            ci++;
        }
        while (l[li] < std::max(t - k + 1, 0))
            li++;
        for (int j = li; j < l.size() && l[j] <= t; j++)
        {
            int t2 = l[j]; // a segment [t2, t]
            int ii = std::lower_bound(r.begin(), r.end(), t2) - r.begin() - 1;
            dp[i] = std::max(dp[i], (ii < 0 ? 0 : dp[ii]) + query(rt, t2) - (t - t2 + 1) * d);
        }
        ans = std::max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    wzc("run");
    int _, q; scanf("%d %d", &_, &q);
    if (_ == 17 || _ == 18)
    {
        while (q--)
        {
            scanf("%d %d %d %lld", &n, &m, &k, &d);
            for (int i = 0; i < m; i++)
            {
                int x, y, v; scanf("%d %d %d", &x, &y, &v);
                c[i] = {x - y + 1, x, v};
            }
            i64 ans = 0;
            for (int i = 0; i < m; )
            {
                if (i < m - 1 && std::get<1>(c[i]) + 1 == std::get<0>(c[i + 1]) && std::get<1>(c[i]) - std::get<0>(c[i]) + std::get<1>(c[i + 1]) - std::get<0>(c[i + 1]) > k)
                {
                    ans = std::max({ans, ans + std::get<2>(c[i]) - (std::get<1>(c[i]) - std::get<0>(c[i]) + 1) * d, ans + std::get<2>(c[i + 1]) - (std::get<1>(c[i + 1]) - std::get<0>(c[i + 1]) + 1) * d});
                    i += 2;
                }
                else
                {
                    ans = std::max(ans, ans + std::get<2>(c[i]) - (std::get<1>(c[i]) - std::get<0>(c[i]) + 1) * d);
                    i += 1;
                }
            }
            printf("%lld\n", ans);
        }
    }
    while (q--)
    {
        scanf("%d %d %d %lld", &n, &m, &k, &d);
        for (int i = 0; i < m; i++)
        {
            int x, y, v; scanf("%d %d %d", &x, &y, &v);
            c[i] = {x - y + 1, x, v};
        }
        printf("%lld\n", solve());
    }
    return 0;
}