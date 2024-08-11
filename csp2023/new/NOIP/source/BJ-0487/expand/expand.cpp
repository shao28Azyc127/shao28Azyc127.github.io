#include<bits/stdc++.h>
#define debug printf("debug\n")
using namespace std;
typedef long long i64;
const int N=5e5+5;
const int inf=0x3f3f3f3f;
int c,n,m,q,x[N],y[N],kx,ky,p,v,tar,lft,rht;
int ans[100],cnt;
bool check()
{
    if(n==1)
    {
        if(x[1]!=y[1])return 1;
        else return 0;
    }
    if(n==2&&m==2)
    {
        if(x[1]-y[1]>0&&x[1]-y[2]>0&&x[2]-y[1]>0&&x[2]-y[2]>0)return 1;
        if(x[1]-y[1]<0&&x[1]-y[2]<0&&x[2]-y[1]<0&&x[2]-y[2]<0)return 1;
        return 0;
    }
    if(n==1&&m==2)
    {
        if(x[1]-y[1]>0&&x[1]-y[2]>0)return 1;
        if(x[1]-y[1]<0&&x[1]-y[2]<0)return 1;
        return 0;
    }
    if(n==2&&m==1)
    {
        if(x[1]-y[1]>0&&x[2]-y[1]>0)return 1;
        if(x[1]-y[1]<0&&x[2]-y[1]<0)return 1;
        return 0;
    }
    return 0;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);int Q=q;
    for(int i=1;i<=n;++i)scanf("%d",x+i);
    for(int i=1;i<=m;++i)scanf("%d",y+i);
    ans[++cnt]=check();
    while(q--)
    {
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;++i)
        {
            scanf("%d%d",&p,&v);
            x[p]=v;
        }
        for(int i=1;i<=ky;++i)
        {
            scanf("%d%d",&p,&v);
            y[p]=v;
        }
        ans[++cnt]=check();
    }
    if(n<=2&&m<=2)for(int i=1;i<=cnt;++i)printf("%d",ans[i]);
    else{
        for(int i=1;i<=Q+1;++i)cout<<"0";
    }
    return 0;
}
