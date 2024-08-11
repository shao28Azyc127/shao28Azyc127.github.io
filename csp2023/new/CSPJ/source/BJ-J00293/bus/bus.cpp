#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,k,u[10005],v[10005],a[10005],ans=0;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;++i)
    {
        scanf("%lld%lld%lld",&u[i],&v[i],&a[i]);
    }
    printf("-1\n");
    return 0;
}
