#include<bits/stdc++.h>
using namespace std;
long long a[100000],v[100000],f[1000000],b[1000000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long i,n,m,sum=0,ans=0;
    cin>>n>>m;
    for(i=1;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    int x=b[1];
    sort(b+1,b+n+1);
    if(b[1]==x)
    {
        ans=ceil(sum/m)*a[1];
        cout<<ans;
        return 0;
    }
    f[1]=v[1]/m*a[1];
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[j]=max(f[i],f[j-v[i]]*a[i]);
        }
    }
    cout<<f[n];
    return 0;
}
