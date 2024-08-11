#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+10;
ll n,d,a[N],b[N];
ll ans,h,x;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    a[0]=1e9;
    for(int i=1;i<n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=min(a[i],a[i-1]);
    }
    for(int i=1;i<n;i++)
    {
        if(h<b[i])
        {
            x=(b[i]-h+d-1)/d;
            ans+=x*a[i];
            h+=x*d;
        }
        h-=b[i];
    }
    cout<<ans;
    return 0;
}

