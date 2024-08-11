#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 1000 + 5;

int sid, T, n, m, K, d, f[NR][NR], s[NR][NR];

inline void solve() {
    cin >> n >> m >> K >> d;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) s[i][j] = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y, z; cin >> x >> y >> z;
        s[x][y] += z;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) s[i][j] += s[i][j - 1];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        f[i][0] = 0;
        for (int j = 0; j <= min(K, i - 1); ++j) f[i][0] = max(f[i][0], f[i - 1][j]);
        ans = max(ans, f[i][0]);
        int p = 0;
        for (int j = 1; j <= min(K, i); ++j) {
            f[i][j] = f[i - 1][j - 1] - d + s[i][j];
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0);
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> sid >> T;
    while (T --) solve();
    return 0;
}