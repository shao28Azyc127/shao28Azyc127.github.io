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
#define maxn 2000010
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

int tot,cnt,Beg;
int b[maxn],tb;
map<string,int> hsh;
struct Class{ int sz,st; } a[maxn];
struct Var{ string name; int type,sz,beg,st; } V[maxn];
vector<Var> g[maxn];

int dv(int x,int y) { return (x+y-1)/y; }

void ins()
{
    string Name,type; int K;
    cin>>type>>K;
    string name0=Name;
    hsh[type]=++tot;

    int temp=0,st=0;
    Var son;
    while(K--)
    {
        cin>>type>>Name;
        int v=hsh[type];
        son.name=Name,son.type=v,son.sz=a[v].sz,son.st=a[v].st;
        son.beg=dv(temp,son.st)*son.st,temp=son.beg+son.sz;
        V[++cnt]=son;
        g[tot].pb(son);
        up(st,son.st);
    }
    a[tot].st=st,a[tot].sz=dv(temp,st)*st;
    printf("%lld %lld\n",a[tot].sz,a[tot].st);
}
void def()
{
    string Name,type;
    cin>>type>>Name;
    V[++cnt].name=Name,V[cnt].type=hsh[type],V[cnt].sz=a[hsh[type]].sz,V[cnt].st=a[hsh[type]].st;
    V[cnt].beg=dv(Beg,V[cnt].st)*V[cnt].st,Beg=V[cnt].beg+V[cnt].sz;
    g[0].pb(V[cnt]);
    printf("%lld\n",V[cnt].beg);
}
void fnd()
{
    string str; cin>>str;
    str+=".";
    int len=str.size(),ans=0,o=0;
    string name;
    fup(i,0,len-1)
    {
        if(str[i]!='.') name+=str[i];
        else
        {
            for(Var son:g[o]) if(son.name==name)
            {
                ans+=son.beg,name.clear(),o=son.type;
                break;
            }
        }
    }
    printf("%lld\n",ans);
}
void get()
{
    int addr=read(),o=0;
    string ans;
    while(true)
    {
        int type=-1; string name;
        Var tar;
        if(g[o].empty())
        {
            if(!o) return puts("ERR"),void();
            for(int i=0;i<(int)(ans.size()-1);i++) cout<<ans[i];
            return puts(""),void();
        }
        for(Var son:g[o]) if(addr>=son.beg&&addr<=son.beg+son.sz-1)
        {
            type=son.type,name=son.name,tar=son;
            break;
        }
        if(type==-1) return puts("ERR"),void();
        addr-=tar.beg,ans+=name,ans+=".",o=type;
    }
}

signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    hsh["byte"]=1,a[++tot].sz=1,a[tot].st=1;
    hsh["short"]=2,a[++tot].sz=2,a[tot].st=2;
    hsh["int"]=3,a[++tot].sz=4,a[tot].st=4;
    hsh["long"]=4,a[++tot].sz=8,a[tot].st=8;


    int T=read();
    while(T--)
    {
        int op=read();
        if(op==1) ins();
        else if(op==2) def();
        else if(op==3) fnd();
        else get();
    }
    return 0;
}
