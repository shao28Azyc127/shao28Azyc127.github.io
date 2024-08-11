#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll d;
ll a[100005];
ll v[100005];
ll pre[100005];
ll ans;
ll nowtank=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        pre[i+1]=pre[i]+v[i];
    }
   // for(int i=1;i<=n;i++)
    //{
    //    cout<<pre[i]<<" ";
    //}
   // cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll nowpoint=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[nowpoint])
        {
            ll toadd=ceil((pre[i]-pre[nowpoint]-nowtank)*1.0/d);
            ans+=toadd*a[nowpoint];
            nowtank=nowtank+toadd*d;
            nowtank-=pre[i]-pre[nowpoint];
            nowpoint=i;
        }
       // cout<<nowpoint<<"\n";
    }
    if(nowpoint!=n)
    {
        ll toadd=ceil((pre[n]-pre[nowpoint]-nowtank)*1.0/d);
        ans+=toadd*a[nowpoint];
    }
    cout<<ans;
    return 0;
}
