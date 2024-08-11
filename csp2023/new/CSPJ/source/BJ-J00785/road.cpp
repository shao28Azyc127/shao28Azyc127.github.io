#include<bits/stdc++.h>
using namespace std;
int n,k,u[100001],sy,ans,d=9999999,a[100001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        cin>>u[i];
    }
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        d=min(d,a[i]);
        if((u[i]-sy)%k==0)
        {
            ans+=(u[i]-sy)/k*d;
            sy+=(u[i]-sy)/k*k-u[i];
        }
        else
        {
            ans+=((u[i]-sy)/k+1)*d;
            sy+=((u[i]-sy)/k+1)*k-u[i];
        }
    }
    cout<<ans;
    return 0;
}
