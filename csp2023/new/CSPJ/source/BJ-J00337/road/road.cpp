#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a[100010],b[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll i;
    ll n,d,len=0;
    ll pd=1,pd2=1;
    scanf("%lld%lld",&n,&d);
    for(i=1;i<n;i++)
    {
        scanf("%lld",&a[i]);
        len+=a[i];
        if(a[i]%d!=0) pd=0;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
        if(b[i]<b[1]) pd2=0;
    }
    if(pd)
    {
        ll last=b[1],price=0;
        for(i=1;i<n;i++)
        {
            last=min(last,b[i]);
            price+=last*a[i]/d;
        }
        cout<<price<<'\n';
        return 0;
    }
    if(pd2)
    {
        if(len%d==0) cout<<(len/d)*b[1];
        else cout<<(len/d+1)*b[1];
        return 0;
    }
    if(len%d==0)
    {
        cout<<b[1]*(len/d)<<'\n';
        return 0;
    }
    if(len%d!=0)
    {
        cout<<b[1]*(len/d+1)<<'\n';
        return 0;
    }
    return 0;
}
