#include<bits/stdc++.h>
using namespace std;
long long f[100005];
long long v[100005];
long long a[100005];
long long z[100005];
long long ans[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long i,j,n,m,k,s=0,x,y,l,r,o,mx,md,ms,mk;
    cin>>n>>m;
    for(i=1;i<n;i++)
    {
        cin>>v[i];
        ans[i]=ans[i-1]+v[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    f[1]=0;
    z[1]=0;
    mk=1;
    f[2]=a[1]*(long long)(ceil(v[1]*1.0/m));
    z[2]=f[2]/a[1]*m-v[1];
    if(a[mk]>a[2])
    {
        mk=2;
    }
    for(i=3;i<=n;i++)
    {
        j=mk;
        s=ans[i-1]-ans[j-1];
        md=j;
        ms=s;
        mx=a[j]*(long long)(ceil((s-z[j])*1.0/m))+f[j];
        f[i]=mx;
        z[i]=(f[i]-f[md])/a[md]*m+z[md]-ms;
        if(a[mk]>a[i])
        {
            mk=i;
        }
    }
    cout<<f[n];
    return 0;
}