#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 1000 + 5;
const int M = 1e5 + 5;
//T4
struct Node{
    LL y, z;
};
int c, T;
LL dp[N][N], dpmax[N];
int n, m, k, d;
vector <Node> v[N];
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for(int i = 0; i <= n; i++) v[i].clear();
        for(int i = 1; i <= m; i++) {
            int x;
            LL y, z;
            scanf("%d%lld%lld", &x, &y, &z);
            v[x].push_back((Node){y, z});
        }
        memset(dp, -0x3f, sizeof(dp));
        memset(dpmax, -0x3f, sizeof(dpmax));
        for(int i = 0; i <= k; i++) dp[0][i] = 0;
        dpmax[0] = 0;
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dpmax[i-1];
            dpmax[i] = dpmax[i-1];
            for(int j = 1; j <= k; j++) {
                dp[i][j] = dp[i-1][j-1] - d;
                for(int p = 0; p < v[i].size(); p++) {
                    LL y = v[i][p].y, z = v[i][p].z;
                    if (j >= y) dp[i][j] += z;
                }
                dpmax[i] = max(dpmax[i], dp[i][j]);
            }
        }
        LL ans = -1e9;
        for(int i = 0; i <= k; i++) ans = max(ans, dp[n][i]);
        cout << ans << endl;
    }
    return 0;
}
