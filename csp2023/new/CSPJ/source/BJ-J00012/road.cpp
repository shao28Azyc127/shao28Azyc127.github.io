#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100050],v[100050],m=LLONG_MAX;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,d,s=0,ans=0;
    cin>>n>>d;
    for(int i=2;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        if(s>v[i+1]) s-=v[i+1];
        else ans+=a[i]*int(ceil((v[i+1]-s)*1.0/d)),s+=int(ceil((v[i+1]-s)*1.0/d))*d-v[i+1];
    }
    cout<<ans;
    return 0;
}
