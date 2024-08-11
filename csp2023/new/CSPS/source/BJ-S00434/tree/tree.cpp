#include <cstdio>
#include <cstdint>
#include <utility>
#include <tuple>
#include <vector>
#include <algorithm>
#include <queue>

#define wzc(f) freopen(f".in", "r", stdin); freopen(f".out", "w", stdout)

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128;
using u128 = unsigned i128;

const size_t N = 1e5 + 5;

constexpr inline int log2(int x) { return 31 - __builtin_clz(x); }

int n;
std::vector<int> g[N];

i64 a[N], b[N], c[N], point[N], e[N];
int dep[N], fa[N][32];
bool vis[N];

int earliest(int i, int end)
{
    i64 to = a[i];
    if (c[i] < 0 && end >= point[i])
    {
        if (end - to + 1 >= point[i])
            return end - to + 1;
        to -= (end - point[i] + 1);
        end = point[i] - 1;
    }

    int l = -1, r = end;
    while (r - l > 1)
    {
        int m = (l + r) >> 1;
        if (b[i] * (end - m + 1) + c[i] * (end - m) * (end + m + 1) / 2 >= to)
            l = m;
        else
            r = m;
    }
    return r;
}

void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= log2(dep[u]); i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];

    for (auto v : g[u])
        if (v != f)
            dfs(v, u);
}

int lca(int u, int v)
{
    if (dep[u] < dep[v]) std::swap(u, v);
    while (dep[u] > dep[v])
    {
        int i = log2(dep[u] - dep[v]);
        u = fa[u][i];
    }
    if (u == v) return u;
    for (int i = 0; i <= log2(dep[u]); i++)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

bool check(int m)
{
    std::vector<std::pair<int, int>> vec;
    vec.reserve(n);
    for (int i = 1; i <= n; i++)
    {
        e[i] = earliest(i, m);
        if (e[i] <= 0) return false;
        vec.emplace_back(e[i], i);
    }
    std::sort(vec.begin(), vec.end());
    int u = 1, now = 0;
    for (auto [before, v] : vec)
    {
        if (vis[v]) continue;
        int l = lca(u, v);
        int d = dep[u] + dep[v] - dep[l];
        now += d;
        if (now > m) return false;
        while (u != l) vis[u] = true, u = fa[u][0];
        while (v != l) vis[v] = true, v = fa[v][0];
        vis[l] = true;
    }
    return true;
}

int main()
{
    wzc("tree");
    scanf("%d", &n);
    bool isa = true;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
        if (c[i] < 0) point[i] = -((1 - b[i]) / -c[i]);
        isa &= (c[i] == 0);
    }

    if (isa)
    {
        std::priority_queue<std::pair<int, int>> pq;
        pq.emplace((a[1] - 1) / b[1] + 1, 1);
        int ans = 0, day = 0;
        while (!pq.empty())
        {
            day++;
            auto [days, i] = pq.top(); pq.pop();
            ans = std::max(ans, day + days - 1);
            vis[i] = true;
            for (auto j : g[i])
                if (!vis[j])
                    pq.emplace((a[j] - 1) / b[j] + 1, j);
        }
        printf("%d\n", ans);
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v); g[v].push_back(u);
    }

    int l = 0, r = 1e9;
    while (r - l > 1)
    {
        int m = (l + r) >> 1;
        if (check(m)) r = m;
        else l = m;
    }
    printf("%d\n", r);
}