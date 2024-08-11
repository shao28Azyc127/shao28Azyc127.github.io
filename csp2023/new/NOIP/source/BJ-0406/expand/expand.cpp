#include<cstdio>
#include<bitset>
#include<iostream>
using namespace std;
typedef long long ll;
const ll N=2e3+10;
ll x[N],y[N],a[N],b[N],ans[N],n,m;
bitset<N> dp[N];
ll dynamic_program(){
    for(ll i=1;i<=n;i++){
        dp[i]=0;
    }
    dp[1][1]=1;
    if(a[1]==b[1]) return 0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(a[1]<b[1]&&a[i]>=b[j]) continue;
            if(a[1]>b[1]&&a[i]<=b[j]) continue;
            dp[i][j]=dp[i][j]|dp[i-1][j-1]|dp[i-1][j]|dp[i][j-1];
        }
    }
    return dp[n][m];
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ll c,q;
    scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
    for(ll i=1;i<=n;i++){
    scanf("%lld",&x[i]); a[i]=x[i];}
    for(ll i=1;i<=m;i++){
    scanf("%lld",&y[i]); b[i]=y[i];}
    ans[0]=dynamic_program();
    for(ll k=1;k<=q;k++){
        for(ll i=1;i<=n;i++) a[i]=x[i];
        for(ll i=1;i<=m;i++) b[i]=y[i];
        ll kx,ky;
        scanf("%lld%lld",&kx,&ky);
        for(ll i=1;i<=kx;i++){
            ll px,vx;
            scanf("%lld%lld",&px,&vx);
            a[px]=vx;
        }
        for(ll i=1;i<=ky;i++){
            ll py,vy;
            scanf("%lld%lld",&py,&vy);
            b[py]=vy;
        }
        ans[k]=dynamic_program();
    }
    for(ll i=0;i<=q;i++){
        printf("%lld",ans[i]);
    }
    return 0;
}
