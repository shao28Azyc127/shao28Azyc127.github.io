#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e4+5;
struct nd{int id,s;};
int n,m,k,ans=1e9;
int q[N],vis[N];
nd a[N][M];
//queue<int> q;
void dfs(int x,int t)
{
    if(vis[x]==1)
    {
        return ;
    }

    if(x==n )
    {
        if(t%k==0) ans=min(ans,t);
        return ;
    }
    vis[x]=1;
    for(int i=1;i<=q[x];i++)
    {
        if(t>=a[x][i].s)  dfs(a[x][i].id,t+1);
    }
    vis[x]=0;
}
int  main()
{
    freopen("bus.in","w",stdin);
    freopen("bus.out","r",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int u,v,b;
        cin>>u>>v>>b;
        q[u]++;
        a[u][q[u]].id=v;
        a[u][q[u]].s =b;
    }
    dfs(1,k);
    if(ans==1e9)  cout<<"-1"<<endl;
    else cout<<ans<<endl;
    return 0;
}
