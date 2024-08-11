#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll a[N],b[N],ta[N],tb[N];
int main()
{
    ios::sync_with_stdio(0);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ll c,n,m,q;
    cin>>c>>n>>m>>q;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        ta[i]=a[i];
    }
    for(ll i=1;i<=m;i++)
    {
        cin>>b[i];
        tb[i]=b[i];
    }
    if(c==1)
    {
        if(a[1]!=b[1])
            cout<<1;
        else
            cout<<0;
    }
    else if(c==2)
    {
        if(a[1]<b[1] && a[2]<b[2] || a[1]>b[1] && a[2]>b[2])
            cout<<1;
        else
            cout<<0;
    }
    else
    {
        cout<<0;
    }
    for(ll i=1;i<=q;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            a[j]=ta[j];
        }
        for(ll j=1;j<=m;j++)
        {
            b[j]=tb[j];
        }
        ll ka,kb;
        cin>>ka>>kb;
        for(ll j=1;j<=ka;j++)
        {
            ll p,v;
            cin>>p>>v;
            a[p]=v;
        }
        for(ll j=1;j<=kb;j++)
        {
            ll p,v;
            cin>>p>>v;
            b[p]=v;
        }
        if(c==1)
        {
            if(a[1]!=b[1])
                cout<<1;
            else
                cout<<0;
        }
        else if(c==2)
        {
            if(a[1]<b[1] && a[2]<b[2] || a[1]>b[1] && a[2]>b[2])
                cout<<1;
            else
                cout<<0;
        }
        else
        {
            cout<<0;
        }
    }
    cout<<endl;
    return 0;
}
