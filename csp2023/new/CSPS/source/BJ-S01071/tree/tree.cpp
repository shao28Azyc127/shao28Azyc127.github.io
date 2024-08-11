#include <iostream>
#include <algorithm>
#include <queue>

typedef long long ll;
typedef double lf;

namespace FastIO
{
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) ? EOF : *p1++)
    #define isdigit(x) ((x) >= '0' && (x) <= '9')
    template <typename T>
    inline void Read(T &x)
    {
        x = 0; bool f = 0; char ch = gc();
        while (!isdigit(ch)) {if (ch == '-') f = 1; ch = gc();}
        while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
        if (f) x = -x;
    }
}

using FastIO::Read;
using namespace std;

const int MAXN = 1e5 + 10;

int n, fa[MAXN], dfn[MAXN], idx[MAXN], ls[MAXN], rs[MAXN], clk;
ll a[MAXN], b[MAXN], c[MAXN], lmt[MAXN];
ll f[MAXN];

struct Edge
{
    int v, nxt;
}e[MAXN << 1];
int head[MAXN], tot;
inline void AddEdge(int u, int v)
{
    e[++tot] = Edge{v, head[u]}, head[u] = tot;
    e[++tot] = Edge{u, head[v]}, head[v] = tot;
}

void Init(int u)
{
    ls[u] = clk + 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v != fa[u])
            fa[v] = u, dfn[v] = ++clk, idx[clk] = v;
    }
    rs[u] = clk;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v != fa[u]) Init(v);
    }
}

inline bool Calc(int i, ll t, ll x)
{
    if (lmt[i] == -1)
    {
        ll sum = b[i] * (x - t + 1), add = (t + x) * (x - t + 1) / 2ll;
        if (a[i] <= sum) return 1;
        if (c[i] == 0) return 0;
        return ((a[i] - sum + c[i] - 1) / c[i] <= add);
    }
    if (lmt[i] < t) return (x - t + 1 >= a[i]);
    if (lmt[i] >= x)
    {
        ll sum = b[i] * (x - t + 1), add = (t + x) * (x - t + 1) / 2ll;
        if (sum < a[i]) return 0;
        return ((sum - a[i]) / -c[i] >= add);
    }
    ll sum = b[i] * (lmt[i] - t + 1) + x - lmt[i], add = (t + lmt[i]) * (lmt[i] - t + 1) / 2ll;
    if (sum < a[i]) return 0;
    return ((sum - a[i]) / -c[i] >= add);
}

struct Node
{
    int x;
    Node (int _x) : x(_x) {}
    bool operator < (const Node u) const {return f[x] > f[u.x];}
};
priority_queue <Node> q;
inline bool Check(ll x)
{
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = x, mid, res = -1;
        while (l <= r)
        {
            mid = l + r >> 1;
            if (Calc(i, mid, x)) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        if (res == -1) return 0;
        f[i] = res;
    }
    for (int i = n; i >= 1; i--) f[fa[idx[i]]] = min(f[fa[idx[i]]], f[idx[i]] - 1);
    while (!q.empty()) q.pop();
    q.push(Node(1));
    int cur = 0;
    while (!q.empty())
    {
        int u = q.top().x; q.pop();
        cur++;
        if (cur > f[u]) return 0;
        for (int i = ls[u]; i <= rs[u]; i++) q.push(Node(i));
    }
    return 1;
}

// #include <ctime>

int main()
{
    // int start = clock();
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    Read(n);
    for (int i = 1; i <= n; i++)
    {
        Read(a[i]), Read(b[i]), Read(c[i]);
        if (c[i] >= 0) lmt[i] = -1;
        else lmt[i] = (b[i] - 1) / -c[i];
    }
    for (int i = 1, u, v; i < n; i++) Read(u), Read(v), AddEdge(u, v);
    dfn[1] = idx[1] = clk = 1, Init(1);
    int l = n, r = 1e9, mid, ans = 1e9;
    while (l <= r)
    {
        mid = l + r >> 1;
        if (Check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << "\n";
    // cerr << 1.0 * (clock() - start) / CLOCKS_PER_SEC << "\n";
    return 0;
}