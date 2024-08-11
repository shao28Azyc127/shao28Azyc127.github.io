#include<bits/stdc++.h>
#define y1 hudxishx
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const int maxn=100005;
const ll mod=998244353;
void ad(int &x,int y,int z){x=y+z;if(x>=mod) x-=mod;}
void ad(ll &x,ll y,ll z){x=y+z;if(x>=mod) x-=mod;}
void ad(int &x,int y){x+=y;if(x>=mod) x-=mod;}
void ad(ll &x,ll y){x+=y;if(x>=mod) x-=mod;}
void siu(int &x,int y,int z){x=y-z;if(x<0) x+=mod;}
void siu(ll &x,ll y,ll z){x=y-z;if(x<0) x+=mod;}
void siu(int &x,int y){x-=y;if(x<0) x+=mod;}
void siu(ll &x,ll y){x-=y;if(x<0) x+=mod;}
int Min(int x,int y){return x<y?x:y;}
ll Min(ll x,ll y){return x<y?x:y;}
int Max(int x,int y){return x>y?x:y;}
ll Max(ll x,ll y){return x>y?x:y;}
void tmn(int &x,int y){if(x>y) x=y;}
void tmn(ll &x,ll y){if(x>y) x=y;}
void tmx(int &x,int y){if(x<y) x=y;}
void tmx(ll &x,ll y){if(x<y) x=y;}
ll qpow(ll aa,ll bb){ll res=1;while(bb){if(bb&1) res=res*aa%mod;aa=aa*aa%mod;bb>>=1;}return res;}
int _,__;
int n,m,k;
ll d;
namespace sub1
{
    ll sum[1005][1005];
    ll f[1005][1005];
    void sve()
    {
        for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) sum[i][j]=0,f[i][j]=-1e18;
        for(int i=1;i<=m;i++)
        {
            int x,y;ll v;cin>>x>>y>>v;
            if(y>k) continue;
            for(int j=y;j<=k;j++) sum[x][j]+=v;
        }
        f[0][0]=0;
        for(int i=0;i<n;i++) for(int j=0;j<=k;j++)
        {
            tmx(f[i+1][0],f[i][j]+sum[i+1][0]);
            if(j+1<=k) tmx(f[i+1][j+1],f[i][j]-d+sum[i+1][j+1]);
        }
        ll ans=-1e18;
        for(int i=0;i<=k;i++) tmx(ans,f[n][i]);
        cout<<ans<<"\n";
    }
}
namespace sub2
{
    void sve()
    {
        ll ans=0;
        for(int i=1;i<=m;i++)
        {
            int x,y;ll v;cin>>x>>y>>v;
            if(y>k) continue;
            if(d*y<v) ans+=v-d*y;
        }
        cout<<ans<<"\n";
    }
}
namespace sub3
{
    int L[maxn],R[maxn],tp;
    ll sum[maxn];
    ll f[maxn],g[maxn];
    ll mx[maxn<<2];
    inline int ls(int x){return x<<1;}
    inline int rs(int x){return x<<1|1;}
    void pushup(int x){mx[x]=Max(mx[ls(x)],mx[rs(x)]);}
    void build(int x,int l,int r)
    {
        mx[x]=-1e18;
        if(l==r)return;
        int mid=(l+r)>>1;
        build(ls(x),l,mid);build(rs(x),mid+1,r);
    }
    void upd(int x,int l,int r,int id,ll k)
    {
        if(l==r){mx[x]=k;return;}
        int mid=(l+r)>>1;
        if(id<=mid) upd(ls(x),l,mid,id,k);
        else upd(rs(x),mid+1,r,id,k);
        pushup(x);
    }
    ll qry(int x,int l,int r,int ql,int qr)
    {
        if(ql>qr) return -1e18;
        if(l>=ql&&r<=qr) return mx[x];
        ll res=-1e18;int mid=(l+r)>>1;
        if(ql<=mid) res=Max(res,qry(ls(x),l,mid,ql,qr));
        if(qr>mid) res=Max(res,qry(rs(x),mid+1,r,ql,qr));
        return res;
    }
    void sve()
    {
        tp=0;
        for(int i=1;i<=m;i++)
        {
            int x,y;ll v;cin>>x>>y>>v;
            if(y>k) continue;
            L[++tp]=x-y+1;R[tp]=x;
            sum[tp]=sum[tp-1]+v;
        }
        m=tp;
        for(int i=1;i<=m;i++) f[i]=g[i]=-1e18;
        f[0]=g[0]=0;
        build(1,1,m);
        for(int i=1;i<=m;i++)
        {
            int t=lower_bound(R+1,R+m+1,L[i]-1)-R-1;
            upd(1,1,m,i,-sum[i-1]+d*(L[i]-1)+g[t]);
            t=lower_bound(L+1,L+m+1,R[i]-k+1)-L;
            f[i]=sum[i]-d*R[i]+qry(1,1,m,t,i);
            g[i]=Max(g[i-1],f[i]);
        }
        cout<<g[m]<<"\n";
    }
}
void solve()
{
    cin>>n>>m>>k>>d;
    if(__<=9) sub1::sve();
    else if(__>=17&&__<=18) sub2::sve();
    else if(__>=19&&__<=21) sub3::sve();
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>__>>_;
    //_=1;
    while(_--)
    {
        solve();
    }
    return 0;
}
