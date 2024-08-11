#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x=0;
    long long y=0;
    long long v=0;
};
bool cmp(node val1,node val2){
    return val1.x<val2.x;
}
node arr[1005];
long long dp[1005][1005];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--){
        long long ans=0;
        memset(arr,0,sizeof arr);
        memset(dp,0,sizeof dp);
        long long n,m,k,d;
        cin>>n>>m>>k>>d;
        for(long long i=1;i<=m;i++){
            cin>>arr[i].x>>arr[i].y>>arr[i].v;
        }
        sort(arr+1,arr+m+1,cmp);
        long long cnt=1;
        for(long long i=1;i<=n;i++){
            for(long long j=0;j<=k&&j<=n;j++){
                dp[i][0]=max(dp[i][0],dp[i-1][j]);
            }
            for(long long j=1;j<=k&&j<=n;j++){
                dp[i][j]=dp[i-1][j-1]-d;
            }
            while(arr[cnt].x==i){
                for(long long j=arr[cnt].y;j<=k&&j<=n;j++){
                    dp[i][j]+=arr[cnt].v;
                }
                cnt++;
            }
        }
        for(long long i=0;i<=n&&i<=k;i++){
            ans=max(ans,dp[n][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
