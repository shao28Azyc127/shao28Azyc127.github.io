#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 1e3 + 10, M = 1e5 + 10, K = 1e3 + 10;
int c, t;
int n, m, k, d;
//能量值可以是负数
LL ans;
LL dp[N][K];
LL v[N][K];
int main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while(t--){
        ans = -1e18;
        memset(dp, -0x3f, sizeof(dp));
        memset(v, 0, sizeof(v));
        //注意清空
        scanf("%d %d %d %d", &n, &m, &k, &d);
        for(int i = 1; i <= m; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            for(int j = y; j <= k; j++){
                v[x][j] += z;
            }
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i][0] = dp[i - 1][0];
            for(int j = 1; j <= k; j++){
                dp[i][0] = max(dp[i][0], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - d + v[i][j]);
            }
        }
        /*for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k; j++){
                //printf("%d %d dp:%lld v:%lld\n", i, j, dp[i][j], v[i][j]);
            }
        }*/
        for(int i = 0; i <= k; i++){
            ans = max(ans, dp[n][i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
