#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll v[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,d,m=1e9,s=0,ans=0;
    scanf("%lld%lld",&n,&d);
    for(ll i=1;i<n;i++){
        scanf("%lld",&v[i]);
    }
    for(ll i=1;i<=n;i++){
        ll a;
        scanf("%lld",&a);
        if(i==n){
            break;
        }
        m=min(m,a);
        ans+=((v[i]-s-1)/d+1)*m;
        s=s+(v[i]-s-1)/d*d+d-v[i];
    }
    printf("%lld",ans);
    return 0;
}
