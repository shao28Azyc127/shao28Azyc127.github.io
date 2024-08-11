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
int n,m;
int N;
int f[maxn<<2];
int las[maxn],il[maxn];
int getfa(int x){while(x!=f[x]) x=f[x]=f[f[x]];return x;}
void merge(int x,int y)
{
    if(getfa(x)!=getfa(y)) f[getfa(x)]=getfa(y);
}
void solve()
{
    cin>>n>>m;
    N=(n+m)*2+3;
    for(int i=1;i<=N;i++) f[i]=i;
    for(int i=1;i<=n;i++) las[i]=i,il[i]=i+n;
    for(int i=1;i<=m;i++)
    {
        string op;
        cin>>op;
        if(op=="+")
        {
            int x,y;cin>>x>>y;
            merge(i+2*n,las[y]);
            merge(i+2*n+m,il[y]);
            las[x]=i+2*n;il[x]=i+2*n+m;
        }
        else if(op=="-")
        {
            int x,y;cin>>x>>y;
            merge(i+2*n,il[y]);
            merge(i+2*n+m,las[y]);
            las[x]=i+2*n;il[x]=i+2*n+m;
        }
        else
        {
            int x;cin>>x;
            int v;
            if(op=="U") v=1;
            if(op=="T") v=2;
            if(op=="F") v=0;
            merge(i+2*n,N-v);
            merge(i+2*n+m,N-2+v);
            las[x]=i+2*n;il[x]=i+2*n+m;
        }
    }
    for(int i=1;i<=n;i++)
    {
        merge(i,las[i]);merge(i+n,il[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int t1=getfa(i),t2=getfa(i+n);
        if(t1==t2) ans++;
    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>__>>_;
    //_=1;
    while(_--)
    {
        solve();
    }
    return 0;
}
