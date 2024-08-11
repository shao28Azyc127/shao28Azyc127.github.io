#include<bits/stdc++.h>
using namespace std;
struct node{
    int x=0;
    int y=0;
    int v=0;
};
bool cmp(node val1,node val2){
    return val1.x<val2.x;
}
node arr[1005];
int dp[1005][1005];
int main(){
    freopen("run2.in","r",stdin);
    freopen("run2.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int ans=0;
        memset(arr,0,sizeof arr);
        memset(dp,0,sizeof dp);
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            cin>>arr[i].x>>arr[i].y>>arr[i].v;
        }
        sort(arr+1,arr+m+1,cmp);
        int cnt=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k&&j<=n;j++){
                dp[i][0]=max(dp[i][0],dp[i-1][j]);
            }
            for(int j=1;j<=k&&j<=n;j++){
                dp[i][j]=dp[i-1][j-1]-d;
            }
            while(arr[cnt].x==i){
                for(int j=arr[cnt].y;j<=k&&j<=n;j++){
                    dp[i][j]+=arr[cnt].v;
                }
                cnt++;
            }
        }
        for(int i=0;i<=n&&i<=k;i++){
            ans=max(ans,dp[n][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
