#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[1005][1005];
int price[1005][1005];
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=0;
                price[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            int x,y,v;
            cin>>x>>y>>v;
            for(int d=y;d<=k;d++){
                price[x][d]+=v;
            }
        }
        int maxl=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(i,k);j++){
                if(j==0){
                    dp[i][j]=max(maxl,dp[i-1][j]);
                    maxl=0;
                }else{
                    dp[i][j]=dp[i-1][j-1]+price[i][j]-d;
                }
                maxl=max(maxl,dp[i][j]);
            }
        }
        cout<<maxl<<endl;
    }
    return 0;
}
