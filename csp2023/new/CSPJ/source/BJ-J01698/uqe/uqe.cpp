#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
const ll M=1e3;
ll t,m,a,b,c,d;
map<ll,ll> mp;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void print(ll x,ll y)
{
    ll g=gcd(x,y);
    x=x/g,y=y/g;
    if(y==1) printf("%lld",x);
    else printf("%lld/%lld",x,y);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&t,&m);
    for(ll i=1;i<=(ll)(1e3);i++)
    {
        mp[i*i]=i;
        for(ll j=2;i*i*j<(ll)(1e6)&&j<i*i;j++)
            mp[i*i*j]=i;
    }
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        d=b*b-4*a*c;
        ll t=mp[d];
        if(d<0)
        {
            printf("NO\n");
            continue;
        }
        if(d==0||t*t==d)
        {
            print(-b+t,2*a);
            continue;
        }
        if(b!=0)
        {
            print(-b,2*a);
            printf("+");
        }
        if(t/2/a==1)
        {
            printf("sqrt(%lld)",d);
        }
        else if(t%(2*a)==0)
        {
            printf("%lld*sqrt(%lld)",t/(2*a),d);
        }
        else if(t==1)
        {
            printf("sqrt(%lld)/%lld",d,2*a);
        }
        else
        {
            ll g=gcd(t,2*a);
            ll x=t/g,y=2*a/g;
            printf("%lld*sqrt(%lld)/%lld",x,d,y);
        }
        printf("\n");
    }
    return 0;
}
