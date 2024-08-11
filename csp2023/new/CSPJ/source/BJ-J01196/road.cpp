#include<iostream>
using namespace std;
int n,v[10000000],a[10000000],d,h,ans,x;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>=a[x])
        {
            h++;
        }
        else
        {
            ans+=a[x]*h;
            h=1;
            x=i;
        }
    }
    cout<<ans;
    return 0;
}
