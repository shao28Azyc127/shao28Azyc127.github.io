#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,m,ans;
int now[N<<1],val[N<<1],sz[N<<1],dfn[N<<1],low[N<<1],cnt,st[N<<1],tp,tot,scc[N<<1];
bool vis[N<<1];
vector<int>G[N<<1];
void tarjan(int u)
{
    dfn[u]=low[u]=++cnt;
    st[++tp]=u,vis[u]=1;
    for(int v:G[u])
    {
        if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
        else if(vis[v])low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        tot++;
        int v=-1;
        while(v!=u)
        {
            v=st[tp--];
            if(v<=n)sz[tot]++;
            if(v==u+n||v==u-n||val[v])scc[tot]=1;
            vis[v]=0;
        }
    }
}
void dfs(int u,int rt)
{
    sz[rt]++;
    vis[u]=1;
    if(val[u])val[rt]=1;
    for(int v:G[u])
    {
        if(vis[v])continue;
        dfs(v,rt);
    }
}
void solve0()
{
    scanf("%d%d",&n,&m);
    memset(val,0,sizeof(val));
    memset(sz,0,sizeof(sz));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)G[i].clear();
    ans=0;
    for(int i=1;i<=m;i++)
    {
        char op;
        scanf(" %c",&op);
        if(op=='+')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].emplace_back(y);
            G[y].emplace_back(x);
        }
        else
        {
            int x;
            scanf("%d",&x);
            val[x]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i,i),ans+=sz[i]*val[i];
    }
    printf("%d\n",ans);
}
void solve()
{
    scanf("%d%d",&n,&m);
    iota(now+1,now+n*2+1,1);
    memset(dfn,0,sizeof(dfn));
    memset(val,0,sizeof(val));
    memset(scc,0,sizeof(scc));
    memset(sz,0,sizeof(sz));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=2*n;i++)G[i].clear();
    tp=tot=cnt=ans=0;
    for(int i=1;i<=m;i++)
    {
        char op;
        scanf(" %c",&op);
        if(op=='+')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            now[x]=y;
            now[x+n]=y+n;
        }
        else if(op=='-')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            now[x]=y+n;
            now[x+n]=y;
        }
        else
        {
            int x;
            scanf("%d",&x);
            if(op=='U')val[x]=val[x+n]=1;
            else val[x]=val[x+n]=0;
            now[x]=x,now[x+n]=x+n;
        }
    }
    for(int i=1;i<=2*n;i++)G[now[i]].emplace_back(i),G[i].emplace_back(now[i]);
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    for(int i=1;i<=tot;i++)ans+=sz[i]*scc[i];
    printf("%d\n",ans);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c!=5&&c!=6)while(t--)solve();
    else while(t--)solve0();
    return 0;
}
