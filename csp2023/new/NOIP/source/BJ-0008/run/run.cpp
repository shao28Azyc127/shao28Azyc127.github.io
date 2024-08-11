#include<bits/stdc++.h>
#define ll long long
using namespace std;

int _,n,m,x,d;
int l[100005],r[100005],v[100005];
int p[200005],cnt;
ll tr[800005],tag[800005],ans;
vector<int> adj[200005];

inline int lc(int k){return k<<1;}

inline int rc(int k){return k<<1|1;}

inline void pushdown(int k)
{
    tr[lc(k)]+=tag[k];
    tag[lc(k)]+=tag[k];
    tr[rc(k)]+=tag[k];
    tag[rc(k)]+=tag[k];

    tag[k]=0;
}

inline void build(int k,int l,int r)
{
    tr[k]=tag[k]=0;

    if(l==r)
        return;

    int mid=(l+r)>>1;

    build(lc(k),l,mid);
    build(rc(k),mid+1,r);
}

inline void change(int k,int l,int r,int ql,int qr,ll vl)
{
    if(ql>qr)
        return;

    if(ql<=l&&r<=qr)
    {
        tr[k]+=vl;
        tag[k]+=vl;

        return;
    }

    pushdown(k);

    int mid=(l+r)>>1;

    if(ql<=mid)
        change(lc(k),l,mid,ql,qr,vl);
    if(mid<qr)
        change(rc(k),mid+1,r,ql,qr,vl);

    tr[k]=max(tr[lc(k)],tr[rc(k)]);
}

inline ll query(int k,int l,int r,int ql,int qr)
{
    if(ql>qr)
        return 0;

    if(ql<=l&&r<=qr)
        return tr[k];

    pushdown(k);

    int mid=(l+r)>>1;
    ll res=0;

    if(ql<=mid)
        res=max(res,query(lc(k),l,mid,ql,qr));
    if(mid<qr)
        res=max(res,query(rc(k),mid+1,r,ql,qr));

    return res;
}

inline void sol()
{
    cin>>n>>m>>x>>d;

    cnt=0;
    for(int i=1;i<=m;i++)
    {
        cin>>r[i]>>l[i]>>v[i];
        l[i]=r[i]-l[i]+1;
        p[++cnt]=l[i]-1;
        p[++cnt]=r[i]+1;
    }

    sort(p+1,p+cnt+1);
    n=unique(p+1,p+cnt+1)-p-1;

    for(int i=1;i<=m;i++)
    {
        int it=upper_bound(p+1,p+n+1,r[i])-p;
        adj[it].push_back(i);
    }

    build(1,1,n);
    ans=0;

    for(int i=1;i<=n;i++)
    {
        if(i)
            change(1,1,n,1,i-1,-1LL*(p[i]-p[i-1]-1)*d);

        for(int it:adj[i])
        {
            int ps=lower_bound(p+1,p+n+1,l[it]-1)-p;

            change(1,1,n,1,ps,v[it]);
        }

        int pk=lower_bound(p+1,p+n+1,p[i]-x-1)-p;
        ans=max(ans,query(1,1,n,pk,i));
        change(1,1,n,i,i,ans);

        if(i)
            change(1,1,n,1,i-1,-1LL*d);
    }

    cout<<ans<<'\n';

    for(int i=1;i<=cnt;i++)
        adj[i].clear();
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>_;
    cin>>_;

    while(_--)
        sol();

    return 0;
}
