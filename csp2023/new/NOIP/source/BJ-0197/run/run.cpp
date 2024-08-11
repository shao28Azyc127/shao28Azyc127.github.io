#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1005][1005];
int x[1005], y[1005], z[1005];
int main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int t, c;
    cin>>c>>t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        int n, m, k, d;
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            cin>>x[i]>>y[i]>>z[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(i, k);j++){
                for(int id=1;id<=m;id++){
                    if(j<y[id]) dp[i][j]=dp[i-j][0]-j*d;
                    else{
                        dp[i][j]=dp[i-y[id]][j-y[id]]-y[id]*d+z[id];
                    }
                }
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans, dp[n][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
