#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
int n,m,k;
int vis[MAXN];
vector<int> edge[MAXN];
struct Node
{
    int id,dis;
};
int bfs(int s)
{
    queue<Node> q;
    q.push((Node){s,0});
    vis[s]=1;
    while(!q.empty())
    {
        Node cur=q.front();
        q.pop();
        int u=cur.id,dis=cur.dis;
        for(auto i=edge[u].begin();i!=edge[u].end();i++)
        {
            int v=*i;
            if(v==n)
            {
                if((dis+1)%k==0)
                {
                    return dis+1;
                }
                else
                {
                    continue;
                }
            }
            if(!vis[v])
            {
                vis[v]=1;
                q.push((Node){v,dis+1});
            }
        }
    }
    return -1;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,a;
        scanf("%d %d %d",&u,&v,&a);
        if(a!=0)
        {
            printf("-1\n");
            return 0;
        }
        edge[u].push_back(v);
    }
    printf("%d\n",bfs(1));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
