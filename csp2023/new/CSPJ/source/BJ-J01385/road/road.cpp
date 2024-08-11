#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[100005];
int sum[100005];
int val[100005];
int cost[100005];
int xx[100005];
int mm=2e9;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;cin >>n>>d;
    for(int i=2;i<=n;i++){
        cin >>val[i];
        sum[i]=sum[i-1]+val[i];
    }
    for(int i=1;i<=n;i++){
        cin >>cost[i];
        mm=min(mm,cost[i]);
    }
    if(mm==cost[1]){
        cout <<(sum[n]+d-1)/d*cost[1];
        return 0;
    }
    memset(dp,2e9,sizeof(dp));
    dp[1]=0;
    xx[1]=0;
    for(int i=2;i<=n;i++){
        int mn=2e9;
        int op=0;
        for(int j=i-1;j>=1;j--){
            if(mn>dp[j]+(sum[i]-sum[j]+d-1-xx[j])/d*cost[j]){
                op=j;
                mn=dp[j]+(sum[i]-sum[j]+d-1-xx[j])/d*cost[j];
            }
        }
        dp[i]=mn;
        xx[i]=abs((sum[i]-sum[op]-xx[op])-(sum[i]-sum[op]-xx[op])/d*d);
    }
    cout <<dp[n];
    return 0;
}
