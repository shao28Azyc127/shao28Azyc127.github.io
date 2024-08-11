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
#define fup(i,l,r) for(int i=l;i<=r;i++)
#define fdn(i,l,r) for(int i=r;i>=l;i--)
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define maxn 100010
#define mod 998244353
#define modd (int)(1e9+7)
#define x first
#define y second
#define int ll
using namespace std;

bool up(int &x,int y) { return (x<y?x=y,1:0); }
bool down(int &x,int y) { return (x>y?x=y,1:0); }
void add(int &x,int y) { x=(x+y)%mod; }
int ksm(int a,int b) { int r=1; for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) r=1ll*r*a%mod; return r; }

int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int n,fa[maxn],x[maxn];
struct Node{
    int a,b,c;
    bool operator<(const Node &W) const {
        return b<W.b;
    }
}v[maxn];
vector<int> g[maxn];
int dep[maxn];
bool st[maxn];
int dp[(1<<20)+10];

int cal(int i,int l,int r)
{
    if(v[i].c>=0) return v[i].b*(r-l+1)+v[i].c*(r-l+1)*(r+l)/2;
    else
    {
        int c=-v[i].c,b=v[i].b,p=(b+c-1)/c;
        if(p<=l) return r-l+1;
        else if(p>r) return b*(r-l+1)-c*(r-l+1)*(r+l)/2;
        else return b*(p-l)-c*(p-l)*(p+l-1)/2+(r-p+1);
    }
}
int get(int i,int lim)
{
    int l=1,r=lim;
    if(cal(i,1,lim)<v[i].a) return -1;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(cal(i,mid,lim)>=v[i].a) l=mid;
        else r=mid-1;
    }
    return l;
}

bool check()
{
    fup(i,0,(1<<n)-1) dp[i]=0;
    dp[1]=1;
    for(int s=1;s<(1<<n);s++)
    {
        if(!dp[s]) continue;
        vector<int> ver,d;
        int cnt=0;
        fup(i,0,n-1) if(s>>i&1) cnt++,d.pb(i+1);
        for(int i:d) for(int j:g[i]) if(!(s>>(j-1)&1)) ver.pb(j);
        for(int j:ver) if(x[j]>=cnt+1) dp[s|(1<<(j-1))]=1;
    }

    return dp[(1<<n)-1];
}

void bf()
{
    int l=1,r=1e9;
    while(l<r)
    {
        int mid=(l+r)>>1;
        fup(i,1,n) x[i]=get(i,mid);
        bool flag=1;
        fup(i,1,n) if(x[i]==-1) { flag=0; break; }
        if(flag&&check()) r=mid;
        else l=mid+1;
    }
    return printf("%lld\n",l),void();
}
void solve2()
{
    int l=1,r=1e9;
    while(l<r)
    {
        int mid=(l+r)>>1;
        fup(i,1,n) x[i]=get(i,mid);
        bool flag=1;
        fup(i,1,n) if(x[i]<i) { flag=0; break; }
        if(flag) r=mid;
        else l=mid+1;
    }
    return printf("%lld\n",l),void();
}

bool check3()
{
    x[1]=-1;
    sort(x+1,x+n+1);
    fup(i,2,n) if(x[i]<i) return 0;
    return 1;
}
void solve3()
{
    int l=1,r=1e9;
    while(l<r)
    {
        int mid=(l+r)>>1;
        fup(i,1,n) x[i]=get(i,mid);
        bool flag=1;
        fup(i,1,n) if(x[i]==-1) { flag=0; break; }
        if(flag&&check3()) r=mid;
        else l=mid+1;
    }
    return printf("%lld\n",l),void();
}

signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    fup(i,1,n) v[i].a=read(),v[i].b=read(),v[i].c=read();
    bool line=1,flower=1;
    fup(i,1,n-1)
    {
        int x=read(),y=read();
        g[x].pb(y),g[y].pb(x);
        if(!(x==i&&y==i+1)) line=0;
        if(x!=1) flower=0;
    }
    fa[1]=-1;

    if(n<=20) bf();
    else if(line) solve2();
    else solve3();

    return 0;
}
