#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, k;
struct node {
    int v, w;
};
struct qu {
    int u, times;
};
bool operator < (qu x, qu y)
{
    return x.times > y.times;
}
vector<node> e[20005];
bool vis[10005];
int dis[10005];
void dijkstra()
{
    priority_queue<qu> q;
    q.push((qu){1, 0});
    for(int i = 1; i <= n; i++) dis[i] = INF;
    dis[1] = 0;
    while(!q.empty())
    {
        int u = q.top().u;
        q.pop();
        if(vis[u])  continue;
        vis[u] = 1;
        for(int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].v, a = e[u][i].w;
            //int add = max(0, a - dis[u]);
            int add = 0;
            while(a > add + dis[u]) add += k;
            if(dis[v] >= dis[u] + add + 1)
            {
                if(v == n && (dis[u] + add + 1) % k)  continue;
                dis[v] = dis[u] + add + 1;
                q.push((qu){v, dis[v]});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v, a;
        cin >> u >> v >> a;
        e[u].push_back((node){v, a});
    }
    dijkstra();
    //for(int i = 1; i <= n; i++) cout << dis[i] << " ";cout << endl;
    if(dis[n] == INF)   cout << -1;
    else    cout << dis[n];
    return 0;
}
/*
5 5 2
1 2 1
2 3 2
3 5 3
1 4 1
4 5 1
*/
