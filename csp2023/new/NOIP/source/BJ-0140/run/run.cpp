#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct Chal{
    int x, y, v;
};
inline bool operator < (Chal a, Chal b){return a.y < b.y;}
int tid, n, m, k, d;
long long dp[N][N];
vector<Chal> tsk[N];

inline void solve(){
    scanf("%d%d%d%d", &n, &m, &k, &d);
    int tx, ty, tv, p;
    for (int i=1; i<=m; i++){
        scanf("%d%d%d", &tx, &ty, &tv);
        if (ty > tx) continue;
        tsk[tx].push_back({tx, ty, tv});
    }
    for (int i=1; i<=n; i++) sort(tsk[i].begin(), tsk[i].end());
    for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) dp[i][j] = -1e18;
    dp[0][0] = 0;
    for (int i=1; i<=n; i++){
        for (int l=0; l<=min(i-1, k); l++) dp[i][0] = max(dp[i][0], dp[i - 1][l]);
        p = 0;
        for (int j=1; j<=min(i, k); j++){
            if (p < (int)tsk[i].size() && tsk[i][p].y == j){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - 1ll * d + 1ll * tsk[i][p].v);
                p++;
            }
            else dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - 1ll * d);
        }
    }
    long long ans = -9e18;
    for (int i=0; i<=k; i++) ans = max(ans, dp[n][i]);
    printf("%lld\n", ans);
    for (int i=1; i<=n; i++) tsk[i].clear();
}

int main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int t;
    scanf("%d%d", &tid, &t);
    while (t--){
        solve();
    }
    return 0;
}
