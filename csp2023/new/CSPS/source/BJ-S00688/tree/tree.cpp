#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int N=1e5+10;
typedef long long LL;

int n;
LL a[N],b[N],c[N],d[N];
struct EDGE{
    int to,next;
}edge[N<<1];
int head[N],tot;
void add(int from,int to)
{
    edge[++tot]=(EDGE){to,head[from]};
    head[from]=tot;
}

bool check(LL t,LL x,LL y,LL z)
{
    LL pos=1LL*((double)(1-y)/z);
    if(z>0)
    {
        if(t<=pos) return t>=x;
        x-=pos;
        LL start=y+z*(pos+1);
        t-=pos;
        return t*(2*start+z*(t-1))/2>=x;
    }
    else
    {
        if(t<=pos) return (2*y+(t+1)*z)*t/2>=x;
        x-=(2*y+(pos+1)*z)*pos/2;
        t-=pos;
        return t>=x;
    }
}

LL calc(LL x,LL y,LL z,LL day)
{
    if(z==0)
    {
        return ceil((double)x/max(y,1LL));
    }
    LL l=0,r=1LL*1e9,mid;
    while(l+1!=r)
    {
        // printf("%lld %lld\n",l,r);
        mid=(l+r)>>1;
        if(check(mid,x,y+(day-1)*z,z)) r=mid;
        else l=mid;
    }
    return r;
}

int fa[N],son[N];

void dfs(int u,int father)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        son[u]=v;
        fa[v]=u;
        dfs(v,u);
    }
}

int idx[N];

bool cmp(int x,int y)
{
    return d[x]>d[y];
}

bool vis[N];

bool checkk(LL mid)
{
    int cur=1;
    for(int i=1;i<=n;i++) vis[i]=0;
    vis[1]=1;
    for(int i=1;i<=n;i++)
    {
        int u=idx[i];
        while(!vis[u])
        {
            cur++;
            vis[u]=1;
            u=fa[u];
        }
        if(cur>mid-d[idx[i]]+1) return 0;
    }
    return 1;
}


int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        d[i]=calc(a[i],b[i],c[i],1);
        // printf("%lld\n",d[i]);
    }
    bool flag1=1,flag2=1,flag3=1;
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
        if(u!=i||v!=i+1) flag1=0;
    }
    if(flag1)
    {
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,calc(a[i],b[i],c[i],i)+i-1);
        }
        printf("%lld",ans);
        return 0;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) idx[i]=i;
    sort(idx+1,idx+1+n,cmp);
    LL l=0,r=1e9,mid;
    while(l+1!=r)
    {
        mid=(l+r)>>1;
        if(checkk(mid)) r=mid;
        else l=mid;
    }
    printf("%lld",r);
    return 0;
}