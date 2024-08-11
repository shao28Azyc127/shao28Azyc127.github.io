#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,a[1000010],v[1000010],minx=1e9,k,ans,vis[1000010],dis[100010],sum=1e9;

ll Find(ll cur)
{
    if(cur==n-1)
    {
        vis[1]=1;
        ans=0;
        for(ll i=1;i<n;i++)
        {
            if(vis[i]==1)
            {
                ans+=a[i]*dis[i];
            }
            else
            {
                ll j=i;
                while(vis[j]==0)
                {
                    j--;
                }
                ans+=a[j]*dis[i];
            }
        }
        sum=min(ans,sum);
        return sum;
    }
    for(ll i=0;i<=1;i++)
    {
        vis[cur]=i;
        Find(cur+1);
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>k;
    if(n!=1)
    {
        for(ll i=1;i<n;i++)
        {
            cin>>v[i];
            ans+=v[i];
        }
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            minx=min(minx,a[i]);
        }
        if(minx==a[1])
        {
            if(ans%k==0)
                cout<<ceil(ans/k)*a[1]<<endl;
            else
                cout<<(ans/k+1)*a[1]<<endl;
            return 0;
        }
        else
        {
            for(ll i=1;i<n;i++)
            {
                if(v[i]%k==0)
                    dis[i]=v[i]/k;
                else
                     dis[i]=v[i]/k+1;
            }
            ans=Find(2);
            cout<<ans<<endl;
            return 0;
        }
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;
}
