#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
bool vis[1000005];
int n, m, k, u, v, a, dis[1000005], tmp;
struct Edge
{
    int v, a;
    friend bool operator<(Edge, Edge);
};
bool operator<(Edge a, Edge b)
{
    return a.a > b.a;
}
vector<Edge> e[10005];
priority_queue<Edge> q;
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> a;
        for (int j = 0; j < k; j++)
            e[u + j * n].push_back({v + (j + 1) % k * n, a});
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    q.push({1, 0});
    for (int i = 2; i <= n * k; i++)
        q.push({i, 0x3f3f3f3f});
    for (int i = 2; i <= n * k; i++)
    {
        while (vis[q.top().v])
            q.pop();
        int now = q.top().v;
        vis[now] = true;
        for (int j = 0; j < e[now].size(); j++)
        {
            int v = e[now][j].v;
            int a = e[now][j].a;
            int tmp = dis[now] + 1;
            if (tmp < a + 1)
                tmp += (a + k - tmp) / k * k;
            if (tmp < dis[v])
            {
                dis[v] = tmp;
                q.push({v, dis[v]});
            }
        }
    }
    if (dis[n] >= 0x3f3f3f30)
        cout << -1 << endl;
    else
        cout << dis[n] << endl;
    return 0;
}
