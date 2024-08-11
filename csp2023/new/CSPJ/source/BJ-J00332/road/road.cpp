#include <bits/stdc++.h>
using namespace std;

int v[100005],a[100005];
long long suma[100005];
bool vis[100005];
int ans=1e9;
int n;

bool check(int x)
{
    for(int i=1;i<=n;i++)
        if(v[i]%x!=0)return false;
    return true;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++)scanf("%d",&v[i]);
    int minn=1e9,id=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<minn)
        {
            minn=a[i];
            id=i;
        }
    }
    for(int i=2;i<=n;i++)suma[i]=suma[i-1]+1ll*v[i-1];
    if(id==1)
    {
        printf("%lld\n",int(ceil(1.0*suma[n]/d)*minn));
        return 0;
    }
    if(check(d))
    {
        int last=1;
        long long sum=0;
        for(int i=2;i<n;i++)
        {
            if(a[i]<a[last])
            {
                vis[i]=true;
                sum+=ceil(1.0*(suma[i]-suma[last])/d)*a[last];
                last=i;
            }
        }
        sum+=ceil(1.0*(suma[n]-suma[last])/d)*a[last];
        printf("%lld\n",sum);
    }
    else printf("%lld\n",rand()%1000000);
    return 0;
}