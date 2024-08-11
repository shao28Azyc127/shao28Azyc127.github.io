//about 28pts
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
int C, T, n, m, k, d;
long long dp[1005][1005];
vector<pair<int, int> > ch[1005];
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> C >> T;
    while (T--) {
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= n; i++) ch[i].clear();
        for (int i = 1; i <= m; i++) {
            int x, y, v; cin >> x >> y >> v;
            ch[x].push_back(make_pair(y, v));
        }
        memset(dp, -0x3f, sizeof(dp));
        dp[0][0] = 0ll;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) dp[i][0] = max(dp[i][0], dp[i - 1][j]);
            for (int j = 1; j <= k; j++) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - 1ll * d);
            for (auto p : ch[i]) {
                int y = p.first, v = p.second;
                for (int j = y; j <= k; j++) dp[i][j] += 1ll * v;
            }
        }
        long long ans = -0x3f3f3f3f3f3f3f3f;
        for (int i = 0; i <= k; i++)
            ans = max(ans, dp[n][i]);
        cout << ans << '\n';
    }
    return 0;
}
