#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
bool g[10005][10005],vis[10005];
int n,m,k,ans;
struct node{
    int x,dis;
};
queue<node> q;
int bfs()
{
    q.push(node{1,0});
    vis[1]=true;
    while(!q.empty())
    {
        int x=q.front().x,dis=q.front().dis;
        q.pop();
        if(x==n) return dis;
        for(int i=1;i<=n;i++)
        {
            if(g[x][i])
            {
                if(vis[i]) continue;
                q.push(node{i,dis+1});
            }
        }
    }
    return -1;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,a;
        cin>>u>>v>>a;
        g[u][v]=true;
    }
    int ans=bfs();
    if(ans==-1) cout<<ans<<endl;
    else if(ans%k==0) cout<<ans<<endl;
    else cout<<(ans/k+1)*k<<endl;
    return 0;
}
