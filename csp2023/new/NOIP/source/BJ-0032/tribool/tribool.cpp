#include <iostream>

typedef long long ll;
typedef double lf;

namespace FastIO
{
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc() (p1 == p2 && ((p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin)), p1 == p2) ? EOF : *p1++)
    template <typename T>
    inline void Read(T &x)
    {
        x = 0; bool sgn = 0; char ch = gc();
        while (ch < '0' || ch > '9') {if (ch == '-') sgn = 1; ch = gc();}
        while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
        if (sgn) x = -x;
    }
}

using FastIO::Read;
using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
int val[MAXN];

inline int Rev(int x)
{
    if (x == n + 1) return n + 2;
    if (x == n + 2) return n + 1;
    if (x == n + 3) return n + 3;
    return -x;
}

int fa[MAXN << 1], sz[MAXN << 1];
inline int Find(int k) {return k == fa[k] ? k : fa[k] = Find(fa[k]);}
inline void Union(int u, int v)
{
    u = Find(u), v = Find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) fa[u] = v, sz[v] += sz[u];
    else fa[v] = u, sz[u] += sz[v];
}
bool avl[MAXN << 1];

inline void Solve()
{
    cin >> n >> m;
    // T -> n + 1, F -> n + 2, U -> n + 3
    for (int i = 1; i <= n; i++) val[i] = i;
    char op[5]; int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> op;
        if (op[0] == 'T') cin >> x, val[x] = n + 1;
        else if (op[0] == 'F') cin >> x, val[x] = n + 2;
        else if (op[0] == 'U') cin >> x, val[x] = n + 3;
        else if (op[0] == '+') cin >> x >> y, val[x] = val[y];
        else cin >> x >> y, val[x] = Rev(val[y]);
    }
    for (int i = 1; i <= 2 * n; i++) fa[i] = i, sz[i] = (i <= n), avl[i] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (val[i] == n + 1 || val[i] == n + 2 || val[i] == n + 3) continue;
        Union(i, (val[i] > 0 ? val[i] : -val[i] + n));
        Union(i + n, (val[i] > 0 ? val[i] + n : -val[i]));
    }
    for (int i = 1; i <= n; i++)
        if (val[i] == n + 3) Union(i, i + n), avl[Find(i)] = 0;
    for (int i = 1; i <= n; i++)
        if (Find(i) == Find(i + n)) avl[Find(i)] = 0;
    for (int i = 1; i <= 2 * n; i++)
        if (fa[i] == i && !avl[i]) ans += sz[i];
    cout << ans << "\n";
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int CASE, T;
    cin >> CASE >> T;
    while (T--) Solve();
    return 0;
}