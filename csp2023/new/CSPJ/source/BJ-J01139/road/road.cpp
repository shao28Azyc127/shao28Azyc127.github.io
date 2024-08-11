#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int v[N],a[N],n,d,minn = 0x7fffffff,q,sum;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    int tmp = 0;
    for(int i = 1;i<=n-1;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum%d == 0) tmp = sum/d;
    else tmp = sum/d+1;
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        if(v[i]<minn) minn = v[i],q = i;
    }
    if(q == 1)
    {
        printf("%d",tmp*minn);
        return 0;
    }
    return 0;
}
