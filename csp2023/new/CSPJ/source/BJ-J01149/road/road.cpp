#include <bits/stdc++.h>
using namespace std;
int const N=1e5+10;
long long dis[N],a[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=2;i<=n;i++)
    {
        scanf("%lld",&dis[i]);
        dis[i]+=dis[i-1];
    }
    long long lei=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        lei=min(lei,a[i]);
    }
    long long x=int(ceil((long double)dis[n]/d));
    printf("%lld\n",x*a[1]);

    /*
    for(int i=1;i<=n;i++)
    {
        for(int i=1;i<=n)
        for(int j=1;j<i;j++)
        {
            dp[i][j]=0x3f3f3f3f;
            int len=dis[i]-dis[j-1];
            for(int k=0;k<=j+len;k++)
            {
                dp[i][j]=min(dp[])
            }
        }
    }
    */
    return 0;
}