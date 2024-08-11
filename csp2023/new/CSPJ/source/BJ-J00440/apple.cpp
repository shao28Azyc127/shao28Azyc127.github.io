#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll n;
    ll cnt=0,cnt2=0;
    scanf("%lld",&n);
    if(n<=3)
    {
        cout<<n<<" "<<n;
        return 0;
    }
    ll t=n;
    ll tt=n;
    ll ans=0;
    while(n)
    {
        if(n%3==0)
        {
            n-=n/3;
            cnt++;
        }
        else
        {
            n-=(n/3+1);
            cnt++;
        }
    }
    printf("%lld ",cnt);
    while(t)
    {
        if(t%3==1)
        {
			printf("%lld",cnt2+1);
            break;
        }
        if(t%3==0)
        {
            t-=t/3;
            cnt2++;
        }
        else
        {
            t-=(t/3+1);
            cnt2++;
        }
    }
    return 0;
}
