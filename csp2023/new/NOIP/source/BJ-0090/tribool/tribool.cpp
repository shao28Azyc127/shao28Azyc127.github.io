#include<bits/stdc++.h>
using namespace std;
const int N=400010;
int c,_;
int n,m,tot;
int fa[N];
bool vis[N];
int dfn[N],low[N],s[N],tp;
int co[N],tmp,sz[N];
vector<int>g[N];
bool ins[N];
int find(int x)
{
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
int cov(int x)
{
    if(x>2*n)return x-2*n;
    return x;
}
int rev(int x)
{
    if(x>n)return x-n;
    else return x+n;
}
void dfs(int u)
{
    dfn[u]=low[u]=++tot;
    ins[u]=1;
    s[++tp]=u;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(dfn[v]==0)
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]>=dfn[u])
    {
        ++tmp;
        while(s[tp]!=u)
        {
            co[s[tp]]=tmp;
            ins[s[tp]]=0;
            sz[tmp]++;
            tp--;
        }
        co[u]=tmp;
        ins[u]=0;
        sz[tmp]++;
        tp--;
    }
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>_;
    while(_--)
    {
        memset(vis,0,sizeof(vis));
        tmp=0;tot=0;tp=0;
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(ins,0,sizeof(ins));
        memset(co,0,sizeof(co));
        memset(sz,0,sizeof(sz));
        cin>>n>>m;
        for(int i=1;i<=2*n;i++)
        {
            fa[i]=i+2*n;
            g[i].clear();
        }
        for(int i=2*n+1;i<=4*n+4;i++)
        {
            fa[i]=i;
        }
        for(int i=1;i<=m;i++)
        {
            char opt;
            cin>>opt;
            if(opt=='U')
            {
                int x;
                cin>>x;
                fa[x]=(4*n+3);
                fa[x+n]=(4*n+3);
            }
            else if(opt=='T')
            {
                int x;
                cin>>x;
                fa[x]=(4*n+2);
                fa[x+n]=(4*n+1);
            }
            else if(opt=='F')
            {
                int x;
                cin>>x;
                fa[x+n]=(4*n+2);
                fa[x]=(4*n+1);
            }
            else if(opt=='+')
            {
                int x,y;
                cin>>x>>y;
                fa[x]=find(y);
                fa[x+n]=find(y+n);
            }
            else if(opt=='-')
            {
                int x,y;
                cin>>x>>y;
                fa[x]=find(y+n);
                fa[x+n]=find(y);
            }
        }
        int ans=0;
        for(int i=1;i<=2*n;i++)
        {
            if(cov(find(i))<=2*n)
            {
                int x=i,y=cov(find(i));
                if(x>y)swap(x,y);
                g[x].push_back(y);
                g[y].push_back(x);
                g[rev(y)].push_back(rev(x));
                g[rev(x)].push_back(rev(y));
                //cout<<"!!!\n";
            }
            else if(cov(find(i))==2*n+2)
            {
                g[rev(i)].push_back(i);
            }
            else if(cov(find(i))==2*n+1)
            {
                g[i].push_back(rev(i));
            }
            else
            {
                g[rev(i)].push_back(i);
                g[i].push_back(rev(i));
            }
        }
        for(int i=1;i<=n*2;i++)
        {
            if(!dfn[i])
            {
                dfs(i);
                
            }
        }
        for(int i=1;i<=2*n;i++)
        {
            //cout<<co[i]<<' ';
            if(co[i]==co[rev(i)])
            {
                vis[co[i]]=1;
                ans++;
            }
        }
        //cout<<'\n';
        cout<<ans/2<<'\n';
    }
}
