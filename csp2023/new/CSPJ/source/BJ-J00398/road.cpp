#include<bits/stdc++.h>
using namespace std;
int n,d,sum,ans,dis[100005],a[100005],dp[100005];
int zheng(double x){
    if(x!=int(x)) return int (x+1);
    else return x;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>dis[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[2]=zheng(1.0*dis[1]/d)*a[1];
    sum=zheng(1.0*dis[1]/d)*d-dis[1];
    int minn=a[1];
    for(int i=3;i<=n;i++){
            minn=min(minn,a[i-1]);
            dp[i]=dp[i-1]+zheng(1.0*(dis[i-1]-sum)/d)*minn;
            sum+=zheng(1.0*(dis[i-1]-sum)/d)*d;
            sum-=dis[i-1];
    }
    cout<<dp[n];
    return 0;
}
