#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
const int maxn=105;
int C,T;
LL n,m,k,w,ans;
struct node
{
    LL x,y,v;
}a[maxn];

void dfs(LL d,LL dd,LL res,LL top)
{
    while(top<=m&&a[top].x<=d)
    {
        if(dd>=a[top].y)
            res+=a[top].v;
        top++;
    }
    if(d==n)
    {
        ans=max(ans,res);
        return;
    }
    if(dd<k) dfs(d+1,dd+1,res-w,top);
    dfs(d+1,0,res,top);
}

bool cmp(node x,node y)
{
    return x.x<y.x;
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--)
    {
        ans=0;
        scanf("%lld%lld%lld%lld",&n,&m,&k,&w);
        for(int i=1;i<=m;i++)
        {
            int x,y,v;
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v);
        }
        sort(a+1,a+1+m,cmp);
        if(k>=1) dfs(1,1,-w,1);
        dfs(1,0,0,1);
        printf("%lld\n",ans);
    }
    return 0;
}
