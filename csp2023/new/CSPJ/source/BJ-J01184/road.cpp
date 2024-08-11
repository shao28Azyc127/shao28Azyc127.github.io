#include<bits/stdc++.h>
using namespace std;

#define ll long long
struct X{
    ll v;
    int last;
    ll len;
}dp[100010];
int n,d,a[100010];
ll dis[100010];
ll updi(ll x,int y){
    return x/y+(bool)(x%y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%d",&dis[i]);
        dis[i]+=dis[i-1];
    }
    for(int i=n;i>1;i--)dis[i]=dis[i-1];
    dis[1]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dp[2]={a[1]*updi(dis[2],d),1,updi(dis[2],d)*d};
    for(int i=2;i<n;i++){
        ll v=updi(dis[i+1]-dp[i].len,d);
        if(v*a[i]<v*a[dp[i].last]){
            dp[i+1]={dp[i].v+v*a[i],i,dp[i].len+v*d};
        }
        else{
            dp[i+1]={dp[i].v+v*a[dp[i].last],dp[i].last,dp[i].len+v*d};
        }
    }
    printf("%lld",dp[n].v);
    return 0;
}
