#include <bits/stdc++.h>
using namespace std;

const int NR=1e5+5e4+100;
int f[NR],x[NR],y[NR],prex[NR],prey[NR],mp[NR],cnt;
struct tree1
{
    int lc[50*NR],rc[50*NR],sum[50*NR],root[50*NR],cnt;
    void build(int &now,int l,int r)
    {
        now=++cnt,sum[now]=1e9;
        if(l==r) return ;
        int mid=(l+r)/2;
        build(lc[now],l,mid);
        build(rc[now],mid+1,r);
    }
    void insert(int &now,int pre,int l,int r,int x,int p)
    {
        now=++cnt,lc[now]=lc[pre],rc[now]=rc[pre],sum[now]=min(sum[pre],p);
        //printf("insert %d %d %d %d\n",now,l,r,sum[now]);
        if(l==r) return ;
        int mid=(l+r)/2;
        if(x<=mid) insert(lc[now],lc[pre],l,mid,x,p);
        else insert(rc[now],rc[pre],mid+1,r,x,p);
    }
    int query(int now,int l,int r,int x)
    {
        if(l==r) return sum[now];
        int mid=(l+r)/2;
        if(x<=mid) return min(query(lc[now],l,mid,x),sum[rc[now]]);
        else return query(rc[now],mid+1,r,x);
    }
}t1;

struct tree2
{
    int lc[50*NR],rc[50*NR],sum[50*NR],root[50*NR],cnt;
    void build(int &now,int l,int r)
    {
        now=++cnt,sum[now]=0;
        if(l==r) return ;
        int mid=(l+r)/2;
        build(lc[now],l,mid);
        build(rc[now],mid+1,r);
    }
    void insert(int &now,int pre,int l,int r,int x,int p)
    {
        now=++cnt,lc[now]=lc[pre],rc[now]=rc[pre],sum[now]=max(sum[pre],p);
        if(l==r) return ;
        int mid=(l+r)/2;
        if(x<=mid) insert(lc[now],lc[pre],l,mid,x,p);
        else insert(rc[now],rc[pre],mid+1,r,x,p);
    }
    int query(int now,int l,int r,int x)
    {
        if(l==r) return sum[now];
        int mid=(l+r)/2;
        if(x<=mid) return query(lc[now],l,mid,x);
        else return max(query(rc[now],mid+1,r,x),sum[lc[now]]);
    }
}t2;

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q,pren,prem;
    scanf("%d%d%d%d",&c,&n,&m,&q);
    pren=n,prem=m;
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=m;i++) scanf("%d",&y[i]);
    for(int i=1;i<=n;i++) prex[i]=x[i];
    for(int i=1;i<=m;i++) prey[i]=y[i];
    for(int t=0;t<=q;t++)
    {
        n=pren,m=prem;
        if(t!=0)
        {
            int kx,ky;
            scanf("%d%d",&kx,&ky);
            for(int i=1;i<=n;i++) x[i]=prex[i];
            for(int i=1;i<=m;i++) y[i]=prey[i];
            for(int i=1;i<=kx;i++)
            {
                int u,v;
                scanf("%d%d",&u,&v);
                x[u]=v;
            }
            for(int i=1;i<=ky;i++)
            {
                int u,v;
                scanf("%d%d",&u,&v);
                y[u]=v;
            }
        }
        if(x[1]>y[1]&&x[n]>y[m]) ;
        else if(x[1]<y[1]&&x[n]<y[m])
        {
            swap(x,y);
            swap(n,m);
        }
        else
        {
            printf("0");
            continue;
        }
        int cnt=0;
        for(int i=1;i<=n;i++) mp[++cnt]=x[i];
        for(int i=1;i<=m;i++) mp[++cnt]=y[i];
        sort(mp+1,mp+cnt+1);
        cnt=unique(mp+1,mp+cnt+1)-mp-1;
        for(int i=1;i<=n;i++) x[i]=lower_bound(mp+1,mp+cnt+1,x[i])-mp;
        for(int i=1;i<=m;i++) y[i]=lower_bound(mp+1,mp+cnt+1,y[i])-mp;
        /*for(int i=1;i<=n;i++) printf("%d ",x[i]);
        puts("");
        for(int i=1;i<=m;i++) printf("%d ",y[i]);
        puts("");*/
        t1.cnt=0,t2.cnt=0;
        t1.build(t1.root[m+1],1,cnt);
        t2.build(t2.root[0],1,cnt);
        for(int i=m;i>=1;i--) t1.insert(t1.root[i],t1.root[i+1],1,cnt,y[i],i);
        for(int i=1;i<=m;i++) t2.insert(t2.root[i],t2.root[i-1],1,cnt,y[i],i);
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(x[i]>x[i-1])
            {
                int now=t1.query(t1.root[f[i-1]+1],1,cnt,x[i]+1)-1;
                f[i]=min(now,m);
            }
            else{
                int now=t2.query(t2.root[f[i-1]],1,cnt,x[i]-1);
                if(now==0)
                {
                    flag=false;
                    break;
                }
                f[i]=now;
            }
        }
        /*printf("\n====\n");
        for(int i=1;i<=n;i++) printf("%d ",f[i]);
        puts("");*/
        if(flag==false) printf("0");
        else if(f[n]>=m) printf("1");
        else printf("0");
    }
    puts("");
    return 0;
}
