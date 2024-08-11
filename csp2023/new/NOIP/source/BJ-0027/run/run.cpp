#include<bits/stdc++.h>
#define int long long
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=500000+5;
int L[n_MAX],R[n_MAX],w[n_MAX],a[n_MAX],F[n_MAX]; vector<pair<int,int>> vec[n_MAX];
struct Segment_Tree
{
    int a[n_MAX<<2],tag[n_MAX<<2];
    inline int lch(const int u){return (u<<1);}
    inline int rch(const int u){return (u<<1|1);}
    void apply(const int u,const int w){a[u]+=w,tag[u]+=w;}
    void push_up(const int u){a[u]=max(a[lch(u)],a[rch(u)]);}
    void push_down(const int u){if(tag[u]) apply(lch(u),tag[u]),apply(rch(u),tag[u]),tag[u]=0;}
    void Build(const int u,const int l,const int r)
    {
        a[u]=tag[u]=0;
        if(l==r) return;
        const int mid=((l+r)>>1);
        Build(lch(u),l,mid),Build(rch(u),mid+1,r);
    }
    int Query(const int u,const int l,const int r,const int ql,const int qr)
    {
        if(ql<=l&&r<=qr) return a[u];
        push_down(u);
        const int mid=((l+r)>>1);
        int b=LONG_LONG_MIN;
        if(ql<=mid) b=max(b,Query(lch(u),l,mid,ql,qr));
        if(qr>mid) b=max(b,Query(rch(u),mid+1,r,ql,qr));
        return b;
    }
    void Modify(const int u,const int l,const int r,const int ql,const int qr,const int w)
    {
        if(ql<=l&&r<=qr){apply(u,w);return;}
        push_down(u);
        const int mid=((l+r)>>1);
        if(ql<=mid) Modify(lch(u),l,mid,ql,qr,w);
        if(qr>mid) Modify(rch(u),mid+1,r,ql,qr,w);
        push_up(u);
    }
};
Segment_Tree St;
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int sub,T; cin>>sub>>T;
    while(T--)
    {
        int n,m=0,q,k,d; cin>>n>>q>>k>>d,a[++m]=(n+1);
        For(i,1,q)
        {
            int x,y; cin>>x>>y>>w[i];
            L[i]=(x-y+1),R[i]=x,a[++m]=(L[i]-1),a[++m]=R[i];
        }
        sort(a,a+m+1),m=(unique(a,a+m+1)-a-1),F[0]=0;
        For(i,1,q)
        {
            L[i]=((lower_bound(a,a+m+1,L[i]-1)-a)+1);
            R[i]=(lower_bound(a,a+m+1,R[i])-a);
            vec[R[i]].push_back({L[i],w[i]});
        }
        St.Build(1,0,m);
        int must=0;
        For(i,1,m)
        {
            F[i]=St.Query(1,0,m,must,i-1),St.Modify(1,0,m,i,i,F[i]);
            while((a[i]-a[must])>k) ++must;
            if(must<=(i-1)) St.Modify(1,0,m,must,i-1,(a[i-1]-a[i])*d);
            for(const pair<int,int> &P:vec[i])
            {
                const int l=P.first,w=P.second;
                if(must<=(l-1)) St.Modify(1,0,m,must,l-1,w);
            }
        }
        cout<<F[m]<<'\n';
        For(i,1,m) vec[i].clear(),vec[i].shrink_to_fit();
    }
    return 0;
}