#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],s1,s2;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d",&v[i]);
        s1+=v[i];
    }

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    s2=ceil(1.0*s1/d)*a[1];
    printf("%d",s2);
    return 0;
}
