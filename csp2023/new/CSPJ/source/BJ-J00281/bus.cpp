#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int n,m,k;
int a[20005];
vector<int> g[10005];
int dis[10005];
bool vis[10005];
signed main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(dis,0xffffff,sizeof(dis));
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        a[i] = w;
        g[u].push_back(v);

    }
    q.push(1);
    dis[1] = 0;
    vis[1] = 1;
    while(!q.empty())
    {

        int x = q.front();

        q.pop();
        vis[x] = 0;
        for(auto k : g[x])
        {
            if(dis[k] > dis[x] + 1)
            {

                dis[k] = dis[x] + 1;
                if(!vis[k])
                {

                    q.push(k);
                    vis[k] = 1;
                }
            }
        }
    }

    if(dis[n] % k == 0)
    {

        cout << dis[n] << endl;
    }
    else
    {

        cout << -1 <<endl;
    }
    return 0;
}
