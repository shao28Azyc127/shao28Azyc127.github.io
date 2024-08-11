#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
typedef long long ll;

int c, t, n, m, k, d;

struct Q {
    int x, y, v;
} q[MAXN];

namespace Subtask1 {
    const int N = 1e3 + 5;
    vector<int> p[N];
    ll dp[N][N], pre[N];

    inline void solve() {
        for (int i = 0; i <= n; i++) {
            pre[i] = 0;
            p[i].clear();
            for (int j = 0; j <= n; j++)
                dp[i][j] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int r = q[i].x;
            p[r].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = pre[n];
            for (int j = 1; j <= min(k, i); j++) {
                dp[i][j] = dp[i - 1][j - 1];
                for (int r: p[i])
                    if (j >= q[r].y) 
                        dp[i][j] += q[r].v;
                dp[i][j] -= d;
            }
            pre[0] = dp[i][0];
            for (int j = 1; j <= n; j++)
                pre[j] = max(pre[j - 1], dp[i][j]);
        }
        printf("%lld\n", pre[n]);
    }
}

inline void solve() {
    scanf("%d%d%d%d", &n, &m, &k, &d);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].v);
    }
    if (c <= 9) {
        Subtask1::solve();
        return;
    }
}

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--) solve();
}