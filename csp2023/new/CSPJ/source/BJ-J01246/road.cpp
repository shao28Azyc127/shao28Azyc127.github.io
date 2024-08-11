#include<bits/stdc++.h>
using namespace std;
long long a[100010],c[100010];
long long qz[100010];
long long st[100010][20];
long long n,d,cost=0,run=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    qz[0]=0,a[0]=0,c[0]=0;
    for(long long i=2;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        qz[i]=qz[i-1]+a[i];
    }
    for(long long i=1;i<=n;i++) scanf("%lld",&c[i]);
    long long minx=c[1];
    for(int i=1;i<=n;i++)
    {
        if(run<qz[i])
        {
            long long newdis=(qz[i]-run);
            long long newget=0;
            if(newdis%d)
            {
                newget=newdis/d+1;
                run+=newget*d;
                cost+=newget*minx;
            }
            else
            {
                newget=newdis/d;
                run+=newdis;
                cost+=newget*minx;
            }
            if(i!=n)
            {
                minx=min(minx,c[i]);
            }
        }
    }
    cout<<cost<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}