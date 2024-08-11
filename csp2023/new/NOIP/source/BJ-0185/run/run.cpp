#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+10;
int dp[maxn][maxn],aw[maxn][maxn];
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--){
        memset(dp,128,sizeof(dp));
        memset(aw,0,sizeof(aw));
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        for (int i=1;i<=m;i++){
            int x,y,v;
            cin>>x>>y>>v;
            aw[x][y]+=v;
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                aw[i][j]=aw[i][j]+aw[i][j-1];
               // cout<<aw[i][j]<<" ";
            }//cout<<endl;
        }
        dp[0][0]=0;
        int ans=-1e18;
        for (int i=1;i<=n;i++){
            for (int j=0;j<=min(i-1,k);j++){
                dp[i][0]=max(dp[i][0],dp[i-1][j]);
            }
            for (int j=1;j<=min(i,k);j++){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d+aw[i][j]);
            }
        }
        for (int j=0;j<=min(n,k);j++){
            ans=max(ans,dp[n][j]);
        }
        /*for (int i=1;i<=n;i++){
            for (int j=0;j<=n;j++)cout<<dp[i][j]<<" ";cout<<endl;
        }*/
        cout<<ans<<endl;
    }
}
