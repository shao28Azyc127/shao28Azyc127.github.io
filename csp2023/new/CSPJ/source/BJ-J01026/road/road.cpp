#include <bits/stdc++.h>

using namespace std;
int n,d,vic=0,sh=0;
long long cnt=0,cnt1=0;
int v[100010];
struct A{
    int m;
    int t;
}a[100010],b[100010];
bool cmp(A x,A y)
{
    return x.m<y.m;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&a[i].m);
        a[i].t=i;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<=n-1;i++)
    {
        b[a[i].t].m=a[i].m;
        b[a[i].t].t=i;
    }
    vic=b[0].m;
    for(int i=0;i<=n-2;i++)
    {
        cnt1+=ceil((1.0*v[i+1]-sh)/d)*vic;
        sh=ceil(1.0*(v[i+1]-sh)/d)*d-v[i+1]+sh;
        if(b[i+1].t<b[i].t) vic=b[i+1].m;

    }
    cout<<cnt1;
    return 0;
}