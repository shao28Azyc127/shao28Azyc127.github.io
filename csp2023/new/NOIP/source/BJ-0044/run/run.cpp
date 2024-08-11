#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#define fup(i,l,r) for(int i=l;i<=r;i++)
#define fdn(i,l,r) for(int i=r;i>=l;i--)
#define ll long long
#define ull unsigned long long
#define ld long double
#define mod 998244353
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define maxn 200010
#define int ll
using namespace std;

bool up(int &x,int y) { return (x<y?x=y,1:0); }
bool down(int &x,int y) { return (x>y?x=y,1:0); }
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int n,m,k,d,dp[maxn];
vector<pii> a[maxn];
struct Node{
    int l,r,mx,add;
}tr[maxn*4];
void pushup(int u) { tr[u].mx=max(tr[u<<1|1].mx,tr[u<<1].mx); }
void pushdown(int u)
{
    if(tr[u].add)
    {
        tr[u<<1].mx+=tr[u].add,tr[u<<1|1].mx+=tr[u].add;
        tr[u<<1].add+=tr[u].add,tr[u<<1|1].add+=tr[u].add;
        tr[u].add=0;
    }
}
void build(int u,int l,int r)
{
    tr[u].l=l,tr[u].r=r,tr[u].mx=0,tr[u].add=0;
    if(l==r)
    {
        if(l==0) tr[u].mx=0;
        return;
    }
    int mid=(l+r)>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}
void inc(int u,int ql,int qr,int x)
{
    if(ql<=tr[u].l&&tr[u].r<=qr)
    {
        tr[u].mx+=x,tr[u].add+=x;
        return;
    }
    int mid=(tr[u].l+tr[u].r)>>1;
    pushdown(u);
    if(ql<=mid) inc(u<<1,ql,qr,x);
    if(qr>mid) inc(u<<1|1,ql,qr,x);
    pushup(u);
}
int qry(int u,int ql,int qr)
{
    //if(ql==1&&qr==3) cout<<tr[u].l<<' '<<tr[u].r<<' '<<tr[u].mx<<' '<<tr[u].add<<endl;
    if(ql<=tr[u].l&&tr[u].r<=qr) return tr[u].mx;
    int mid=(tr[u].l+tr[u].r)>>1,res=-1e18;
    pushdown(u);
    if(ql<=mid) up(res,qry(u<<1,ql,qr));
    if(qr>mid) up(res,qry(u<<1|1,ql,qr));
    return res;
}

void solve2()
{
    int ans=0;
    fup(i,1,m)
    {
        int x=read(),y=read(),v=read();
        if(y>k) continue;
        ans+=max(0ll,v-y*d);
    }
    printf("%lld\n",ans);
}

void solve()
{
    n=read(),m=read(),k=read(),d=read();
    if(n>=1000000000) return solve2(),void();
    fup(i,1,n) a[i].clear();
    fup(i,1,m)
    {
        int x=read(),y=read(),v=read();
        a[x].pb(mp(x-y,v));
    }
    dp[0]=0;
    build(1,0,n+1);
    fup(i,1,n+1)
    {
        dp[i]=qry(1,max(0ll,i-k-1),i-1)+d;
        //cout<<dp[i]<<endl;
        inc(1,i,i,dp[i]);
        for(pii p:a[i]) inc(1,0,p.x,p.y);
    }
    printf("%lld\n",dp[n+1]-(n+1)*d);
}

signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int cs=read(),T=read();
    while(T--) solve();
    return 0;
}
