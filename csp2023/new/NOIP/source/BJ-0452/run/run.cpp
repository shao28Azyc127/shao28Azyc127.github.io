#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 10005
#define M 10005

// #define N 5
// #define M 5

int dp[N][N][2];

int act[M][M];

int main(){

    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int I=0;I<t;I++){
        memset(dp,0,sizeof(dp));
        memset(act,0,sizeof(act));
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        for(int i=0;i<m;i++){
            int x,y,v;
            cin>>x>>y>>v;
            act[x-y+1][x]+=v;
        }
        for(int i=1;i<=n;i++){
            dp[i][i][1]=-d+act[i][i];
            dp[i][i][0]=max(0,dp[i][i][1]);
        }
        int ans=0;
        for(int l=2;l<=n;l++){
            int j;
            for(int i=1;(j=i+l-1)<=n;i++){
                if(l<=k){
                    for(int kk=i;kk+1<=j;kk++){
                        dp[i][j][1]+=dp[i][kk][1]+dp[kk+1][j][1]+l*d;
                    }dp[i][j][1]+=-l*d+act[i][j];
                }else dp[i][j][1]=INT32_MIN;

                dp[i][j][0]=max(0,dp[i][j][1]);
                for(int i2=i;i2<j;i2++){
                    for(int j2=i2+2;j2<=j;j2++){
                        dp[i][j][0]=max(dp[i][j][0],dp[i][i2][0]+dp[j2][j][0]);
                    }
                }
                ans=max(ans,dp[i][j][0]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}