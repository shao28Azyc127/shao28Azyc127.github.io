// ¹Ø×¢ÓÀ³ûËþ·Æß÷£¬¹Ø×¢ÓÀ³ûËþ·ÆÐ»Ð»ß÷£¡

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll chk1(ll a)
{
    ll ans=0;
    while(a)
    {
        a-=ceil(a*1.0/3.0);
        ans++;
    }
    return ans;
}
ll chk2(ll a)
{
    ll now=a;
    ll cnt=0;
    while(a)
    {
        cnt++;
        ll minu=ceil(a*1.0/3.0);
        a-=minu;
        if(now%3==1)
        {
            return cnt;
        }
        now-=minu;
    }
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    long long ans1=chk1(n),ans2=chk2(n);
    printf("%lld %lld\n",ans1,ans2);
    return 0;
}
