#include <bits/stdc++.h>
#define int long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair <int, int> pii;
const int N = 1e5 + 10;
inline int read ()
{
    int x = 0, f = 1;
    char c = getchar ();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar (); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar (); }
    return x * f;
}
int n;
int a[N], b[N], c[N];
struct edge {
    int ver, nxt;
} e[N << 1]; int head[N], tot;
void add_edge (int u, int v) { e[++tot] = (edge) {v, head[u]}; head[u] = tot;}
priority_queue <pii> que;
int fa[N];
void dfs (int u, int f)
{
    fa[u] = f;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].ver;
        if (v == f) continue;
        dfs (v, u);
    }
}
signed main ()
{
    freopen ("tree.in", "r", stdin);
    freopen ("tree.out", "w", stdout);
    n = read ();
    for (int i = 1; i <= n; i++) a[i] = read (), b[i] = read (), c[i] = read ();
    for (int i = 1; i < n; i++)
    {
        int u = read (), v = read ();
        add_edge (u, v);
        add_edge (v, u);
    }
    dfs (1, 0);
    que.push (mk(b[1], 1));
    int ans = 0, day = 0;
    while (!que.empty ())
    {
        int u = que.top ().se; que.pop();
        ans = max (ans, day + (a[u] / b[u]));
        day++;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].ver;
            if (v == fa[u]) continue;
            que.push (mk((a[v] / b[v]), v));
        }
    }
    printf ("%lld\n", ans);
    return 0;
}