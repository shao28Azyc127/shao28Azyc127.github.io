#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
ll m,n;
ll a[10];
vector<ll> v[15];
ll t[1000005];
ll p(ll x)
{
    x--;
    ll ret=1;
    while(x)
    {
        ret*=10;
        x--;
    }
    return ret;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>m;
    ll l=0,o=m;
    while(m--)
    {
        l++;
        n=5;
        for(ll i=1;i<=n;i++) cin>>a[i];
        ll sum=0;
        for(ll i=n;i>=1;i--)
        {
            sum*=10;
            sum+=a[i];
        }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=0;j<=9;j++)
            {
                if(a[i]==j) continue;
                v[l].push_back(sum-a[i]*p(i)+j*p(i));
            }
        }
        for(ll i=1;i<n;i++)
        {
            for(ll j=1;j<=9;j++)
            {
                ll k1=(a[i]+j)%10,k2=(a[i+1]+j)%10;
                v[l].push_back(sum-a[i]*p(i)+k1*p(i)-a[i+1]*p(i+1)+k2*p(i+1));
            }
        }
        sort(v[l].begin(),v[l].end());
        t[v[l][0]]++;
        for(ll i=1;i<v[l].size();i++)
        {
            if(v[l][i]!=v[l][i-1]) t[v[l][i]]++;
        }
    }
    ll ans=0;
    for(ll i=0;i<=200000;i++)
    {
        if(t[i]==o) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
