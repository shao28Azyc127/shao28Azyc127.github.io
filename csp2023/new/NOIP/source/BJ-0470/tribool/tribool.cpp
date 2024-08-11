#include <stdio.h>
#include <string.h>
#define N 200005
int a[N];
int nxt[N<<1], to[N<<1], dis[N<<1], hd[N], tot;
void ade(int u, int v, int w) { nxt[++tot] = hd[u], to[tot] = v, dis[tot] = w, hd[u] = tot; }
int vis[N], b[N], cnt;
void dfs1(int u, int fa) {
    for (int i = hd[u], v; i && (v = to[i]); i = nxt[i]) {
        if (v == fa) continue; int w = vis[u] * dis[i];
        if (!vis[v]) vis[v] = w, dfs1(v, u);
        if (vis[v] && vis[v] * w == -1) b[++cnt] = u;
    }
}
void dfs2(int u, int fa) {
    vis[u] = 1; for (int i = hd[u], v; i && (v = to[i]); i = nxt[i])
        if (v != fa && !vis[v]) dfs2(v, u);
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, t; scanf("%d%d", &c, &t);
    while (t--) {
        int n, m; scanf("%d%d", &n, &m); int nn = 2 * n + 4;
        for (int i = 1; i <= n; i++) a[i] = i;
        while (m--) {
            char v; int x; scanf(" %c%d", &v, &x);
            if (v > 'A')
                a[x] = (v == 'T' ? n + 1 : v == 'U' ? n + 2 : v == 'F' ? n + 3 : 0);
            else {
                int y; scanf("%d", &y);
                a[x] = (v == '-' ? nn - a[y] : a[y]);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == n + 2) a[i] = nn - i;
            if (a[i] == n + 1 || a[i] == n + 3) a[i] = i;
            int w = 1; if (nn - a[i] <= n) a[i] = nn - a[i], w = -1;
            ade(i, a[i], w), ade(a[i], i, w);
        }
        for (int i = 1; i <= n; i++) if (!vis[i]) vis[i] = 1, dfs1(i, 0);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= cnt; i++) dfs2(b[i], 0);
        int ans = 0; for (int i = 1; i <= n; i++) ans += vis[i];
        printf("%d\n", ans);
        memset(vis, 0, sizeof(vis)); cnt = tot = 0;
        memset(nxt, 0, sizeof(nxt)); memset(hd, 0, sizeof(hd));
    }
    return 0;
}