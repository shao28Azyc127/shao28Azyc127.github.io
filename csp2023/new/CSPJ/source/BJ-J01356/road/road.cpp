#include <bits/stdc++.h>
using namespace std;
int a[100001],v[100001],sum[100001],n,d,ans,minn=1<<30,minbianhao,minnn=1<<30;
int jinyifa(int a)
{
    if (a%d==0)
        return a/d;
    return a/d+1;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=1;i<n;i++)
    {
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        minnn=min(minnn,a[i]);
    }
    if (minnn==a[1])
    {
        cout<<a[1]*jinyifa(sum[n-1]);
        return 0;
    }
    minn=a[1];
    for (int i=2;i<=n;i++)
    {
        ans+=(v[i-1]/d)*minn;
        minn=min(minn,a[i]);
    }
    cout<<ans;
}