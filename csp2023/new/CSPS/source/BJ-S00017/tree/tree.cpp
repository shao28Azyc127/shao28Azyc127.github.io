#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef __int128 i128;
const int maxn=100005;
const ll mod=998244353;
void ad(int &x,int y){x+=y;if(x>=mod) x-=mod;}
void ad(ll &x,ll y){x+=y;if(x>=mod) x-=mod;}
void siu(int &x,int y){x-=y;if(x<0) x+=mod;}
void siu(ll &x,ll y){x-=y;if(x<0) x+=mod;}
void ad(int &x,int y,int z){x=y+z;if(x>=mod) x-=mod;}
void ad(ll &x,ll y,ll z){x=y+z;if(x>=mod) x-=mod;}
void siu(int &x,int y,int z){x=y-z;if(x<0) x+=mod;}
void siu(ll &x,ll y,ll z){x=y-z;if(x<0) x+=mod;}
ll qpow(ll aa,ll bb){ll res=1;while(bb){if(bb&1) res=res*aa%mod;aa=aa*aa%mod,bb>>=1;}return res;}
inline int Max(int x,int y){return x>y?x:y;}
inline int Min(int x,int y){return x<y?x:y;}
inline int Max(ll x,ll y){return x>y?x:y;}
inline int Min(ll x,ll y){return x<y?x:y;}
inline void tmx(int &x,int y){if(x<y) x=y;}
inline void tmn(int &x,int y){if(x>y) x=y;}
inline void tmx(ll &x,ll y){if(x<y) x=y;}
inline void tmn(ll &x,ll y){if(x>y) x=y;}
int _,__;
int n;
ll a[maxn],b[maxn],c[maxn],d[maxn];
i128 s[maxn];
vector<int> g[maxn];
i128 calc(int x,ll r)
{
    if(r==0) return 0;
    if(c[x]<0&&r>=d[x]) return s[x]+r-d[x]+1;
    i128 bg=b[x]+c[x],ed=b[x]+c[x]*r;
    return (bg+ed)*r/2;
}
int lim[maxn];
void dfs(int u,int fro)
{
    for(auto v:g[u])
    {
        if(v==fro) continue;
        dfs(v,u);
        tmn(lim[u],lim[v]);
    }
}
bool check(ll x)
{
    for(int i=1;i<=n;i++)
    {
        i128 sum=calc(i,x);
        if(sum<a[i]) return false;
        int l=1,r=x;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(sum-calc(i,mid-1)<a[i]) r=mid-1;
            else l=mid+1,lim[i]=mid;
        }
    }
    sort(lim+1,lim+n+1);
    for(int i=1;i<=n;i++) if(lim[i]<i) return false;
    return true;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(c[i]<0)
        {
            d[i]=(b[i]-1)/(-c[i])+1;
            if(d[i]==1) continue;
            i128 bg=b[i]+c[i],ed=b[i]+c[i]*(d[i]-1);
            s[i]=(bg+ed)*(d[i]-1)/2;
        }
    }
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;g[u].push_back(v);g[v].push_back(u);
    }
    int l=n,r=1000000000,res=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) res=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<res<<"\n";
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    _=1;
    while(_--)
    {
        solve();
    }
    return 0;
}
