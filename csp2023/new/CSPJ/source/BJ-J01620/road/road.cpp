#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n,d,v[100005],a[100005];
long long ans;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n-1;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    long long minn = 2e9,len = 0;
    for(int i=1;i<=n-1;i++)
    {
        if(minn > a[i])
        {
            ans += ceil(len * 1.0 / d) * minn;
            minn = a[i];
            len = len - ceil(len * 1.0 / d) * d;
        }
        len += v[i];
    }
    ans += ceil(len * 1.0 / d) * minn;
    printf("%lld",ans);
    return 0;
}
