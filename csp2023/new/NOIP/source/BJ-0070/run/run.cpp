#include <bits/stdc++.h>
typedef long long LL;
const int MAXN = 1005;
int n, m, k, d;
LL f[MAXN][MAXN], g[MAXN][MAXN];

void solve() {
    memset(g, 0, sizeof(g));
    std::cin >> n >> m >> k >> d;
    for(int i = 1; i <= m; ++i) {
        int x, y, v;
        std::cin >> x >> y >> v;
        g[x][y] += v;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            g[i][j] += g[i][j - 1];
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= k; ++j)
            f[i][j] = -0x3f3f3f3f3f3f3f3fLL;
    f[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= k; ++j)
            f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + g[i][j] - d);
        for(int j = 0; j <= k; ++j)
            f[i][0] = std::max(f[i][0], f[i - 1][j]);
    }
    LL ans = 0;
    for(int i = 0; i <= k; ++i)
        ans = std::max(ans, f[n][i]);
    std::cout << ans << '\n';
}

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int sid, T;
    std::cin >> sid >> T;
    while(T--)
        solve();
    return 0;
}