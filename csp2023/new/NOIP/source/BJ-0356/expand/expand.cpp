#include <bits/stdc++.h>
using namespace std;
int c, n, m, q, x[500005], y[500005], xx[500005], yy[500005], kx, ky, p, v;
int sum[2005][2005];
bool dp[2005][2005];
inline void work(){
    if(x[1] == y[1]){
        cout << 0;
        return;
    }
    else if(x[1] > y[1]){
        dp[0][0] = 1;
        for(int i = 0;i <= m;i++){
            sum[0][i] = 1;
        }
        for(int i = 1;i <= n;i++){
            int pos = 0;
            for(int j = 1;j <= m;j++){
                if(x[i] <= y[j]){
                    dp[i][j] = 0;
                    pos = j;
                }
                else{
                    if(pos == 0){
                        dp[i][j] = sum[i - 1][j];
                    }
                    else{
                        dp[i][j] = (sum[i - 1][j] - sum[i - 1][pos - 1] > 0);
                    }
                }
                sum[i][j] = sum[i][j - 1] + dp[i][j];
            }
        }
        cout << dp[n][m];
    }
    else if(x[1] < y[1]){
        dp[0][0] = 1;
        for(int i = 0;i <= m;i++){
            sum[0][i] = 1;
        }
        for(int i = 1;i <= n;i++){
            int pos = 0;
            for(int j = 1;j <= m;j++){
                if(x[i] >= y[j]){
                    dp[i][j] = 0;
                    pos = j;
                }
                else{
                    if(pos == 0){
                        dp[i][j] = sum[i - 1][j];
                    }
                    else{
                        dp[i][j] = (sum[i - 1][j] - sum[i - 1][pos - 1] > 0);
                    }
                }
                sum[i][j] = sum[i][j - 1] + dp[i][j];
            }
        }
        cout << dp[n][m];
    }
}
signed main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> c >> n >> m >> q;
    for(int i = 1;i <= n;i++){
        cin >> x[i];
        xx[i] = x[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> y[i];
        yy[i] = y[i];
    }
    work();
    while(q--){
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        memcpy(x, xx, sizeof(x));
        memcpy(y, yy, sizeof(y));
        cin >> kx >> ky;
        for(int i = 1;i <= kx;i++){
            cin >> p >> v;
            x[p] = v;
        }
        for(int i = 1;i <= ky;i++){
            cin >> p >> v;
            y[p] = v;
        }
        work();
    }
    return 0;
}
