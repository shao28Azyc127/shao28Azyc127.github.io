#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
long long a[100010],b[100010],c[100010];
int n;
bool check1(long long mid)
{
    for(int i=1;i<=n;i++)
    {
        long long hi=max((b[i]+c[i]*mid)*(n-i+1+mid),mid);
        if(hi<0)hi=1e18;
        if(hi<a[i])return 0;
    }
    return 1;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
    }
    long long l=n,r=1e18,ans=0;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check1(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}