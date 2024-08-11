#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,d,x,y,v,c,ans,t,b[1001][1001],dp[1001][1001];
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(b,0,sizeof(b));
        memset(dp,0,sizeof(dp));
        cin>>n>>m>>k>>d;
        while(m--){
            cin>>x>>y>>v;
            b[x][y]+=v;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                b[i][j]+=b[i][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][0]=max(dp[i][0],dp[i-1][j]);
            }
            for(int j=1;j<=k;j++){
                dp[i][j]=dp[i-1][j-1]-d+b[i][j];
            }
        }
        ans=0;
        for(int j=0;j<=k;j++){
            ans=max(ans,dp[n][j]);
        }
        cout<<ans<<endl;
    }
}
