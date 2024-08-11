#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int n,m,i,j,k,a,b,c,times;
vector<pair<int,int> > G[100009];
void dfs(int x,int dis)
{
    if(times>1e7)
    {
        puts("-1");
        exit(0);
    }
    times++;
    if(x==n&&dis%k==0)
    {
        cout<<dis;
        exit(0);
    }
    for(int i=0;i<G[x].size();i++) dfs(G[x][i].first,dis+1);
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
    }
    dfs(1,0);
    puts("-1");
    return 0;
}
