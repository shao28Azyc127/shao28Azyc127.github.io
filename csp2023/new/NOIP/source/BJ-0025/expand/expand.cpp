#include<bits/stdc++.h>
#define y1 hudxishx
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const int maxn=500005;
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
int n,m,q;
int a[maxn],b[maxn];
bool fl=false;
void cl()
{
    if(fl)
    {
        swap(n,m);
        for(int i=1;i<=Max(n,m);i++) swap(a[i],b[i]);
    }
}
int ax[maxn],an[maxn],bx[maxn],bn[maxn];
void sve()
{
    fl=false;
    if(a[1]>b[1])
    {
        swap(n,m);
        for(int i=1;i<=Max(n,m);i++) swap(a[i],b[i]);
        fl=true;
    }
    if(a[1]>=b[1]||a[n]>=b[m]) return cout<<"0",cl(),void();
    int ai=0,bi=0;an[0]=1e9;bn[0]=1e9;
    for(int i=1;i<=n;i++)
    {
        an[i]=Min(an[i-1],a[i]);
        ax[i]=Max(ax[i-1],a[i]);
        if(an[i]==a[i]) ai=i;
    }
    for(int i=1;i<=m;i++)
    {
        bn[i]=Min(bn[i-1],b[i]);
        bx[i]=Max(bx[i-1],b[i]);
        if(bx[i]==b[i]) bi=i;
    }
    //cout<<ai<<" "<<bi<<" "<<an[n]<<" "<<a[ai]<<" "<<bx[m]<<" "<<b[bi]<<"\n";
    if(an[n]>=bn[m]||ax[n]>=bx[m]) return cout<<"0",cl(),void();
    bool ans=true;
    int x=ai-1,y=bi-1;
    while(1)
    {
        //cout<<x<<" "<<y<<"\n";
        if(x<1||y<1) break;
        if(ax[x]<bn[y]) break;
        if(an[x]>=bn[y]&&ax[x]>=bx[y]){ans=false;break;}
        if(an[x]>=bn[y])
        {
            while(bn[y]<=an[x]||b[y]!=bx[y]) y--;
            if(ax[x]>=bx[y]){ans=false;break;}
            y--;
        }
        else if(ax[x]>=bx[y])
        {
            while(ax[x]>=bx[y]||a[x]!=an[x]) x--;
            if(an[x]>=bn[y]){ans=false;break;}
            x--;
        }
        else
        {
            while(an[x]!=a[x]) x--;
            while(bx[y]!=b[y]) y--;
            x--;
            y--;
        }
    }
    if(!ans) return cout<<"0",cl(),void();
    //cout<<"qwq\n";
    x=ai+1;y=bi+1;
    an[n+1]=bn[m+1]=1e9;
    ax[n+1]=bx[m+1]=0;
    for(int i=n;i>=1;i--)
    {
        an[i]=Min(an[i+1],a[i]);
        ax[i]=Max(ax[i+1],a[i]);
    }
    for(int i=m;i>=1;i--)
    {
        bn[i]=Min(bn[i+1],b[i]);
        bx[i]=Max(bx[i+1],b[i]);
    }
    while(1)
    {
        if(x>n||y>m) break;
        if(ax[x]<bn[y]) break;
        if(an[x]>=bn[y]&&ax[x]>=bx[y]){ans=false;break;}
        if(an[x]>=bn[y])
        {
            while(bn[y]<=an[x]||b[y]!=bx[y]) y++;
            if(ax[x]>=bx[y]){ans=false;break;}
            y++;
        }
        else if(ax[x]>=bx[y])
        {
            while(ax[x]>=bx[y]||a[x]!=an[x]) x++;
            if(an[x]>=bn[y]){ans=false;break;}
            x++;
        }
        else
        {
            while(an[x]!=a[x]) x++;
            while(bx[y]!=b[y]) y++;
            x++;y++;
        }
    }
    if(!ans) return cout<<"0",cl(),void();
    else return cout<<"1",cl(),void();
}
int ta[maxn],tb[maxn];
void solve()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i],ta[i]=a[i];
    for(int i=1;i<=m;i++) cin>>b[i],tb[i]=b[i];
    sve();
    while(q--)
    {
        int kx,ky;cin>>kx>>ky;
        for(int i=1;i<=n;i++) a[i]=ta[i];
        for(int i=1;i<=m;i++) b[i]=tb[i];
        for(int i=1;i<=kx;i++)
        {
            int x,y;cin>>x>>y;a[x]=y;
        }
        for(int i=1;i<=ky;i++)
        {
            int x,y;cin>>x>>y;b[x]=y;
        }
        sve();
    }
    cout<<"\n";
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>__;
    _=1;
    while(_--)
    {
        solve();
    }
    return 0;
}
