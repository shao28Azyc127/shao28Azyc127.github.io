#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
const long long inf = 1e18 + 5;
int sid, T;
int n, m, k, d;
struct node {
    int ln;
    int vl;
};
node make(int ln, int vl) {
    node res;
    res.ln = ln;
    res.vl = vl;
    return res;
}
vector<node> g[N];
long long dp[2][N];
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d%d", &sid, &T);
    if(sid <= 9) {
        for(int ti = 1; ti <= T; ti++) {
            scanf("%d%d%d%d", &n, &m, &k, &d);
            int x, y, v;
            for(int i = 1; i <= n; i++) {
                g[i].clear();
            }
            for(int i = 1; i <= m; i++) {
                scanf("%d%d%d", &x, &y, &v);
                g[x].push_back(make(y, v));
            }
            int fg = 0;
            for(int i = 0; i <= k; i++) {
                dp[fg][i] = -inf;
            }
            dp[fg][0] = 0;
            for(int i = 1; i <= n; i++) {
                fg ^= 1;
                for(int j = 0; j <= k; j++) {
                    dp[fg][j] = -inf;
                }
                long long sum = 0;
                for(int j = 0; j <= k; j++) {
                    sum = 0;
                    if(j < k) {
                        for(int p = 0; p < g[i].size(); p++) {
                            if(g[i][p].ln <= j + 1) {
                                sum += g[i][p].vl;
                            }
                        }
                        dp[fg][j + 1] = max(dp[fg][j + 1], dp[fg ^ 1][j] + sum - d);
                    }
                    dp[fg][0] = max(dp[fg][0], dp[fg ^ 1][j]);
                }
            }
            long long mx = -inf;
            for(int i = 0; i <= k; i++) {
                mx = max(mx, dp[fg][i]);
            }
            printf("%lld\n", mx);
        }
    }
    return 0;
}
