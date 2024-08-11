#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int NR = 200010;
vector<int> G[NR], id[NR];
bool vis[NR];
int a[NR], dis[NR];
int s, mx, n, m, ans = 1e9, k;
void spfa(int s)
{
    memset(dis, 999999, sizeof dis);
    dis[s] = 0, vis[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                if (!vis[v]) q.push(v), vis[v] = true;
            }
        }
    }
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v >> a[i];
        G[u].push_back(v);
    }
    spfa(1);
    cout << dis[n] << '\n';
    return 0;
}
