#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5+10;
int n,d;
int v[N],a[N],ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
        ans+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ans+=d;
    ans-=1;
    ans/=d;
    ans*=a[1];
    cout<<ans;
    return 0;
}