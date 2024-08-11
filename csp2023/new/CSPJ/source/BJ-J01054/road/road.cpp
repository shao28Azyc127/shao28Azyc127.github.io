#include <bits/stdc++.h>
using namespace std;
int price[114514],dis[114514],dissum[114514];
#define ll long long
int i,j,k;
ll disall,m,oil,km,n,d;
ll min(ll a,ll b)
{
    if (a>b) return b;
    return a;
}
int main()
{
    freopen("road.in" ,"r" ,stdin);
    freopen("road.out","w",stdout);

    scanf("%lld%lld",&n,&d);
    dissum[0]=0;
    for (i=1;i<=n-1;i++)
    {
        scanf("%d",&dis[i]);
        dissum[i]=dissum[i-1]+dis[i];
    }
    for (i=1;i<=n;i++) scanf("%d",&price[i]);
    i=1,j=0,k=0,disall=0,m=0,oil=0,km=0;

    while (i<=n)
    {
        j=i;
        while (price[j]>=price[i]&&j<=n)
        {
            //printf("'PRICER':%d!!!!\n",price[j]);
            j++;
        }
        disall=dissum[min(n-1,j-1)]-dissum[min(n-1,i-1)];
        //printf("'FIRSTEST DISALLLLLL!!!!!!!':%lld\n",disall);
        //printf("%lld ",disall);
        if (disall-km>=0)
        {

            disall-=km;
            oil=disall/d;
            if (disall%d) oil++;
            m+=oil*price[i];
            km=oil*d-disall;
            //printf("%lld %lld %d J\n",oil*price[i],km,j);
            disall=0;
            i=j;
            if (i>=n) break;
        }
        else
        {
            k=i;
            while (k<=n&&disall<=km)
            {
                disall+=dis[k];
                //printf("'DISALL!!!':%lld\n",disall);
                k++;
            }
            if (disall<=km) oil=0;
            else
            {
                disall-=km;
                oil=disall/d;
                if (disall%d) oil++;
            }
            m+=oil*price[i];
            km=oil*d-disall;
            //printf("%lld %lld %d K\n",oil*price[i],km,k);
            disall=0;
            i=k;
            if (i>=n) break;
        }

    }
    printf("%lld",m);
    return 0;
}
