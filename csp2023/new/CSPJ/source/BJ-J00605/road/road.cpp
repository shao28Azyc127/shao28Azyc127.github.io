#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll up_qz(ll x,ll y){
    if(x%y==0)return x/y;
    else return x/y+1;
}
ll n,d,dis[100005],v[100005],sy,tot,chp;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld",&n,&d);
    for(ll i=2;i<=n;++i)scanf("%lld",&dis[i]);
    for(ll i=1;i<=n;++i)scanf("%lld",&v[i]);
    chp=v[1];
    for(ll i=2;i<=n;++i){
        int ls=up_qz(dis[i]-sy,d);
        tot+=(ls*chp);
        ls*=d;
        sy=ls+sy-dis[i];
        chp=min(chp,v[i]);
    }
    printf("%lld",tot);
    return 0;
}
