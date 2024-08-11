#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i];
    }
    b[0]=1e9;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        b[i]=min(b[i-1],b[i]);
    }
    int t=0,ans=0;
    for(int i=1;i<=n-1;i++)
    {
        ans+=(a[i]-t)/d*b[i];
        t+=(a[i]-t)/d*d;
        if(t<a[i])
        {
            ans+=b[i];
            t+=d;
        }
        t-=a[i];
    }
    cout<<ans;
    return 0;
}
