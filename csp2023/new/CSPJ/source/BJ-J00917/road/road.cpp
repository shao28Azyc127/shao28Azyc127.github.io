#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N],dist[N],sum[N];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>dist[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+dist[i];
    double left=0;
    int ans=0;
    for(int i=1;i<=n;)
    {
        int j=i;
        for(;j<=n;j++)
            if(a[j]<a[i]) break;
        int distt=sum[j-1]-sum[i-1];
        if(1.0*distt>1.0*left*d)
        {
            ans+=ceil(1.0*(distt-left*d)/d)*a[i];
            int cck=ceil(1.0*(distt-left*d)/d);
            left+=ceil(1.0*(distt-left*d)/d);
        }
        left-=1.0*distt/d;
        i=j;
    }
    cout<<ans;
    return 0;
}
