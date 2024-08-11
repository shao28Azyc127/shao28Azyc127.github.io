#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int c,t,n,m,k;
long long d,x,y,v,dp[1005][1005];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        memset(dp,0,sizeof(dp));
        scanf("%d%d%d%lld",&n,&m,&k,&d);
        for(int i = 1;i <= m;i++){
            scanf("%lld%lld%lld",&x,&y,&v);
            if(y <= k){
                for(int j = y;j <= k;j++) dp[x][j] += v;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= k;j++) dp[i][0] = max(dp[i][0],dp[i - 1][j]);
            for(int j = 1;j <= k;j++) dp[i][j] += dp[i - 1][j - 1] - d;
        }
        long long ans = 0;
        for(int i = 0;i <= k;i++) ans = max(ans,dp[n][i]);
        printf("%lld\n",ans);
    }
    return 0;
}