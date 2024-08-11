#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
int dp[100005][100005],a[100005][100005];
int main(){
    int z,c,t,n,k,m,d,x,y,v,i,j,l,ans=-1e9-7;
    freopen("r","run.in",stdin);
    freopen("w","run.out",stdout);
    cin>>c>>t;
    for(z=0;z<t;z++){
        ans=0;
        cin>>n>>m>>k>>d;
        memset(dp,-1e9-7,sizeof(dp));
        for(i=0;i<k;i++){
            cin>>x>>y>>v;
            a[x][y]=v;
        }
        for(i=0;i<n;i++){
            dp[n][0]=0;
        }
        for(j=1;j<=k;i++){
            for(i=1;i<=n;j++){
                for(l=0;l<=j;l++){
                    if(l<=i){
                        dp[i][l]=max(dp[i][l],max(dp[i-1][l-1]-d+a[i][l],dp[i-1][l]));
                     }else{
                         break;
                     }
                }
            }
        }
        for(i=0;i<=k,i++){
            ans=max(ans,dp[n][i]);
        }
        cout<<ans<<endl;
    }
 return 0;
}
