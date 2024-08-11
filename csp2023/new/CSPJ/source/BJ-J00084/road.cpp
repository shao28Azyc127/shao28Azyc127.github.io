#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,d,v[MAXN],a[MAXN],s[MAXN];
int main()

{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&v[i]);
        s[i]=s[i-1]+v[i];
    }
    int minn=1e5;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        minn=min(minn,a[i]);
    }
    if(minn==a[0])
    {
        if(s[n-1]%d==0)printf("%d",s[n-1]/d*minn);
        else printf("%d",(s[n-1]+d-s[n-1]%d)/d*a[0]);
        return 0;
    }
    minn=a[0];
    int y=0,money=0,yy=0;
    for(int i=0;i<n-1;i++)
    {
        if((s[i+1]-y*d)%d==0)y=(s[i+1]-yy*d)/d;
        else y=(s[i+1]-yy*d+d-(s[i+1]-yy*d)%d)/d;
        money+=y*minn;
        minn=min(minn,a[i+1]);
        yy+=y;
    }
    printf("%d",money);
    return 0;
}
