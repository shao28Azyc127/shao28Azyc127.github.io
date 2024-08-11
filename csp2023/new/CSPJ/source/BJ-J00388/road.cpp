#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long n,d,len[100020],cost[100020],f[100020],g[100020];
long long high(double x)
{
    int y=x;
    if(x==y)
    {
        return y;
    }
    return y+1;
}
long long dp()
{
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1]+high((len[i-1]-g[i-1])/1.0/d)*cost[min_element(cost+1,cost+i)-cost];
        g[i]=g[i-1]+high((len[i-1]-g[i-1])/1.0/d)*d-len[i];
    }
    return f[n];
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%lld",&len[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&cost[i]);
    }
    printf("%lld",dp());
    return 0;
}