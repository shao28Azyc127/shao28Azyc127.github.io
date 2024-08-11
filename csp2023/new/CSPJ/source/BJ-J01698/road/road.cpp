#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll N=1e5;
ll n,d,v[N+5],a[N+5],now=1,ans,rem;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(ll i=1;i<=n-1;i++) scanf("%lld",&v[i]);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(;now<n;)
    {
        ll j=now,res=0;
        while(a[j]>=a[now]&&j<=n)
        {
            res+=v[j];
            j++;
        }
        res=res-rem;
        if(res%d==0)
        {
            ans+=a[now]*(res/d);
        }
        else
        {
            ans+=a[now]*(res/d+1),rem=(res/d+1)*d-res;
        }
        now=j;
    }
    printf("%lld",ans);
    return 0;
}
