#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll a[100001],b[100001],h;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,d,y=0,q=0;
    cin>>n>>d;
    for(ll i=1;i<=n-1;i++)
    {
        cin>>a[i];
        h+=a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    /*
    for(ll i=1;i<n;i++)
    {
        ll jl=0;
        bool t=0;
        for(ll j=i+1;j<=n;j++)
        {
            jl+=a[j-1];
            if(b[j]<=b[i])
            {
                if(y*d>=jl)
                {
                    t=1;
                    y=y-a[i]*d;
                    break;
                }
                y=ceil(double(jl)/d);
                q=q+y*b[i];
                y=y-a[i]*d;
                t=1;
                cout<<i<<' '<<ceil(double(jl)/d)<<endl;
                break;
            }
        }
        if(t==0)
        {
            q=q+(ceil(double(c[n-1]-c[i-1])/d-y)*b[i]);
            y=ceil(double(c[n-1]-c[i-1])/d);
        }
    }
    cout<<q<<endl;
    */
    y=ceil(double(h)/d);
    q=y*b[1];
    cout<<q<<endl;
    return 0;
}
