#include <bits/stdc++.h>
#define rfor(i,l,r) for(int i=l;i<=r;i++)
#define irfor(i,r,l) for(int i=r;i>=l;i--)
#define ls(p) p<<1
#define rs(p) p<<1|1
#define y0 qwrgshsjglarahfkagr
#define y1 soighsodighslighddd
using namespace std;
typedef long long ll;typedef unsigned long long ull;typedef pair<int,int> pii;
inline ll read()
{
    ll x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-48;c=getchar();}
    return x*f;
}
inline void gmin(int &a,int b){if(b<a)a=b;}inline void gmax(int &a,int b){if(b>a)a=b;}
inline void gmin(ll &a,ll b){if(b<a)a=b;}inline void gmax(ll &a,ll b){if(b>a)a=b;}
inline int min(int a,int b){return a<b?a:b;}inline int max(int a,int b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}inline ll max(ll a,ll b){return a>b?a:b;}
const int N = 1e5+5;
ll n,a[N],b[N],c[N];vector<int> adj[N];
int fa[N],dep[N],sz[N];
struct plt{
    int id,p;
    plt(int id=0,int p=0):id(id),p(p){}
    bool operator<(const plt&x)const
    {
        if(p != x.p) return p > x.p;
        return dep[id] > dep[x.id];
    }
}pl[N];
void dfs(int u,int f)
{
    fa[u] = f;dep[u] = dep[f]+1;sz[u] = 1;
    for(int v:adj[u])
    {
        if(v == f) continue;
        sz[u]++;
        dfs(v,u);
    }
}
ll cal(int i,int l,int r)
{
    __int128 x = 0;
    if(c[i] >= 0) x = __int128(2*b[i]+(l+r)*c[i])*(r-l+1)/2;
    else
    {
        int pr = b[i]/(-c[i]);
        if(b[i]%c[i]==0) pr--;
        if(pr < l) x = r-l+1;
        else if(pr >= r) x = __int128(2*b[i]+(l+r)*c[i])*(r-l+1)/2;
        else
        {
            x = __int128(2*b[i]+(l+pr)*c[i])*(pr-l+1)/2;
            l = pr+1;
            x += r-l+1;
        }
    }
    ll qwq = 0;
    if(x > 1e18) qwq = 1e18+1;
    else qwq = x;
    return qwq;
}
int tag[N],viscnt;
queue<int> pq;
bool check(int dy)
{
    rfor(i,1,n)
    {
        int l = 1,r = dy,mid,ans=-1;
        while(l <= r)
        {
            mid = l+r>>1;
            if(cal(i,mid,dy) >= a[i]) ans = mid,l = mid+1;
            else r = mid-1;
        }
        if(ans == -1) return false;
        tag[i] = sz[i];pl[i].id = i;pl[i].p = ans;
    }
    sort(pl+1,pl+n+1);
    viscnt = 0;
    int tmpp = 0;
    while(dy && tmpp < n)
    {
        if(pq.empty())
        {
            tmpp++;
            dy = min(pl[tmpp].p,dy);
            tag[pl[tmpp].id]--;
            if(tag[pl[tmpp].id] == 0) pq.push(pl[tmpp].id);
        }
        while(!pq.empty())
        {
            int ntt = pq.front();pq.pop();
            dy--;
            tag[fa[ntt]]--;
            if(tag[fa[ntt]] == 0) pq.push(fa[ntt]);
        }
    }
    return dy>=0;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    n = read();
    rfor(i,1,n) a[i]=read(),b[i]=read(),c[i]=read();
    rfor(i,1,n-1)
    {
        int u=read(),v=read();
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    int l = 1,r = 1e9,mid,ans=1e9;
    while(l <= r)
    {
        mid = l+r>>1;
        if(check(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    cout << ans;
    return 0;
}
