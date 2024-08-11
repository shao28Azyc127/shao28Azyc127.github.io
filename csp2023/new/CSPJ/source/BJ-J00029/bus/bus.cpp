#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e4 + 10;
vector<int> e[N];
long long dis[N];
bool vis[N];
queue<int> q;
int n, m, k;

long long bfs()
{
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        // cout << x << " " << dis[x] << " ";
        q.pop();
        if (x == n && dis[x] % k == 0) return dis[x];
        for (int i = 0; i < e[x].size(); i++)
        {
            // cout << e[x][i] << " ";
            q.push(e[x][i]);
            dis[e[x][i]] = dis[x] + 1;
        }
        // cout << endl;
    }
    return -1;
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    bool flag = true;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (w != 0) flag = false;
        e[u].push_back(v);
    }
    if (flag) cout << bfs() << endl;
    else cout << -1 << endl;
    return 0;
}
