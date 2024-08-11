#include <bits/stdc++.h>
#define rfor(i,l,r) for(int i=l;i<=r;i++)
#define irfor(i,r,l) for(int i=r;i>=l;i--)
#define ls(p) p<<1
#define rs(p) p<<1|1
#define mkp make_pair
#define x0 aiklsfhlasdkfghlkadrfhgasdfg
#define y0 zsfdkgjhlksdfhglksfdhglkasdf
#define y1 sklrluhgklahrgklsedrhgklfdhg
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
const int N = 1e5+5,mod = 1e9+7;
struct node{
    ll maxd,addt;
    void add(ll x){maxd+=x;addt+=x;}
}nd[N*12];
void pushup(int p){nd[p].maxd = max(nd[ls(p)].maxd,nd[rs(p)].maxd);}
void pushdown(int p){if(!nd[p].addt) return;nd[ls(p)].add(nd[p].addt);nd[rs(p)].add(nd[p].addt);nd[p].addt=0;}
void build(int p,int l,int r)
{
    nd[p].maxd = nd[p].addt = 0;
    if(l == r) return;
    int mid = l+r>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
}
void change(int p,int l,int r,int ql,int qr,ll k)
{
//    printf("%d %d %d %d %d %d\n",p,l,r,ql,qr,k);
    if(ql > qr) return;
    if(ql <= l && r <= qr) return nd[p].add(k);
    int mid = l+r>>1;pushdown(p);
    if(ql <= mid) change(ls(p),l,mid,ql,qr,k);
    if(qr > mid) change(rs(p),mid+1,r,ql,qr,k);
    pushup(p);
}
inline ll query(int p,int l,int r,int ql,int qr)
{
    if(ql > qr) return 0;
    if(ql <= l && r <= qr) return nd[p].maxd;
    int mid = l+r>>1;pushdown(p);
    ll nmax = 0;
    if(ql <= mid) gmax(nmax,query(ls(p),l,mid,ql,qr));
    if(qr > mid) gmax(nmax,query(rs(p),mid+1,r,ql,qr));
    return nmax;
}
ll n,m,k,d;
struct chl{ll x,y,v;}q[N];
ll key[N*3],kcnt;
bool cmp(chl a,chl b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.x-a.y < b.x-b.y;
}
ll dp[N][1005];
void solve1()
{
    int t = read();
    while(t--)
    {
        n = read();m = read();k = read();d = read();
        rfor(i,0,m)
            rfor(j,0,k) dp[i][j] = -1e18;
        rfor(i,1,m)
        {
            q[i].x = read();q[i].y = read();q[i].v = read();
        }
        sort(q+1,q+m+1,cmp);
        dp[0][0] = 0;
        rfor(i,1,m)
        {
            ll nmax = 0;
            rfor(j,0,k)
            {
                gmax(nmax,dp[i-1][j]);
            }
            rfor(j,0,min(k,q[i].y))
            {
                dp[i][j] = nmax - d*j;
            }
            rfor(j,q[i].x-q[i-1].x,k) gmax(dp[i][j],dp[i-1][j-q[i].x+q[i-1].x]-d*(q[i].x-q[i-1].x)+(j>=q[i].y?q[i].v:0));
 //           if(q[i].y<=k) gmax(dp[i][q[i].y],nmax-d*q[i].y+q[i].v);
        }
        ll nmax = 0;
        rfor(j,0,k) gmax(nmax,dp[m][j]);
        cout << nmax << '\n';
    }
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c = read();
    if(c <= 9 ||c == 15 || c== 16)
    {
        solve1();
        return 0;
    }
    int t = read();
    while(t--)
    {
        n = read();m = read();k = read();d = read();kcnt = 0;
        rfor(i,1,m)
        {
            q[i].x = read();q[i].y = read();q[i].v = read();
            key[++kcnt] = q[i].x;
            key[++kcnt] = q[i].x+1;
            key[++kcnt] = q[i].x-q[i].y+1;
        }
        sort(q+1,q+m+1,cmp);
        sort(key+1,key+kcnt+1);
        kcnt = unique(key+1,key+kcnt+1)-key-1;
        build(1,1,kcnt);reverse(key+1,key+kcnt+1);
        ll lastmax = 0;
        for(int i=1,l=kcnt+1,r=kcnt,p = kcnt+1;i <= m;i++)
        {
            gmax(lastmax,query(1,1,kcnt,l,r));
            int nl = l;
            while(nl>1 && key[nl-1] <= q[i].x)
            {
                nl--;
               // cout << "change:" << nl << ' ' << -d*(q[i].x-key[nl]+1) << '\n';
                /*if(l==kcnt+1 || key[nl]!=key[l]+1)*/ change(1,1,kcnt,nl,nl,-d*(q[i].x-key[nl]+1));
            }
            int nr = r;
            while(nr > nl && q[i].x-key[nr] >= k) nr--;
            gmin(p,nr+1);
            while(p>1 && q[i].x-key[p-1]+1 >= q[i].y) p--;
            change(1,1,kcnt,nl,l-2,lastmax);
            change(1,1,kcnt,l,nr,-d*(q[i].x-key[l]));
            change(1,1,kcnt,p,nr,q[i].v);
/*
            cout << "change:" << nl << ' ' <<l-2 << ' '<< lastmax << '\n';
            cout << "change:" << p << ' ' << nr << ' ' << q[i].v << '\n';
            rfor(i,1,kcnt) cout << query(1,1,kcnt,i,i) <<' ';cout << '\n';
            cout <<"maxd:"<< nd[1].maxd <<'\n';
            cout << nl <<' ' << nr << '\n';
//*/
            l = nl,r = nr;
        }
        cout << nd[1].maxd << '\n';
    }
    return 0;
}
/*
我好像调不出来了。
暴力也挂了。
怎么办，遗憾离场了。！！！！！！
*/
