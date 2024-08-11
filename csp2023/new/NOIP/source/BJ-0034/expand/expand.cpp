# include <bits/stdc++.h>
# define N 500005
using namespace std;
int c,n,m,q;
int a[N],b[N],A[N],B[N];
int kx,ky,px[N],x[N],py[N],y[N];
struct Segment_Tree
{
    int pos[N],mina[N<<2],maxa[N<<2];
    void build(int now,int l,int r)
    {
        if(l==r)
        {
            pos[l]=now;
            return ;
        }
        int mid=l+r>>1;
        build(now<<1,l,mid);
        build(now<<1|1,mid+1,r);
    }
    void update(int x,int y)
    {
        int now=pos[x];
        mina[now]=maxa[now]=y;
        while(now!=1)
        {
            now/=2;
            mina[now]=min(mina[now<<1],mina[now<<1|1]);
            maxa[now]=max(maxa[now<<1],maxa[now<<1|1]);
        }
    }
    int get1(int now,int l,int r,int L,int x)
    {
        if(maxa[now]<x)
            return -1;
        if(r<L)
            return -1;
        if(l==r)
            return l;
        int mid=l+r>>1;
        int p=get1(now<<1,l,mid,L,x);
        if(p==-1)
            return get1(now<<1|1,mid+1,r,L,x);
        else
            return p;
    }
    int get2(int now,int l,int r,int R,int x)
    {
        if(mina[now]>=x)
            return -1;
        if(l>R)
            return -1;
        if(l==r)
            return l;
        int mid=l+r>>1;
        int p=get2(now<<1|1,mid+1,r,R,x);
        if(p==-1)
            return get2(now<<1,l,mid,R,x);
        else
            return p;
    }
}T1,T2;
bool doit()
{
    if(a[1]==b[1])
        return 0;
    if(a[1]>b[1])
    {
        int nowr=0;
        for(int i=1;i<=n;i++)
            if(i!=1 && i!=n && 1ll*(a[i-1]-a[i])*(a[i]-a[i+1])>=0)
                continue;
            else
            {
                if(nowr!=m && a[i]>b[nowr+1])
                {
                    nowr=T2.get1(1,1,m,nowr+1,a[i]);
                    if(nowr==-1)
                        nowr=m;
                    else
                        nowr--;
                }
                else
                {
                    nowr=T2.get2(1,1,m,nowr,a[i]);
                    if(nowr==-1)
                        return 0;
                }
            }
        return (nowr==m);
    }
    else
    {
        int nowr=0;
        for(int i=1;i<=m;i++)
            if(i!=1 && i!=m && 1ll*(b[i-1]-b[i])*(b[i]-b[i+1])>=0)
                continue;
            else
            {
                if(nowr!=n && b[i]>a[nowr+1])
                {
                    nowr=T1.get1(1,1,n,nowr+1,b[i]);
                    if(nowr==-1)
                        nowr=n;
                    else
                        nowr--;
                }
                else
                {
                    nowr=T1.get2(1,1,n,nowr,b[i]);
                    if(nowr==-1)
                        return 0;
                }
            }
        return (nowr==n);
    }
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),A[i]=a[i];
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]),B[i]=b[i];
    T1.build(1,1,n);
    T2.build(1,1,m);
    for(int i=1;i<=n;i++)
        T1.update(i,a[i]);
    for(int i=1;i<=m;i++)
        T2.update(i,b[i]);
    printf("%d",doit());
    while(q--)
    {
        int kx,ky;
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;i++)
        {
            scanf("%d%d",&px[i],&x[i]);
            a[px[i]]=x[i];
            T1.update(px[i],x[i]);
        }
        for(int i=1;i<=ky;i++)
        {
            scanf("%d%d",&py[i],&y[i]);
            b[py[i]]=y[i];
            T2.update(py[i],y[i]);
        }
        printf("%d",doit());
        for(int i=1;i<=kx;i++)
        {
            a[px[i]]=A[px[i]];
            T1.update(px[i],A[px[i]]);
        }
        for(int i=1;i<=ky;i++)
        {
            b[py[i]]=B[py[i]];
            T2.update(py[i],B[py[i]]);
        }
    }
    return 0;
}