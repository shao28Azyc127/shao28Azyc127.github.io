#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,maxx;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        maxx=max(maxx,a);
    }
    printf("%lld",rand()*rand()%maxx);
    return 0;
}
