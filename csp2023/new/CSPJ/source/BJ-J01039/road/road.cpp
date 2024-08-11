#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,d,v[N],a[N],minn[N],m[N];
long long sum[N],ans=0x3f3f3f3f,dp[N];
long long need(int i,int j){
    int l=sum[j-1]-sum[i-1];
    if(l%d) return a[i]*(l/d)+a[i];
    return a[i]*(l/d);
}
long long need2(int i,int j){
    int l=sum[j-1]-sum[i-1]-m[i];
    if(l%d) return a[i]*(l/d)+a[i];
    return a[i]*(l/d);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=0x3f3f3f3f;
    for(int i=2;i<=n;i++){
        int x=need(i-1,i),y=need(minn[i-1],i);
        if(i==n) x=need2(i-1,i),y=need2(minn[i-1],i);
        dp[i]=min(dp[i-1]+x,dp[minn[i-1]]+y);
        if(i==3){
            x=need(i-1,i),y=need(1,i);
            dp[i]=min(dp[i-1]+x,dp[1]+y);
        }
        if(a[i]<=a[minn[i-1]]) minn[i]=i;
        else minn[i]=minn[i-1];
        if(dp[i-1]+x<dp[minn[i-1]]+y){
            m[i]=m[i-1];
            if(v[i-1]%d!=0) m[i]+=d*(v[i-1]/d+1)-v[i-1];
        }else m[i]=d*((sum[i-1]-sum[minn[i]-1])/d+1)-v[i-1]+m[minn[i]];

        if(m[i]>=sum[n-1]-sum[i-1]){
            ans=dp[i];
        }
    }
    ans=min(ans,dp[n]);
    cout<<ans<<endl;
    return 0;
}
