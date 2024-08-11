#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define _for1(i,a,b) for(int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
ll a[maxn],b[maxn],c[maxn],n;
struct Edge
{
    int u,v;
}e[maxn];
ll h[maxn],cnt;
void add_edge(int u,int v)
{
    e[++cnt].v=v;
    e[cnt].u=h[u];
    h[u]=cnt;
}
bool vis[maxn];
int f[maxn];
ll high[maxn];
vector<int> G[maxn];
void dfs(int u,int fa)
{
    for(int i=0;i<=G[u].size()-1;i++)
    {
        if(G[u][i]==fa) continue;
        else
        {
            f[G[u][i]]=u;
            dfs(G[u][i],u);
        }
    }
}
ll ans=0x3f3f3f3f;
void dfs1(int time)
{
    bool ok=1;
    _for(i,1,n)
    {
        if(!vis[i])
        {
            ok=0;
            break;
        }
    }
    if(ok)
    {
        ll exti=0;
        _for(i,1,n)
        {
            if(high[i]<a[i])
            {
                if(high[i]%a[i]==0)
                    exti=max(exti,high[i]/a[i]);
                else
                    exti=max(exti,high[i]/a[i]+1);
            }
        }
        ans=min(ans,exti+time);
        return;
    }
    _for(i,1,n)
    {
        if(vis[i])
        {
            high[i]+=max(b[i]+time*c[i],1ll);
        }
    }
    _for(i,1,n)
        if(!vis[i]&&vis[f[i]])
        {
            vis[i]=1;
            dfs1(time+1);
            vis[i]=0;
        }
}
ll d[maxn];
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    _for(i,1,n) cin>>a[i]>>b[i]>>c[i];
    bool ok2=1;
    _for(i,1,n-1)
    {
        ll u,v;
        cin>>u>>v;
        if(u!=i||v!=i+1) ok2=0;
        G[u].push_back(v);
        G[v].push_back(u);
        add_edge(u,v);
        add_edge(v,u);
    }
    bool Tr=1;
    _for(i,1,n)
    {
        if(c[i])
        {
            Tr=0;
            break;
        }
    }
    if(Tr)
    {
        ll ext=0;
        _for(i,1,n)
        {
            if(a[i]>n*b[i]) ext=max(ext,(a[i]%b[i]==0 ? ((a[i]-n*b[i])/b[i]):(((a[i]-n*b[i])/b[i])+1)));
        }
        cout<<n+ext<<endl;
        return 0;
    }
    if(ok2)
    {
        cout<<n<<endl;
        return 0;
    }
    dfs(1,0);
    vis[1]=1;
    high[1]=max(b[1]+c[1],1ll);
    dfs1(1);
    bool ok=1;
    cout<<ans<<endl;
    return 0;
}
