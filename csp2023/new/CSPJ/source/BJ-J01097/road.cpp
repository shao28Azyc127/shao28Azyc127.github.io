#include <bits/stdc++.h>
using namespace std;

int read()
{
    int x=0,f=1;
    char c=getchar();
    while (!isdigit(c))
    {
        if (c=='-')
        {
            f=-1;
        }
        c=getchar();
    }
    while (isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
const int maxn=1e6+5;
struct node{
    int id,price;
}a[maxn],b[maxn];
int dis,stop[maxn];
int sum[maxn];
int n,d,cnt=0;
int ans=0;
bool cmp(node x,node y)
{
    if (x.price!=y.price)
    {
        return x.price<y.price;
    }
    else
    {
        return x.id>y.id;
    }
}
bool cmp1(int x,int y)
{
    return x<y;
}
signed main()
{
    /*freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);*/
    sum[1]=0;
    n=read();
    d=read();
    for (int i=1;i<n;i++)
    {
        dis=read();
        sum[i+1]=sum[i]+dis;
    }
    for (int i=1;i<=n;i++)
    {
        a[i].id=i;
        a[i].price=read();
    }
    for (int i=1;i<=n;i++)
    {
        b[i]=a[i];
    }
    sort(a+1,a+n,cmp);
    int now=a[1].id;
    if (a[1].id==1)
    {
        double ans1=1.0*sum[n]/d;
        ans1=ceil(ans1);
        cout << int(ans1)*a[1].price;
        return 0;
    }
    while (true)
    {
        cnt++;
        stop[cnt]=now;
        for (int i=1;i<now;i++)
        {
            a[i]=b[i];
        }
        sort(a+1,a+now,cmp);
        now=a[1].id;
        if (now==1)
        {
            cnt++;
            stop[cnt]=now;
            break;
        }
    }
    sort(stop+1,stop+cnt+1,cmp1);
    for (int i=1;i<=cnt;i++)
    {
        cout << sum[stop[i+1]]-sum[stop[i]] << endl;
        ans+=ceil((sum[stop[i+1]]-sum[stop[i]])*1.0/d)*a[stop[i]].price;
    }
    cout << ans;
    return 0;
}
