#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1005][1005],n,m,t,c,k,d,x,y,v,reward[1005][1005];
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=-9e18;
        cin>>n>>m>>k>>d;
        memset(reward,0,sizeof(reward));
        memset(dp,-0x3f3f3f3f,sizeof(dp));
        dp[0][0]=0;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>v;
            reward[x][y]=v;
        }
        for(int i=0;i<=n;i++)
            for(int j=0;j<=min(k,i);j++){
                dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]-d+reward[i+1][j+1]);
            }
        //cout<<dp[15][1]<<endl;
    //    for(int i=0;i<=n;i++)
    //        for(int j=0;j<=min(k,i);j++){
       //         cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        //    }
        for(int i=0;i<=k;i++) ans=max(ans,dp[n][i]);
        cout<<ans<<endl;
    }
    return 0;
}