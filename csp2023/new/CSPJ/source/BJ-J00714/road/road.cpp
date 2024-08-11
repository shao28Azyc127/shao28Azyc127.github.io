#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,d,v[N],a[N],i;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(i=1;i<n;i++){
        scanf("%lld",&v[i]);
    }
    ll pre=1e9,ans=0,s=0;
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=1;i<n;i++){
        pre=min(pre,a[i]);
        if(s>=v[i]){
            s-=v[i];
            continue;
        }
        ans+=((v[i]-s)/d+((v[i]-s)%d!=0))*pre;
        s=((v[i]-s)/d+((v[i]-s)%d!=0))*d-v[i];
    }
    printf("%lld",ans);
    return 0;
}