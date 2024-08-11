#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,m,k,d;
const int N=1e5+5;
long long dp[1005][1005]; 
int x[N],y[N],v[N];
inline void solve(){
    scanf("%d%d%d%d",&n,&m,&k,&d);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x[i],&y[i],&v[i]);
    }
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            dp[i][j]=-10000000000000;
        }
    }
    dp[1][1]=-d;
    dp[1][0]=0;
    dp[0][0]=0;
    long long ans=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0];
       dp[i][1]=-d;
        for(int j=0;j<=k;j++){
            if(j!=0)
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d);
            for(int l=1;l<=m;++l){
                if(y[l]==0) dp[i][j]=max(dp[i][j],(long long)v[l]-d);
                if(j!=0)
                    if(i==x[l] && j>=y[l]) dp[i][j]=max(dp[i][j],(long long)dp[i-1][j-1]+v[l]-d);
            }
            
            dp[i][0]=max(dp[i][0],dp[i-1][j]);
            if(i==n) ans=max(ans,max(dp[i][j],dp[i][0]));
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}