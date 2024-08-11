#include <algorithm>
#include <cstdio>
using namespace std;
long long n,d,sum,minn=99999999;
long long a[10005],v[10005],p[10005];

void dfs(long long u)
{
    if(u>=n)
    {
        minn=min(sum,minn);
        return;
    }
    for(long long i=u+1;i<=n;i++)
    {
        long long jl=p[i-1]-p[u-1];
        long long o=0;
        if(jl%d!=0) o=jl/d+1;
        else o=jl/d;
        sum+=o*a[i-1];
        dfs(i);
        sum-=o*a[i-1];
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld",&n,&d);
    for(long long i=1;i<n;i++)
    {
        scanf("%lld",&v[i]);
        p[i]=p[i-1]+v[i];
    }
    for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
    dfs(1);
    printf("%lld",minn);
    return 0;
}