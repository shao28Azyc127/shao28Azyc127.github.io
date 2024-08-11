#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100010],b[100010],c[100010];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    ll x,y,z; scanf("%lld%lld%lld",&x,&y,&z);
    ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            ll day=i,h=max(b[i]+c[i]*day,1ll);
            while(h<a[i])
            {
                day++;
                h+=max(b[i]*day+c[i]*day,1ll);
            }
            ans=max(ans,day);
        }
        printf("%lld",ans);
    return 0;
}
