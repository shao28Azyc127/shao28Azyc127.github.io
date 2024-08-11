#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N],v[N],n,d;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(ll i=1;i<n;i++)
    {
        cin>>v[i];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll sum=0,minn=1e18,ans=0,m=0;
    for(ll i=1;i<=n;i++)
    {
        if(minn>a[i])
        {
            ll k=sum-m;
            if(k%d==0)
            {
                ans+=(minn*(k/d));
                m=0;
            }
            else
            {
                ans+=(minn*(k/d+1));
                m=(k/d+1)*d-k;
            }
            minn=a[i];
            sum=0;

        }
        if(i<n) sum+=v[i];
    }
    if(a[n]>=minn)
    {
        ll k=sum-m;
        if(k%d==0)
        {
            ans+=(minn*(k/d));
            m=0;
        }
        else
        {
            ans+=(minn*(k/d+1));
            m=(k/d+1)*d-k;
        }
    }
    cout<<ans<<endl;
    return 0;
}
