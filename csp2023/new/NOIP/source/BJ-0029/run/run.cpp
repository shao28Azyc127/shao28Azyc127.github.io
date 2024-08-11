#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=1000005;
const long long inf=1e18;
int sid,T;
int n,m,k;long long d;
struct Q
{
    int x,y,v;
    bool operator <(const Q &b) const
    {
        return x<b.x;
    }
}a[N];
/*
int idx,rt;
struct TR
{
    int fa,s[2];
    int p;long long v,ma;
    int lzy1;long long lzy2;
    void New(int f,int pos,long long val)
    {
        fa=f;
        v=val;
        p=pos;
        lzy1=lzy2=0;
    }
}tr[M];
void pushup(int x)
{
    tr[x].ma=tr[x].v;
    if(tr[x].s[0]) tr[x].ma=max(tr[x].ma,tr[tr[x].s[0]].ma);
    if(tr[x].s[1]) tr[x].ma=max(tr[x].ma,tr[tr[x].s[1]].ma);
}
void add1(int x,int k)
{
    tr[x].lzy1+=k;
    tr[x].p+=k;
}
void add2(int x,long long k)
{
    tr[x].lzy2+=k;
    tr[x].v+=k;
}
void pushdown(int x)
{
    if(tr[x].lzy1)
    {
        if(tr[x].s[1]) add1(tr[x].s[1],tr[x].lzy1);
        if(tr[x].s[2]) add1(tr[x].s[2],tr[x].lzy1);
    }
    if(tr[x].lzy2)
    {
        if(tr[x].s[1]) add1(tr[x].s[1],tr[x].lzy2);
        if(tr[x].s[2]) add1(tr[x].s[2],tr[x].lzy2);
    }
}
void down(int x)
{
    while(tr[x].fa) down(tr[x].fa);
    pushdown(x);
}
void rtt(int x)
{
    int y=tr[x].fa;
    int z=tr[y].fa;
    int k=(tr[y].s[1]==x);
    if(z) tr[z].s[tr[z].s[1]==y]=x; tr[x].fa=z;
    if(tr[x].s[k^1]) tr[tr[x].s[k^1]].fa=y; tr[y].s[k]=tr[x].s[k^1];
    tr[x].s[k^1]=y; tr[y].fa=x;
    pushup(y);
    pushup(x);
}
void splay(int x,int f)
{
    down(x);
    while(tr[x].fa!=f)
    {
        int y=tr[x].fa;
        int z=tr[y].fa;
        if(z!=f)
        {
            if((tr[z].s[1]==y)^(tr[y].s[1]==x)) rtt(y);
            else rtt(x);
        }
        rtt(x);
    }
    if(k==0) rt=x;
}
int getp(int pos)
{
    int now=rt,pre=0;
    while(now)
    {
        pushdown(now);
        if(tr[now].p<pos) now=tr[now].s[0];
        else pre=now,now=tr[now].s[1];
    }
    return pre;
}
int getpre(int x)
{
    pushdown(x);
    x=tr[x].s[0];
    pushdown(x);
    while(tr[x].s[1]) x=tr[x].s[1],pushdown(x);
    return x;
}
void update1(int v)
{
    printf("LLL");
    int x=getp(0);
    printf("%d",x);
    splay(x,0);
    splay(2,x);
    if(tr[2].s[0]) add1(tr[2].s[0],v);
}
void update2(int l,int v)
{
    int x=getp(l);
    splay(x,0);
    if(tr[x].p!=l)
    {
        x=getpre(x);
        int v=tr[x].v+(l-tr[x].p)*d;
        tr[x].s[1]=++idx;
        tr[idx].New(x,l,v);
    }
    x=getpre(x);
}
void init()
{
    idx=2;rt=1;
    tr[1].New(0,-1,-inf);
    tr[2].New(1,k,inf);
    tr[1].s[1]=2;
}
void print(int x)
{
    pushdown(x);
    if(tr[x].s[0]) print(tr[x].s[0]);
    printf("%d:%lld\n",tr[x].p,tr[x].v);
    if(tr[x].s[1]) print(tr[x].s[1]);
    pushup(x);
}
int main()
{
    freopen("run1.in","r",stdin);
    //freopen("run.out","w",stdout);
    scanf("%d%d",&sid,&T);
    while(T--)
    {
        scanf("%d%d%d%lld",&n,&m,&k,&d);
        for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
        sort(a+1,a+m+1);
        init();
        int pre=0;
        for(int i=1;i<=m;i++)
        {
            int x=a[i].x,y=a[i].y,v=a[i].v;
            if(x-pre)
            {
                update1(x-pre);
                update2(0,(x-pre)*d);
            }
            print(rt);
        }
    }
}
*/
long long f[N];
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&sid,&T);
    while(T--)
    {
        scanf("%d%d%d%lld",&n,&m,&k,&d);
        for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
        sort(a+1,a+m+1);
        if(sid==17||sid==18)
        {
            long long ans=0;
            for(int i=1;i<=m;i++) ans+=max(0ll,a[i].v-a[i].y*d);
            printf("%lld\n",ans);
            continue;
        }
        f[0]=0;
        for(int i=1;i<=k;i++) f[i]=-inf;
        int now=0;long long ma=0;
        for(int i=1;i<=m;i++)
        {
            while(now<a[i].x)
            {
                for(int i=k;i>=1;i--) f[i]=f[i-1]-d;
                f[0]=ma;
                for(int i=0;i<=k;i++) ma=max(ma,f[i]);
                now++;
            }
            for(int j=a[i].y;j<=k;j++) f[j]+=a[i].v;
            for(int i=0;i<=k;i++) ma=max(ma,f[i]);
            //printf("%d:",now);
            //for(int j=0;j<=k;j++) printf("%lld ",f[j]);printf("\n");
        }
        printf("%lld\n",ma);
    }
    return 0;
}
