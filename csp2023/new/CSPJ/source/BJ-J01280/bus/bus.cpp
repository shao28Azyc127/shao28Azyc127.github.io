#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e4 + 5;
long long dis[N]; bool vis[N];
vector<int> g[N]; int n;
void dijkstra(int s)
{
    for (int i = 1; i <= n; i ++)
        dis[i] = 1e18 + 7;
    dis[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto v : g[u])
            if (dis[v] > dis[u] + 1ll)
                dis[v] = dis[u] + 1ll, q.push(v);
    }
}
int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    ios::sync_with_stdio(false);

    int m, k; cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
    }
    dijkstra(1);
    cout << (dis[n] + 1ll * k - 1ll) / k * k;

    return 0;
}
