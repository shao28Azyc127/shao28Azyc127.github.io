#include<iostream>
#include<cstdio>
using namespace std;
int n,u[1000005],a[1000005],d,dp[1005][100005],minn=1000000005,sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;++i){
        cin>>u[i];
        u[i]+=u[i-1];
    }
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<sum;
    return 0;
    for(int i=1;i<=n;++i){
            cout<<i<<endl;
        for(int j=d;j<=u[n];++j){
                dp[i][j]=dp[i][j-d]+a[i];
            cout<<j<<" "<<dp[i][j]<<endl;
        }
    for(int j=0;j<=u[n];++j){
        dp[i][j]=min(dp[i][j],dp[i-1][j-u[i-1]+u[i-2]]);
    }
    }
    for(int i=0;i<u[n];++i){
        minn=min(minn,dp[n][i]);
    }
    cout<<minn;
    return 0;
}
