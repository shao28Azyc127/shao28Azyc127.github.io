#include <iostream>
using namespace std;
#define M 100005
#define MAXN 100000000000000000
typedef long long ll;
ll n,d,dist[M],distqzh[M],pric[M],dissum;
ll f[M],yu[M];
bool flag1;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    flag1=1;
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++)
    {
        scanf("%lld",&dist[i]);
        dissum+=dist[i];
        distqzh[i]=distqzh[i-1]+dist[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&pric[i]);
        if(pric[i]<pric[1])flag1=0;

        f[i]=MAXN;
    }
    if(flag1)
    {
        printf("%lld",((dissum-1)/d+1)*pric[1]);
        return 0;
    }
    f[1]=0;
    for(int i=2;i<=n;i++)
    {
        yu[i]=(distqzh[i-1]%d==0)?0:(d-distqzh[i-1]%d);
        for(int j=i;j<=n;j++)
        {
            f[j]=min(f[j],f[i-1]+((distqzh[j-1]-distqzh[i-2]-yu[i-1]-1)/d+1)*pric[i-1]);
        }
    }
    printf("%lld",f[n]);
    return 0;
}
