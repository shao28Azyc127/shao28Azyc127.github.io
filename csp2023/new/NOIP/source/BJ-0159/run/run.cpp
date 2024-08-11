// 44pts
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 9;
struct node {
    int v, w;
};
bool cmp(node x, node y) {
    return x.v < y.v;
}
int c, _, n, m, k, d;
LL dp[1009][1009];
vector<node> ch[N];
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d%d", &c, &_);
    while (_--) {
        scanf("%d%d%d%d", &n, &m, &k, &d);
        if (c == 17 || c == 18) { // 8pts
            LL ans = 0;
            for (int i = 1; i <= m; i++) {
                int x, y, v; scanf("%d%d%d", &x, &y, &v);
                if (y <= k) ans += max(v - 1ll * y * d, 0ll);
            }
            printf("%lld\n", ans);
            continue;
        }
        for (int i = 1; i <= n; i++) ch[i].clear();
        for (int i = 1; i <= m; i++) {
            int x, y, v; scanf("%d%d%d", &x, &y, &v);
            ch[x].push_back({y, v});
        }
        for (int i = 1; i <= n; i++) sort(ch[i].begin(), ch[i].end(), cmp);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -4e18;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            int lt = 0, sz = ch[i].size(); LL sum = 0;
            for (int j = 0; j <= k; j++) {
                if (dp[i][j] < -2e18) continue;
                while (lt < sz && j >= ch[i][lt].v) sum += ch[i][lt++].w;
                dp[i][j] += sum;
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] - d);
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
            }
        }
        LL ans = -4e18, sum = 0; int lt = 0, sz = ch[n].size();
        for (int i = 0; i <= k; i++) {
            while (lt < sz && i >= ch[n][lt].v) sum += ch[n][lt++].w;
            ans = max(ans, dp[n][i] + sum);
        }
        printf("%lld\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
