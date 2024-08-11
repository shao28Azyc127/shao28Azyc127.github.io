#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    ll l,r,v;
}a[1010];
ll c,t,n,m,k,d,sum[1010];
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(ll i=1;i<=m;i++)
        {
            scanf("%lld%lld%lld",&a[i].r,&a[i].l,&a[i].v);
            a[i].l=a[i].r-a[i].l+1;
        }
        ll Ans=0;
        for(ll S=0;S<(1<<n);S++)
        {
            ll s=S,ans=0;
            for(ll i=1;i<=n;i++)
            {
                if(s&1) sum[i]=1,ans-=d;
                else sum[i]=0;
                s>>=1; sum[i]+=sum[i-1];
            }
            bool flag=false;
            for(ll l=1;l+k<=n;l++)
            {
                if(sum[l+k]-sum[l-1]==k+1)
                {
                    flag=true;
                    break;
                }
            }
            if(flag) continue;
            for(ll i=1;i<=m;i++)
            {
                if(sum[a[i].r]-sum[a[i].l-1]==(a[i].r-a[i].l+1))
                    ans+=a[i].v;
            }
            Ans=max(Ans,ans);
        }
        printf("%lld\n",Ans);
    }
    return 0;
}
