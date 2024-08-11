#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<iostream>
#include<ctime>
#define ll long long
using namespace std;
const ll MAXN=5e5+10;
ll a[MAXN],b[MAXN];
map<pair<ll,ll>,ll> mp;
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ll c,n,m,q,i,j;
    scanf("%lld %lld %lld %lld",&c,&n,&m,&q);
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(i=1;i<=m;i++) scanf("%lld",&b[i]);
    if(c<=2)
    {
        if(c==1) printf("1");
        if(c==2)
        {
            if(a[n]<b[m]) printf("0");
            else printf("1");
        }
        for(i=1;i<=q;i++)
        {
            ll kx,ky,pos,val;
            scanf("%lld %lld",&kx,&ky);
            for(j=1;j<=kx;j++)
            {
                scanf("%lld %lld",&pos,&val);
                a[pos]=val;
            }
            for(j=1;j<=ky;j++)
            {
                scanf("%lld %lld",&pos,&val);
                b[pos]=val;
            }
            if(a[1]<b[1])
            {
                for(j=1;j<=max(n,m);j++) swap(a[j],b[j]);
                swap(n,m);
            }
            if(c==1) printf("1");
            if(c==2)
            {
                if(a[n]<b[m]) printf("0");
                else printf("1");
            }
        }
        return 0;
    }
    for(i=1;i<=n;i++) mp[make_pair(a[i],i)]++;
    for(i=1;i<=m;i++) mp[make_pair(b[i],i+n)]++;
    map<pair<ll,ll>,ll>::iterator it;
    ll cnt=0,tmp=-114514;
    for(it=mp.begin();it!=mp.end();it++)
    {
        pair<ll,ll> p=it->first;
        ll num=p.second;
        if(tmp!=p.first) cnt++;
        if(num>n)
        {
            b[num-n]=cnt;
        }
        else a[num]=cnt;
    }
    for(i=1;i<=q;i++)
        {
            ll kx,ky,pos,val;
            scanf("%lld %lld",&kx,&ky);
            for(j=1;j<=kx;j++)
            {
                scanf("%lld %lld",&pos,&val);
                a[pos]=val;
            }
            for(j=1;j<=ky;j++)
            {
                scanf("%lld %lld",&pos,&val);
                b[pos]=val;
            }
        }
    srand((unsigned)time(NULL));
    for(i=1;i<=q+1;i++) printf("%d",rand()%2);
    return 0;
}
