#include<bits/stdc++.h>
#define lson (x<<1)
#define rson (x<<1)|1
using namespace std;
int n,m,q;
struct node{
    int maxx,minn;
}t[2000005];
int x[500005],y[500005];
void build(int l,int r,int x)
{
    //cout<<"::"<<l<<" "<<r<<endl;
    if(l==r)
    {
        t[x].maxx=y[l];
        t[x].minn=y[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    t[x].minn=min(t[lson].minn,t[rson].minn);
    t[x].maxx=max(t[lson].maxx,t[rson].maxx);
}
void gb(int l,int r,int ql,int key,int x)
{
    if(l==r)
    {
        t[x].maxx=key;
        t[x].minn=key;
        return;
    }
    int mid=(l+r)>>1;
    if(ql<=mid)
    {
        gb(l,mid,ql,key,lson);
    }
    else
    {
        gb(mid+1,r,ql,key,rson);
    }
    t[x].minn=min(t[2*x].minn,t[2*x+1].minn);
    t[x].maxx=max(t[2*x].maxx,t[2*x+1].maxx);
}
int findleft(int l,int r,int ql,int qr,int key,int flag,int x)//0/1:zai ql~qr li cha zhao bi key </> de zui kao you de dian
{
    //cout<<"??"<<l<<" "<<r<<" "<<ql<<" "<<qr<<" "<<key<<" "<<flag<<endl;
    if(l==r)
    {
        if(flag==1)
        {
            if(t[x].maxx>key)
            {
                return l;
            }
        }
        else
        {
            if(t[x].minn<key)
            {
                return l;
            }
        }
        return 0;
    }
    if(l==ql&&r==qr)
    {
        int mid=(l+r)>>1;
        if(flag==1)
        {
            if(t[2*x+1].maxx>key)
            {
                return findleft(mid+1,r,mid+1,r,key,flag,rson);
            }
            if(t[2*x].maxx>key)
            {
                return findleft(l,mid,l,mid,key,flag,lson);
            }
        }
        else
        {
            if(t[2*x+1].minn<key)
            {
                return findleft(mid+1,r,mid+1,r,key,flag,rson);
            }
            if(t[2*x].minn<key)
            {
                return findleft(l,mid,l,mid,key,flag,lson);
            }
        }
        return 0;
    }
    int mid=(l+r)>>1;
    if(qr>mid)
    {
        int now=findleft(mid+1,r,max(ql,mid+1),qr,key,flag,rson);
        if(now!=0)
        {
            return now;
        }
    }
    if(ql<=mid)
    {
        int now=findleft(l,mid,ql,min(mid,qr),key,flag,lson);
        if(now!=0)
        {
            return now;
        }
    }
    return 0;
}
int findright(int l,int r,int ql,int qr,int key,int flag,int x)//0/1:zai ql~qr li cha zhao zui da de x shi de ql~x dou </> yu key de x
{
    if(l==r)
    {
        if(flag==1)
        {
            if(t[x].maxx>key)
            {
                return l;
            }
        }
        else
        {
            if(t[x].minn<key)
            {
                return l;
            }
        }
        return l-1;
    }
    if(l==ql&&r==qr)
    {
        int mid=(l+r)>>1;
        if(flag==1)
        {
            if(t[x].minn>key)
            {
                return qr;
            }
            else
            {
                if(t[2*x].minn>key)
                {
                    return findright(mid+1,r,mid+1,r,key,flag,rson);
                }
                return findright(l,mid,l,mid,key,flag,lson);
            }
        }
        else
        {
            if(t[x].maxx<key)
            {
                return qr;
            }
            else
            {
                if(t[2*x].maxx<key)
                {
                    return findright(mid+1,r,mid+1,r,key,flag,rson);
                }
                return findright(l,mid,l,mid,key,flag,lson);
            }
        }
    }
    int mid=(l+r)>>1;
    int re=ql-1;
    if(ql<=mid)
    {
        re=findright(l,mid,ql,min(qr,mid),key,flag,lson);
        if(qr>mid&&re==mid)
        {
            re=findright(mid+1,r,mid+1,qr,key,flag,rson);
        }
    }
    else
    {
        re=findright(mid+1,r,max(ql,mid+1),qr,key,flag,rson);
    }
    return re;
}
int ans[500005];
inline void solve()
{
    /*for(int i=1;i<=n;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;*/
    ans[n]=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<"::"<<i<<endl;
        int now=findleft(1,m,1,min(ans[i-1]+1,m),x[i],0,1);
        //cout<<"::"<<1<<" "<<min(ans[i-1]+1,m)<<" "<<x[i]<<" "<<now<<" "<<0<<endl;
        if(now==0)
        {
            break;
        }
        ans[i]=findright(1,m,now,m,x[i],0,1);
    }
    if(ans[n]==m)
    {
        cout<<1;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        int now=findleft(1,m,1,min(ans[i-1]+1,m),x[i],1,1);
        if(now==0)
        {
            break;
        }
        ans[i]=findright(1,m,now,m,x[i],1,1);
    }
    if(ans[n]==m)
    {
        cout<<1;
        return;
    }
    cout<<0;
}
int xx[500005],yy[500005];
int id1[500005],id2[500005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int waste;
    cin>>waste>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        xx[i]=x[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>y[i];
        yy[i]=y[i];
    }
    build(1,m,1);
    solve();
    int k1,k2;
    while(q--)
    {
        cin>>k1>>k2;
        int t2;
        for(int i=1;i<=k1;i++)
        {
            cin>>id1[i]>>t2;
            x[id1[i]]=t2;
        }
        for(int i=1;i<=k2;i++)
        {
            cin>>id2[i]>>t2;
            y[id2[i]]=t2;
            gb(1,m,id2[i],t2,1);
        }
        //cout<<"------------------"<<endl;
        solve();
        for(int i=1;i<=k1;i++)
        {
            x[id1[i]]=xx[id1[i]];
        }
        for(int i=1;i<=k2;i++)
        {
            y[id2[i]]=yy[id2[i]];
            gb(1,m,id2[i],yy[id2[i]],1);
        }
    }
    return 0;
}
