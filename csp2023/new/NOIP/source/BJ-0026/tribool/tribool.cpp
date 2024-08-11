#include <bits/stdc++.h>
#define rfor(i,l,r) for(int i=l;i<=r;i++)
#define irfor(i,r,l) for(int i=r;i>=l;i--)
#define ls(p) p<<1
#define rs(p) p<<1|1
#define mkp make_pair
#define x0 aiklsfhlasdkfghlkadrfhgasdfg
#define y0 zsfdkgjhlksdfhglksfdhglkasdf
#define y1 sklrluhgklahrgklsedrhgklfdhg
using namespace std;
typedef long long ll;typedef unsigned long long ull;typedef pair<int,int> pii;
inline ll read()
{
    ll x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-48;c=getchar();}
    return x*f;
}
inline void gmin(int &a,int b){if(b<a)a=b;}inline void gmax(int &a,int b){if(b>a)a=b;}
inline void gmin(ll &a,ll b){if(b<a)a=b;}inline void gmax(ll &a,ll b){if(b>a)a=b;}
inline int min(int a,int b){return a<b?a:b;}inline int max(int a,int b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}inline ll max(ll a,ll b){return a>b?a:b;}
const int N = 1e5+5,mod = 1e9+7;
int n,m;
struct X{int tag,key;}x[N];
struct edge{int to,key,nxt;edge(int to=0,int key=0,int nxt=0):to(to),key(key),nxt(nxt){}}e[N*2];int head[N],cnt;
void adde(int u,int v,int k){e[++cnt]=edge(v,k,head[u]);head[u]=cnt;}
int fil[N],ans;
int vis[N];
void dfs1(int u,int key)
{
    vis[u] = 1;fil[u] = key;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v = e[i].to,w = e[i].key*key;
        if(vis[v]) continue;
        dfs1(v,w);
    }
}
bool dfs2(int u,int key)
{
    vis[u] = 1;fil[u] = key;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v = e[i].to,w = e[i].key*key;
        if(vis[v])
        {
            if(fil[v] != w) return false;
            continue;
        }
        if(!dfs2(v,w)) return false;
    }
    return true;
}
void dfs3(int u)
{
    vis[u] = 3;fil[u] = 0;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v = e[i].to;
        if(vis[v] == 3) continue;
        dfs3(v);
    }
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> m;
        rfor(i,1,n) x[i].tag = 1,x[i].key = i,fil[i] = vis[i] = head[i] = 0;
        ans = cnt = 0;
        char s;int xi,xj;
        rfor(i,1,m)
        {
            cin >> s >> xi;
            if(s == '+' || s == '-')
            {
                cin >> xj;
                int w = (s=='+'?1:-1);
                if(x[xj].tag == 0)
                {
                    x[xi].tag = 0;
                    x[xi].key = x[xj].key*w;
                }
                else
                {
                    x[xi].tag = x[xj].tag*w;
                    x[xi].key = x[xj].key;
                }
            }
            else
            {
                x[xi].tag = 0;
                if(s == 'T') x[xi].key = 1;
                else if(s == 'F') x[xi].key = -1;
                else x[xi].key = 0;
            }
        }
        rfor(i,1,n) if(x[i].tag != 0) adde(i,x[i].key,x[i].tag),adde(x[i].key,i,x[i].tag);
        rfor(i,1,n) if(!vis[i] && x[i].tag==0) dfs1(i,x[i].key);
        rfor(i,1,n)
        {
            if(vis[i]) continue;
            if(!dfs2(i,1)) dfs3(i);
        }
        rfor(i,1,n) if(fil[i]==0) ans++;
        cout << ans << '\n';
    }
    return 0;
}
