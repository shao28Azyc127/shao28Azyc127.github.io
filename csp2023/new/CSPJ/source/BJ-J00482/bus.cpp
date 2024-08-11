#include <bits/stdc++.h>
using namespace std;
vector<int>e[200005];
int vis[200005];
int dis[200005];
int spfa(int s,int t)
{
    queue<int>Q;
    Q.push(s);
    dis[s]=0;
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(int i=0;i<e[now].size();i++)
        {
            int nex=e[now][i];
            if(dis[nex]>dis[now]+1)
            {
                dis[nex]=dis[now]+1;
                Q.push(nex);
            }
        }
    }
    return dis[t];
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back(v);
    }
    for(int i=1;i<=m;i++)
        dis[i]=99999999;
    if(k==1)
    {
        cout<<1+spfa(1,n);
        return 0;
    }
    else cout<<-1;
    return 0;
}
