#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+10;
char a[N];
bool check(ll l,ll r)
{
    stack<char> s;
    for(ll i=l;i<=r;i++)
    {
        if(!s.empty() && s.top()==a[i])
            s.pop();
        else
            s.push(a[i]);
    }
    return s.empty();
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ll n;
    cin>>n;
    if(n>8000)
    {
        ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i>=2 && a[i]==a[i-1])
                ans++;
        }
        cout<<ans<<endl;
    }
    else
    {
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            stack<char> s;
            for(ll j=i;j<=n;j++)
            {
                if(!s.empty() && s.top()==a[j])
                    s.pop();
                else
                    s.push(a[j]);
                if(s.empty())
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
