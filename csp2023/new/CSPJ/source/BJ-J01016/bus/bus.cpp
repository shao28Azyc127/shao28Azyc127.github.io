#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10;
int n, m, k, u, v, w, vis[N][110], f[N][110];
int tot, head[N], to[2 * N], nxt[2 * N], edge[2 * N];
void add(int x, int y, int z) {
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    edge[tot] = z;
}
void dfs(int x, int cnt, int st) {
    if (!vis[x][cnt % k]) f[x][cnt % k] = st + cnt;
    else {
        if (st + cnt >= f[x][cnt % k]) return;
        f[x][cnt % k] = st + cnt;
    }
    vis[x][cnt % k] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        dfs(to[i], cnt + 1, max(st, edge[i] - cnt));
    }
}
signed main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &u, &v, &w);
        add(u, v, w);
    }
    dfs(1, 0, 0);
    if (!vis[n][0]) {
        printf("-1");
        return 0;
    }
    printf("%lld", (f[n][0] + k - 1) / k * k);
    return 0;
}