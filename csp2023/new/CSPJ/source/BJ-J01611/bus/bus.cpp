#include<bits/stdc++.h>
using namespace std;
#define endl "\n";

bool vis[10005];
int n, m, k, dist[10005];
vector<int> g[10005];


void dfs(int u)
{
    if(u == n)
    {
        return;
    }
    vis[u] = 1;
    dist[u]++;
    for(auto v:g[u])
    {
        if(vis[v])
            continue;
        dist[v]++;
        dfs(v);
    }
}

int main()
{
    freopen("bus.in", "r",, stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v, a;
        cin >> u >> v >> a;
        g[u].push_back(v);
    }
    dfs(1);
    for(int i = dist[n]; i <= 5000000; i++)
        if(i % k == 0)
        {
            cout << i << endl;
            return 0;
        }
    return 0;
}