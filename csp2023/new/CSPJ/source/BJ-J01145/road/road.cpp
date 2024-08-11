#include <iostream>
using namespace std;
#define int long long
const int N=1e5+5;
int n,d;
int v[N],a[N];
int ans,nowr,nowg,minx=1e9;
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int i,j;
    scanf("%lld%lld",&n,&d);
    for(i=1; i<n; i++)
        scanf("%lld",&v[i]);
    for(i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    for(i=1; i<=n; i++)
    {
        nowr+=v[i-1];
        int temp=nowr/d;
        if(nowr%d!=0)
            temp++;
        ans+=(temp-nowg)*minx;
        nowg=temp;
        minx=min(minx,a[i]);
    }
    printf("%lld",ans);
    return 0;
}
