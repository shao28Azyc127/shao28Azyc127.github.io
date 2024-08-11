#include<bits/stdc++.h>
#define first fi
#define second se
#define make_pair mp
#define push_back pb
using namespace std;
typedef long long ll;
const int maxn=2000005;
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
int _,__;
int n;
string s;
int a[maxn];
int p[maxn][26];
int f[maxn];
ll ans;
void solve()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++) a[i]=s[i-1]-'a';
    for(int i=2;i<=n;i++)
    {
        if(a[i-1]==a[i])
        {
            f[i]=f[i-2]+1;
            for(int j=0;j<26;j++) p[i][j]=p[i-2][j];
            if(i!=2) p[i][a[i-2]]=i-2;
            continue;
        }
        int t=p[i-1][a[i]];
        if(!t) continue;
        f[i]=f[t-1]+1;
        for(int j=0;j<26;j++) p[i][j]=p[t-1][j];
        if(t!=1) p[i][a[t-1]]=t-1;
    }
    for(int i=1;i<=n;i++) ans+=f[i];
    cout<<ans<<"\n";
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    _=1;
    while(_--)
    {
        solve();
    }
    return 0;
}
