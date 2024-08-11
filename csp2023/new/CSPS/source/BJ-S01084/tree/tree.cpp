#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1145141919810;
const ll mod=998244353;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n;
ll a[100005],b[100005],c[100005];
vector<vector<ll> > tree(100005);
bool check(ll x)
{
    return 1;
}
ll fat[100005];
void dfs0(ll u,ll fa)
{
    fat[u]=fa;
    ll sz=tree[u].size();
    for(int i=0;i<sz;i++)
    {
        ll v=tree[u][i];
        if(v==fa)continue;
        dfs0(v,u);
    }
}
void solve0()
{
    dfs0(1,0);
    return;
}
bool check1(ll k,ll p,ll x)
{
    ll z=(a[p]+k-1)/k-b[p];
    if(z+z<=c[p]*(x+x+k-1))return 1;
    else return 0;
}
ll sol(ll p,ll x)
{
    ll l=0,r=1e18,res=0;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(check1(mid,p,x))r=mid-1,res=mid;
        else l=mid+1;
    }
    return res;
}
void solve1()
{
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,i+sol(i,i)-1);
    }
    cout<<ans<<'\n';
}
void solve()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read(),b[i]=read(),c[i]=read();
    }
    for(int i=1;i<n;i++)
    {
        ll u=read(),v=read();
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    solve1();
    return;
}
int main()
{
//    freopen("game.in","r",stdin);
//    freopen("game.out","w",stdout);
//    clock_t start=read();
    ll t=1;
    while(t--)solve();
//    clock_t end=read();
//    cout<<(end-start)*1.00/CLOCKS_PER_SEC<<'\n';
    return 0;
}