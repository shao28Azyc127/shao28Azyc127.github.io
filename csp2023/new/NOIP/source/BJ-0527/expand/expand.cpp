#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef double db;
const int N=5e5+5;
int c,n,m,q,x[N],y[N];
struct node
{
    int mi,mx;
};
inline int ls(int p)
{
    return p<<1;
}
inline int rs(int p)
{
    return p<<1|1;
}
struct seg
{
    node t[N<<2];
    void init()
    {
        for(int i=1;i<N<<2;i++)
        {
            t[i].mi=1e9;
            t[i].mx=0;
        }
    }
    void push_up(int p)
    {
        t[p].mi=min(t[ls(p)].mi,t[rs(p)].mi);
        t[p].mx=max(t[ls(p)].mx,t[rs(p)].mx);
    }
    void upd(int p,int l,int r,int x,int k)
    {
        if(l==r)
        {
            t[p].mi=t[p].mx=k;
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)upd(ls(p),l,mid,x,k);
        else upd(rs(p),mid+1,r,x,k);
        push_up(p);
    }
    int qrymin(int p,int l,int r,int ql,int qr)
    {
        if(ql<=l&&qr>=r)return t[p].mi;
        int mid=l+r>>1;
        if(ql>mid)return qrymin(rs(p),mid+1,r,ql,qr);
        if(qr<=mid)return qrymin(ls(p),l,mid,ql,qr);
        return min(qrymin(rs(p),mid+1,r,ql,qr),qrymin(ls(p),l,mid,ql,qr));
    }
    int qrymax(int p,int l,int r,int ql,int qr)
    {
        if(ql<=l&&qr>=r)return t[p].mx;
        int mid=l+r>>1;
        if(ql>mid)return qrymax(rs(p),mid+1,r,ql,qr);
        if(qr<=mid)return qrymax(ls(p),l,mid,ql,qr);
        return max(qrymax(rs(p),mid+1,r,ql,qr),qrymax(ls(p),l,mid,ql,qr));
    }
}tx,ty;
void solve()
{
    if(n==1&&m==1)putchar('1');
    else
    {
        if(n==1&&m==2)
        {
            if(x[1]>y[1])
            {
                if(x[1]>y[2])putchar('1');
                else putchar('0');
            }
            else if(x[1]<y[1])
            {
                if(x[1]<y[2])putchar('1');
                else putchar('0');
            }
            else putchar('0');
        }
        if(n==2&&m==1)
        {
            if(y[1]>x[1])
            {
                if(y[1]>x[2])putchar('1');
                else putchar('0');
            }
            else if(y[1]<x[1])
            {
                if(y[1]<x[2])putchar('1');
                else putchar('0');
            }
            else putchar('0');
        }
        if(n==2&&m==2)
        {
            if(x[1]>y[1])
            {
                if(x[2]>y[2])putchar('1');
                else putchar('0');
            }
            else if(x[1]<y[1])
            {
                if(x[2]<y[2])putchar('1');
                else putchar('0');
            }
            else putchar('0');
        }
    }
    while(q--)
    {
        int kx,ky;
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;i++)
        {
            int p,v;
            scanf("%d%d",&p,&v);
            x[p]=v;
        }
        for(int i=1;i<=ky;i++)
        {
            int p,v;
            scanf("%d%d",&p,&v);
            y[p]=v;
        }
        if(n==1&&m==1)putchar('1');
        else
        {
            if(n==1&&m==2)
            {
                if(x[1]>y[1])
                {
                    if(x[1]>y[2])putchar('1');
                    else putchar('0');
                }
                else if(x[1]<y[1])
                {
                    if(x[1]<y[2])putchar('1');
                    else putchar('0');
                }
                else putchar('0');
            }
            if(n==2&&m==1)
            {
                if(y[1]>x[1])
                {
                    if(y[1]>x[2])putchar('1');
                    else putchar('0');
                }
                else if(y[1]<x[1])
                {
                    if(y[1]<x[2])putchar('1');
                    else putchar('0');
                }
                else putchar('0');
            }
            if(n==2&&m==2)
            {
                if(x[1]>y[1])
                {
                    if(x[2]>y[2])putchar('1');
                    else putchar('0');
                }
                else if(x[1]<y[1])
                {
                    if(x[2]<y[2])putchar('1');
                    else putchar('0');
                }
                else putchar('0');
            }
        }
    }
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    tx.init(),ty.init();
    for(int i=1;i<=n;i++)scanf("%d",&x[i]),tx.upd(1,1,n,i,x[i]);
    for(int i=1;i<=m;i++)scanf("%d",&y[i]),ty.upd(1,1,m,i,y[i]);
    if(max(n,m)<=2)
    {
        solve();
        return 0;
    }
    if(x[1]>y[1])
    {
        if(x[n]>y[m])putchar('1');
        else putchar('0');
    }
    else if(x[1]<y[1])
    {
        if(x[n]<y[m])putchar('1');
        else putchar('0');
    }
    else putchar('0');
    while(q--)
    {
        int kx,ky;
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;i++)
        {
            int p,v;
            scanf("%d%d",&p,&v);
            tx.upd(1,1,n,p,v);
            x[p]=v;
        }
        for(int i=1;i<=ky;i++)
        {
            int p,v;
            scanf("%d%d",&p,&v);
            ty.upd(1,1,m,p,v);
            y[p]=v;
        }
        if(x[1]>y[1])
        {
            if(x[n]>y[m])putchar('1');
            else putchar('0');
        }
        else if(x[1]<y[1])
        {
            if(x[n]<y[m])putchar('1');
            else putchar('0');
        }
        else putchar('0');
    }
    return 0;
}
