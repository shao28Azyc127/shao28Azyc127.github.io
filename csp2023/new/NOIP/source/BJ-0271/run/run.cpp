#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo = 1000000000000000000;
int n, m, k, d;
struct Chal {
    int x, y, v;
    bool operator<(const Chal &oth) const {
        return x < oth.x;
    }
} a[100005];
ll dp[1005][1005];
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    if (1 <= c && c <= 9) {
        while (t--) {
            scanf("%d%d%d%d", &n, &m, &k, &d);
            for (int i = 1; i <= m; ++i)
                scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
            sort(a + 1, a + m + 1);
            int nxt_a = 1;
            ll dpm = 0;
            for (int i = 1; i <= n; ++i) {
                int nnxt_a;
                ll add;
                for (int j = 0; j <= i && j <= k; ++j) {
                    nnxt_a = nxt_a, add = 0;
                    while (nnxt_a <= m && a[nnxt_a].x == i) {
                        if (j >= a[nnxt_a].y)
                            add += a[nnxt_a].v;
                        ++nnxt_a;
                    }
                    if (j == 0)
                        dp[i][j] = dpm + add;
                    else
                        dp[i][j] = dp[i - 1][j - 1] + add - d;
                }
                nxt_a = nnxt_a;
                dpm = -oo;
                for (int j = 0; j <= i && j <= k; ++j)
                    dpm = max(dpm, dp[i][j]);
            }
            printf("%lld\n", dpm);
        }
        return 0;
    }
}