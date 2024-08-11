#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;

int c, t, n, m, k;
ll d, dp[maxn], x[maxn], y[maxn], v[maxn];
// vector <int> act[maxn];

int main ()
{
    freopen ("run.in", "r", stdin);
    freopen ("run.out", "w", stdout);
    scanf ("%d%d", &c, &t);
    while (t --) {
        memset (dp, ~0x7f, sizeof(dp));
        scanf ("%d%d%d%lld", &n, &m, &k, &d);
        for (int i = 1; i <= m; i ++) {
            scanf ("%lld%lld%lld", &x[i], &y[i], &v[i]);
            // act[x[i]].push_back(i);
        }
        dp[1] = 0, dp[0] = 0;
        for (int i = 1; i <= m; i ++) {
            for (int j = n; j > 1; j --) {
                dp[j] = max(dp[j - 1], dp[j]);
                // for (int q = 0; q < act[j].size(); q ++) {
                    // int p = act[j][q];
                    if (x[i] == j && y[i] <= k) {
                        dp[j] = max (dp[j], dp[x[i] - y[i]] - y[i] * d + v[i]);
                        // printf ("%d %lld\n", j, dp[j]);
                    }
                // }
            }
        }
        printf ("%lld\n", dp[n]);
    }
    return 0;
}