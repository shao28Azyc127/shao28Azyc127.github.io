#include<bits/stdc++.h>
#define first fi
#define second se
#define make_pair mkp
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
inline void tmx(int &x,int y){if(x<y) x=y;}
inline void tmn(int &x,int y){if(x>y) x=y;}
inline void tmx(ll &x,ll y){if(x<y) x=y;}
inline void tmn(ll &x,ll y){if(x>y) x=y;}
int _,__;
int n;
string s[4]={"byte","short","int","long"};
map<string,int> mp,mp1;
struct node
{
    string ne;
    int k;
    map<string,int> mp;
    int id[105];
    ll bg[105],siz[105];
    ll sz;
    int x;
    string s[105];
}a[105];
string q[105];
int onw;
string ne[105];
int id[105];
ll bg[105],sz[105];
ll tp;
ll ans;
string res[105];
bool vis[105];
void solve()
{
    cin>>n;
    mp[s[0]]=0;mp[s[1]]=-1;mp[s[2]]=-2;mp[s[3]]=-3;
    for(int i=1;i<=n;i++)
    {
        int op;cin>>op;
        if(op==1)
        {
            cin>>a[i].ne;mp[a[i].ne]=i;
            cin>>a[i].k;
            ll nw=0;
            for(int j=1;j<=a[i].k;j++)
            {
                string tmp;cin>>tmp;
                a[i].id[j]=mp[tmp];
                int x;ll ts;
                if(a[i].id[j]<=0) tmx(a[i].x,1<<(-a[i].id[j])),x=ts=(1<<(-a[i].id[j]));
                else tmx(a[i].x,a[a[i].id[j]].x),x=a[a[i].id[j]].x,ts=a[a[i].id[j]].sz;
                a[i].bg[j]=(nw%x==0?nw:nw/x*x+x);nw=a[i].bg[j]+ts;
                a[i].siz[j]=ts;
                cin>>a[i].s[j];
                a[i].mp[a[i].s[j]]=j;
            }
            a[i].sz=(nw%a[i].x==0?nw:nw/a[i].x*a[i].x+a[i].x);
            cout<<a[i].sz<<" "<<a[i].x<<"\n";
        }
        if(op==2)
        {
            vis[i]=true;
            string tmp;cin>>tmp;id[i]=mp[tmp];cin>>ne[i];mp1[ne[i]]=i;
            int x;
            if(id[i]<=0) sz[i]=x=(1<<(-id[i]));
            else sz[i]=a[id[i]].sz,x=a[id[i]].x;
            bg[i]=(tp%x==0?tp:tp/x*x+x);tp=bg[i]+sz[i];
            cout<<bg[i]<<"\n";
        }
        if(op==3)
        {
            string s;cin>>s;
            for(int j=0;j<=onw;j++) q[j]="";
            onw=0;
            ans=0;int len=s.length();
            for(int j=0;j<s.length();j++)
            {
                if(s[j]=='.') onw++;
                else if(s[j]>='a'&&s[j]<='z') q[onw]+=s[j];
                else break;
            }
            int qwq=mp1[q[0]];
            if(onw==0)
            {
                cout<<bg[qwq]<<"\n";continue;
            }
            ans=bg[qwq];qwq=id[qwq];
            for(int j=1;j<=onw;j++)
            {
                int t=a[qwq].mp[q[j]];
                ans+=a[qwq].bg[t];qwq=a[qwq].id[t];
            }
            cout<<ans<<"\n";
        }
        if(op==4)
        {
            ll ar;cin>>ar;
            int t=0;
            for(int j=1;j<i;j++) if(vis[j]&&bg[j]<=ar) t=j;
            ar-=bg[t];
            if(ar>=sz[t])
            {
                cout<<"ERR\n";continue;
            }
            if(id[t]<=0)
            {
                cout<<ne[t]<<"\n";continue;
            }
            bool fl=true;
            res[0]=ne[t];t=id[t];
            for(onw=1;;onw++)
            {
                int qwq=upper_bound(a[t].bg+1,a[t].bg+a[t].k+1,ar)-a[t].bg-1;
                ar-=a[t].bg[qwq];
                if(ar>=a[t].siz[qwq])
                {
                    fl=false;break;
                }
                res[onw]=a[t].s[qwq];
                t=a[t].id[qwq];if(t<=0) break;
            }
            if(!fl) cout<<"ERR\n";
            else
            {
                for(int j=0;j<=onw;j++)cout<<res[j]<<(j==onw?'\n':'.');
            }
        }
    }
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    _=1;
    while(_--)
    {
        solve();
    }
    return 0;
}
