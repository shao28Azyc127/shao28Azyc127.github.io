#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
struct Eric_cai
{
    int to,next;
};
Eric_cai EC[maxn<<1];
int head[maxn],cnt;
void add(int u,int v)
{
    EC[++cnt].to=v;
    EC[cnt].next=head[u];
    head[u]=cnt;
}
int n;
ll a[maxn],b[maxn],c[maxn],t[maxn];
__int128 get_h(ll x,__int128 st,__int128 ed)
{
    __int128 p;
    if(c[x]==0) return (ed-st+1)*max(b[x],1ll);
    if(c[x]>0)
    {
        p=(1-b[x]+c[x]-1)/c[x];
        if(p>=st)
        {
            if(p<=ed) return (p-st)+(p*c[x]+b[x]+ed*c[x]+b[x])*(ed-p+1)/2;
            else return ed-st+1;
        }
        return (ed-st+1)*(st*c[x]+b[x]+ed*c[x]+b[x])/2;
    }
    if(c[x]<0)
    {
        p=(1-b[x]-c[x]-1)/c[x];
        if(p<=ed)
        {
            if(p>=st) return (ed-p)+(p-st+1)*(st*c[x]+b[x]+p*c[x]+b[x])/2;
            else return ed-st+1;
        }
        return (ed-st+1)*(st*c[x]+b[x]+ed*c[x]+b[x])/2;
    }
}
ll get_t(ll x,ll lim)
{
    ll l=1,r=lim,mid,ret=1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        //cout<<x<<' '<<mid<<' '<<lim<<' '<<get_h(x,mid,lim)<<'\n';
        if(get_h(x,mid,lim)>=a[x])
        {
            l=mid+1;
            ret=max(ret,mid);
        }
        else r=mid-1;
    }
    return ret;
}
int rt[maxn],dot;//Min->min(x-rk+1)
int ls[maxn*100],rs[maxn*100],Min[maxn*100],sum[maxn*100],tag[maxn*100];
void pushup(int id)
{
    sum[id]=sum[ls[id]]+sum[rs[id]];
    if(ls[id]!=0 && rs[id]!=0) Min[id]=min(Min[ls[id]],Min[rs[id]]);
    else if(ls[id]!=0) Min[id]=Min[ls[id]];
    else if(rs[id]!=0) Min[id]=Min[rs[id]];
}
int upd(int id,ll l,ll r,ll x)
{
    if(id==0)
    {
        id=++dot;
        Min[dot]=1e9,sum[dot]=0,tag[dot]=0,ls[dot]=rs[dot]=0;
    }
    if(l==r)
    {
        sum[id]++;
        Min[id]=x;
        return id;
    }
    ll mid=(l+r)>>1;
    if(x<=mid) ls[id]=upd(ls[id],l,mid,x);
    else rs[id]=upd(rs[id],mid+1,r,x);
    pushup(id);
    return id;
}
void pushdown(int id)
{
    if(ls[id]!=0)
    {
        tag[ls[id]]+=tag[id];
        Min[ls[id]]-=tag[id];
    }
    if(rs[id]!=0)
    {
        tag[rs[id]]+=tag[id];
        Min[rs[id]]-=tag[id];
    }
    tag[id]=0;
    return;
}
int merget(int id1,int id2,ll l,ll r,ll rk1,ll rk2)
{
    if(id1==0 || id2==0)
    {
        if(id1==0) swap(id1,id2),swap(rk1,rk2);
        tag[id1]+=rk2,Min[id1]-=rk2;
        return id1;
    }
    if(l==r)
    {
        rk2+=sum[id2];
        tag[id1]+=rk2,Min[id1]-=rk2;
        sum[id1]+=sum[id2];
        return id1;
    }
    ll mid=(l+r)>>1;
    pushdown(id1);
    pushdown(id2);
    rs[id1]=merget(rs[id1],rs[id2],mid+1,r,rk1+sum[ls[id1]],rk2+sum[ls[id2]]);
    ls[id1]=merget(ls[id1],ls[id2],l,mid,rk1,rk2);
    pushup(id1);
    return id1;
}
int fl;
void dfs(int now,int f)
{
    rt[now]=upd(rt[now],1,1e9,t[now]);
    for(int i=head[now];i!=0;i=EC[i].next)
    {
        if(EC[i].to!=f)
        {
            dfs(EC[i].to,now);
            rt[now]=merget(rt[now],rt[EC[i].to],1,1e9,0,0);
        }
    }
    /*if(Min[rt[now]]<-1e6 && fl==0)
    {
        cout<<now<<' '<<Min[rt[now]]<<' '<<sum[rt[now]]<<"?\n";
        fl=1;
    }*/
}
bool check(ll x)
{
    for(int i=1;i<=n;i++)
    {
        if(get_h(i,1,x)<a[i]) return 0;
        t[i]=get_t(i,x);
        //if(t[i]<=n) cout<<t[i]<<' ';
    }
    //cout<<'\n';
    //init
    for(int i=1;i<=dot;i++) Min[i]=1e9,ls[i]=rs[i]=tag[i]=sum[i]=0;
    dot=0;
    for(int i=1;i<=n;i++) rt[i]=0;
    Min[0]=1e9,sum[0]=0;
    dfs(1,0);
    return Min[rt[1]]>=1;
}
ll get_ans()
{
    ll l=0,r=1e9,mid,ret=1e9;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            ret=min(ret,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int u,v;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    cout<<get_ans()<<'\n';
    return 0;
}
