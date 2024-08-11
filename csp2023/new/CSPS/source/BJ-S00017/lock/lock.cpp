#include<bits/stdc++.h>
#define first fi
#define second se
#define make_pair mp
#define push_back pb
using namespace std;
typedef long long ll;
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
int _,__;
int n;
int a[10][6];
int r[6];
int ans;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) cin>>a[i][j];
    for(r[1]=0;r[1]<=9;r[1]++)
       for(r[2]=0;r[2]<=9;r[2]++)
            for(r[3]=0;r[3]<=9;r[3]++)
                for(r[4]=0;r[4]<=9;r[4]++)
                    for(r[5]=0;r[5]<=9;r[5]++)
                    {
                        bool fl=true;
                        for(int i=1;i<=n;i++)
                        {
                            int mx=0,mn=6;
                            for(int j=1;j<=5;j++) if(a[i][j]!=r[j]) mx=Max(mx,j),mn=Min(mn,j);
                            if(mx==0)
                            {
                                fl=false;break;
                            }
                            if(mx==mn) continue;
                            else if(mn<mx-1)
                            {
                                fl=false;break;
                            }
                            else
                            {
                                int t1=(a[i][mn]-r[mn]+10)%10,t2=(a[i][mx]-r[mx]+10)%10;
                                if(t1!=t2)
                                {
                                    fl=false;break;
                                }
                            }
                        }
                        if(fl) ans++;
                    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    _=1;
    while(_--)
    {
        solve();
    }
    return 0;
}
