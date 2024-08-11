#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
ll solve(ll n)
{
    if(n<=3)
    {
        return n;
    }
    return solve(n-(n%3==0?n/3:n/3+1))+1;
}
ll solve2(ll n)
{
    if(n%3==1)
    {
        return 1;
    }
    return solve2(n-(n%3==0?n/3:n/3+1))+1;
}
int main()
{
    freopen("apple.in","w",stdin);
    freopen("apple.out","r",stdout);
    ll n;
    cin>>n;
    ll ans=solve(n);
    cout<<ans<<" ";
    ll ans2=solve2(n);
    cout<<ans2;
    return 0;
}
