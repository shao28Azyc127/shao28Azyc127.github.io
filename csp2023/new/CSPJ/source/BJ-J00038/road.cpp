#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+6;
int n,a[N],v[N],d;
int f[N],g[N],x[N];
signed main()
{
    freopen("road.in","w",stdin);
    freopen("road.out","r",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++)  cin>>v[i];
    for(int i=1;i<=n;i++)  cin>>a[i];
    f[1]=0;
    g[1]=a[1];
    x[1]=0;
    for(int i=2;i<=n;i++)
    {
        g[i]=min(g[i-1],a[i]);
        v[i]-=x[i-1];
        x[i]=((v[i]-1)/d+1)*d-v[i];
        f[i]=f[i-1]+g[i-1]*((v[i]-1)/d+1);
    }
    cout<<f[n]<<endl;
    return 0;
}
