#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,m,k,ans=-1;
bool vis[10005];
vector<int> g[10005],w[10005];
struct node
{
    int t,x;
};
priority_queue<node> q;
bool operator<(node a,node b)
{
    return a.t<b.t;
}
void bfs()
{
    q.push(node{k,1});
    while(!q.empty())
    {
        node k=q.top();
        q.pop();
        int u=k.x;
        vis[u]=false;
        //cout<<u<<" "<<k.t<<endl;
        if(u==n)
        {
            ans=k.t;
            return;
        }
        int tt=k.t;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(!vis[v])
            {
                q.push(node{max(tt,w[u][i])+1,v});
                //cout<<w[u][i]<<"*"<<endl;
                vis[v]=true;
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,a;
        cin>>u>>v>>a;
        g[u].push_back(v);
        w[u].push_back(a);
    }
    bfs();
    //cout<<ans<<endl;
    if(ans==-1) cout<<-1<<endl;
    else
    {
        if(ans%k!=0) ans=ans/k*k+k;
        cout<<ans<<endl;
    }
    return 0;
}
