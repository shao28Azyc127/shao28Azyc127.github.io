#include<iostream>
using namespace std;

typedef long long ll;
const ll MXN=1000010;
ll v[MXN],a[MXN];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,d;cin>>n>>d;
    for(ll i=1;i<n;i++) {cin>>v[i];}
    for(ll i=1;i<=n;i++) cin>>a[i];
    ll nw=0,mn=a[1],ret=0;
    for(ll i=1;i<n;i++)
    {
        mn=min(mn,a[i]);nw-=v[i];
        if(nw>=0) continue;
        ll nd=(-nw+d-1)/d;
        ret+=mn*nd;nw+=nd*d;
    }
    cout<<ret<<endl;return 0;
}