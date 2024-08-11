// 30pts
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __int128_t int128;
const int N = 29;
vector<int> G[N];
int n, vis[N][N];
LL a[N], b[N], c[N], d[N][N], dp[1100009];
bool chk(LL x, LL st, LL id) {
    int128 h = (x - st + 1) * b[id] + (int128)(x + st) * (x - st + 1) / 2 * c[id];
    return h >= a[id];
}
int fa[N];
void dfs(int u) {
    for (int v : G[u]) {
        if (v == fa[u]) continue;
        fa[v] = u; dfs(v);
    }
}
void dfs(int u, int mx, int cnt, int now) {
    if (cnt == mx) {
        for (int i = 1; i <= n; i++) {
            if (!(now & (1 << (i - 1)))) continue;
            if (!(now & (1 << (fa[i] - 1)))) continue;
            dp[now] = min(dp[now], max(dp[now ^ (1 << (i - 1))], d[i][mx]));
        }
        return;
    }
    if (u == n) return;
    dfs(u + 1, mx, cnt, now);
    dfs(u + 1, mx, cnt + 1, now + (1 << u));
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i] > 0) {
                int l = j, r = 1e9, mid;
                while (l < r) {
                    mid = (l + r) >> 1;
                    if (chk(mid, j, i)) r = mid;
                    else l = mid + 1;
                }
                d[i][j] = l;
            } else if (c[i] < 0) {
                LL now = b[i] + j * c[i];
                if (now <= 0) d[i][j] = a[i] + j - 1;
                else {
                    LL cnt = (now - 1) / (-c[i]);
                    LL ls = now + cnt * c[i];
                    LL sum = (now + ls) * (cnt + 1) / 2;
                    if (sum <= a[i]) d[i][j] = a[i] - sum + cnt + j;
                    else {
                        int l = j, r = j + cnt, mid;
                        while (l < r) {
                            mid = (l + r) >> 1;
                            if (chk(mid, j, i)) r = mid;
                            else l = mid + 1;
                        }
                        d[i][j] = l;
                    }
                }
            }
            else d[i][j] = (a[i] + b[i] - 1) / b[i];
        }
    }
    int fl1 = 1;
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        vis[u][v] = vis[v][u] = 1;
        if (u != i || v != i + 1) fl1 = 0;
    }
    if (fl1) {
        LL ans = 0;
        for (int i = 1; i <= n; i++) ans += d[i][i];
        printf("%lld\n", ans);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    dfs(1);
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = d[1][1];
    for (int mx = 2; mx <= n; mx++) {
        dfs(0, mx, 0, 0);
    }
    printf("%lld\n", dp[(1 << n) - 1]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
