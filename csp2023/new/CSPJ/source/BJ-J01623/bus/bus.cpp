#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, k;
int g[10005][10005];

struct node
{
    int x, t;
};

bool operator< (const node& x, const node& y)
{
    return x.t > y.t;
}

int bfs()
{
    priority_queue<node> q;
    q.push({1, 0});
    while (1)
    {
        node a = q.top();
        q.pop();
        if (a.x == n && a.t % k == 0)
        {
            return a.t;
        }
        for (int i = 1; i <= n; i++)
        {
            if (g[a.x][i] > 1e6)
            {
                continue;
            }
            if (g[a.x][i] <= a.t)
            {
                q.push({i, a.t + 1});
            }
            else
            {
                q.push({i, a.t + (g[a.x][i] - a.t + k - 1) / k * k + 1});
            }
        }
    }
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= m; i++)
    {
        int u, v, a;
        cin >> u >> v >> a;
        g[u][v] = a;
    }
    cout << bfs();
    return 0;
}
