#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d;
ll u[100005];
ll a[100005];
ll dp[100005];
ll Min=1e9;
ll x;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for(ll i=1;i<=100000;i++){
        dp[i]=1e9;
    }
    scanf("%lld%lld",&n,&d);
    for(ll i=1;i<=n-1;i++){
        scanf("%lld",&u[i+1]);
        u[i+1]+=u[i];
    }
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        Min=min(Min,a[i]);
    }
    x=ceil(u[n]/d);
    dp[0]=0;
    for(ll i=1;i<n;i++){
        for(ll j=1;j<=x;j++){
            if((j-1)*d>=u[i]){
                dp[j]=min(dp[j],dp[j-1]+a[i]);
            }
        }
    }
    printf("%lld ",dp[x]);
    return 0;
}

