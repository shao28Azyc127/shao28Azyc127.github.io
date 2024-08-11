#include<bits/stdc++.h>
using namespace std;
int c, n, m, q;
int x[500005], y[500005];
int xx[500005], yy[500005];
int dp[2005][2005];
int cal0(){
    if(x[1] < y[1]) return 0;
    if(x[n] < y[m]) return 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) dp[i][j] = 0;
    dp[0][0] = 1;
  //  cout << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x[i] > y[j]){
                dp[i][j] = (dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1]);
            //    if(dp[i][j]) cout << i << "-" << j << "ok" << endl;
            }
        }
    }
    return dp[n][m];
}
int cal1(){
    if(x[1] > y[1]) return 0;
    if(x[n] > y[m]) return 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) dp[i][j] = 0;
    dp[0][0] = 1;
  //  cout << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x[i] < y[j]){
                dp[i][j] = (dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1]);
         //       if(dp[i][j]) cout << i << "-" << j << "ok" << endl;
            }
        }
    }
    return dp[n][m];
}
int cal(){
    if(cal0()) return 1;
    if(cal1()) return 1;
    return 0;
}
signed main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= m; i++) cin >> y[i];
    for(int i = 1; i <= n; i++) xx[i] = x[i];
    for(int i = 1; i <= m; i++) yy[i] = y[i];
    if(c <= 7){
        cout << cal();
        for(int i = 1; i <= q; i++){
            int kx, ky;
            cin >> kx >> ky;
            for(int i = 1; i <= n; i++) x[i] = xx[i];
            for(int i = 1; i <= m; i++) y[i] = yy[i];
            for(int j = 1; j <= kx; j++){
                int p, v;
                cin >> p >> v;
                x[p] = v;
            }
            for(int j = 1; j <= ky; j++){
                int p, v;
                cin >> p >> v;
                y[p] = v;
            }
          /*  cout << '\n';
            for(int i = 1; i <= n; i++) cout << x[i] << " ";
            cout << ";";
            for(int i = 1; i <= m; i++) cout << y[i] << ' ';*/
            cout << cal();
        }
    } else if(c >= 8 && c <= 14){

    }
    return 0;
}
