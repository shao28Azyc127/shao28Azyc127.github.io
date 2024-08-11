#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,m,k;
long long d;
struct Node
{
    int x,y;
    long long v;
    inline bool operator<(const Node &a)const
    {
        return x<a.x;
    }
}a[N];
long long dp[N];
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--)
    {
        scanf("%d %d %d %lld",&n,&m,&k,&d);
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d %lld",&a[i].x,&a[i].y,&a[i].v);
        }
        sort(a+1,a+m+1);
        for(int i=1;i<=m;i++)
        {
            if(a[i].x>=a[i].y)dp[i]=a[i].v-a[i].y*d;
        }
        for(int i=1;i<=m;i++)
        {
            int x1=a[i].x,y1=a[i].y,x2,y2;
            for(int j=1;j<i;j++)
            {
                x2=a[j].x,y2=a[j].y;
                if(x1-x2>y1&&y1<=k)
                {
                    dp[i]=max(dp[i],dp[j]-y1*d+a[i].v);
                }else if(x1-x2+y2<=k)
                {
                    dp[i]=max(dp[i],dp[j]-(x1-x2)*d+a[i].v);
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=m;i++)
        {
            ans=max(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
