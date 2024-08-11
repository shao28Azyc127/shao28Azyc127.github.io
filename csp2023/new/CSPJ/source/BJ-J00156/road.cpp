#include <iostream>
#include <cmath>
using namespace std;
#define IO_ON_FILE
const int maxn=100005;
int n,d,v[maxn],sum[maxn],a[maxn],mina[maxn];
double l=0;
long long ans=0;
int main()
{
    #ifdef IO_ON_FILE
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    #endif // IO_ON_FILE
    cin>>n>>d;
    sum[1]=0;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
        sum[i+1]=sum[i]+v[i];
    }
    mina[0]=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mina[i]=min(mina[i-1],a[i]);
    }
    for(int i=1;i<=n-1;i++)
    {
        double buy=ceil(max(v[i]-l*d,(double)0)/(d/1.0));
        l=l+buy-v[i]/(d/1.0);
        ans+=buy*mina[i];
    }
    cout<<ans;
    return 0;
}
