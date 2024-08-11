#include<bits/stdc++.h>
using namespace std;

int n,k,v[100005],a[100005];
//we have dpl[i] oil to arrive at i stop
//dpl[i] means we use the cheapest price to arrive at i stop
long long dpl[100005],dpa[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //n<=10^5 so that we have to use scanf and printf
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&v[i]);
        v[i]+=v[i-1];
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)
    {
        long long sav=(v[i]+k-1)/k;
        dpa[i]=sav*a[1];
        dpl[i]=sav*k-v[i];
        for(int j=2;j<i;j++)
        {
            long long l=(v[i]-v[j]-dpl[j]+k-1)/k;
            long long pri=l*a[j];
            long long sl=l*k-(v[i]-v[j]-dpl[j]);
            if(dpa[i]>dpa[j]+pri)
            {
                dpa[i]=dpa[j]+pri;
                dpl[i]=sl;
            }
        }
    }
    /*for(int i=1;i<=n;i++)
        printf("%ld %ld\n",dpa[i],dpl[i]);*/
    printf("%ld",dpa[n]);
    return 0;
}