#include <bits/stdc++.h>

#define Node pair<int, int>
#define V first
#define ID second

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e4 + 5;
int n, m, k;
struct Edge
{
    int u, v, a;
};
vector<Edge> g[N];
bool vis[N];
int dist[N];

inline bool relax(Edge e)
{
    if (dist[e.u] + 1 < dist[e.v])
    {
        dist[e.v] = dist[e.u] + 1;
        return true;
    }
    return false;
}

void dijkstra()
{
    priority_queue<Node, vector<Node>, greater<Node>> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    q.push({0, 1});

    while (!q.empty())
    {
        int u = q.top().ID;
        q.pop();
        if (vis[u]) continue;
        for (auto e : g[u])
            if (relax(e))
                q.push({dist[e.v], e.v});
        vis[u] = true; 
    }
}

int main()
{
    ifstream cin("bus.in");
    ofstream cout("bus.out");
    ios::sync_with_stdio(false);

    bool a_is_zero = true;
    cin >> n >> m >> k;

    while (m--)
    {
        int u, v, a;
        cin >> u >> v >> a;
        g[u].push_back({u, v, a});
        if (a) a_is_zero = false;
    }

    if (k == 1 && a_is_zero)
    {
        dijkstra();
        cout << (dist[n] == INF ? -1 : dist[n]) << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}