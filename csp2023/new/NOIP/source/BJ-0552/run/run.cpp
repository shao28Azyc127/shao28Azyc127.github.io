#include <bits/stdc++.h>
using namespace std;

struct ch{
    int x, y, v;
};

int main(){
    int c,t;
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while (t--){
        int n,m,k,d;
        cin >> n >> m >> k >> d;
        ch chal[m+5];
        int dp[n+5], cnt=0;
        for (int i=0;i<n+5;i++){
            dp[i] = 0;
        }
        for (int i=1;i<=m;i++){
            cin >> chal[i].x >> chal[i].y >> chal[i].v;
        }
        for (int i=1;i<=n;i++){
            if (chal[cnt+1].x > i+k){
                dp[i] = dp[i-1];
            }
            dp[i] = max(dp[i-1]-chal[i].y*d+chal[i].v, dp[i-1]);
        }
        cout << dp[m] << endl;
    }
    // pian fen
}