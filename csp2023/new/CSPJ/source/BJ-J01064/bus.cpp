#include <bits/stdc++.h>
#define int long long
#define MAXN 10010
#define MAXK 105
#define INF LONG_LONG_MAX
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,k,u,v,w,ans=INF,vis[MAXN];
struct edge
{
    int u,v,t;
};
vector<edge> p[MAXN];
void dfs(int x,int d,int minstart)
{
    if(x==n)
    {
        if(d%k) return;
        if(minstart==0) ans=min(ans,d);
        else if(minstart%k==0) ans=min(ans,minstart+d);
        else ans=min(ans,minstart/k*k+k+d);
        return;
    }
    vis[x]=1;
    for(int i=0;i<p[x].size();i++)
    {
        int v=p[x][i].v,t=p[x][i].t;
        if(!vis[v])
            dfs(v,d+1,max(minstart,t-d));
    }
    vis[x]=0;
}
int vis2[MAXN][MAXK];
queue<pii> Q;
void bfs()
{
    Q.push({1,0}); vis2[1][0]=1;
    while(!Q.empty())
    {
        int x=Q.front().fi,d=Q.front().se;
        Q.pop();
        if(x==n)
        {
            if(d%k==0)
                ans=min(ans,d);
        }
        for(int i=0;i<p[x].size();i++)
        {
            int v=p[x][i].v,t=p[x][i].t;
            if(!vis2[v][(d+1)%k])
            {
                vis2[v][(d+1)%k]=1;
                Q.push({v,d+1});
            }
        }
    }
    if(ans==INF) cout<<-1;
    else cout<<ans;
}
/*
struct node
{
    int x,d,minstart;
};
int vis3[MAXN][MAXK];
void BFS()
{
    queue<node> Q;
    Q.push({1,0,0}); vis3[1][0]=1;
    while(!Q.empty())
    {
        int x=Q.front().x,d=Q.front().d,minstart=Q.front().minstart;
        Q.pop();
        if(x==n)
        {
            if(d%k==0)
            {
                if(minstart==0) ans=min(ans,d);
                else if(minstart%k==0) ans=min(ans,minstart+d);
                else ans=min(ans,minstart/k*k+k+d);
            }
        }
        for(int i=0;i<p[x].size();i++)
        {
            int v=p[x][i].v,t=p[x][i].t;
            if(!vis3[v][(d+1)%k])
            {
                vis3[v][(d+1)%k]=1;
                Q.push({v,d+1});
            }
        }
    }
    cout<<ans;
}*/
signed main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;bool flag=true;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        p[u].push_back({u,v,w});
        if(w) flag=false;
    }
    if(flag)//a[i]==0
    {
        bfs();
        return 0;
    }
    
    dfs(1,0,0);
    if(ans==INF) cout<<-1;
    else cout<<ans;
    return 0;
}
