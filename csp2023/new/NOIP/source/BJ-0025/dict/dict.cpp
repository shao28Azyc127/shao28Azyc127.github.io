#include<bits/stdc++.h>
#define y1 hudxishx
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const int maxn=3005;
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
string s;
int a[maxn][maxn],mx[maxn],c[30];
int b[maxn];
int id;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) mx[i]=30;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++) c[s[j]-'a']++;
        int tp=0;
        for(int j=25;j>=0;j--) for(int k=1;k<=c[j];k++) a[i][++tp]=j;
        for(int j=0;j<26;j++) c[j]=0;
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]<mx[j])
            {
                for(int k=1;k<=m;k++) mx[k]=a[i][k];
                id=i;
                break;
            }
            else if(a[i][j]>mx[j]) break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==id)
        {
            cout<<"1";continue;
        }
        for(int j=1;j<=m;j++) b[j]=a[i][j];
        reverse(b+1,b+m+1);
        bool fl=true;
        for(int j=1;j<=m;j++)
        {
            if(b[j]<mx[j])
            {
                fl=false;cout<<"1";break;
            }
            else if(b[j]>mx[j]) break;
        }
        if(fl) cout<<"0";
    }
    cout<<"\n";
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cin>>_;
    _=1;
    while(_--)
    {
        solve();
    }
    return 0;
}
