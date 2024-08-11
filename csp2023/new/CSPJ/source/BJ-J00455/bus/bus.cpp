#include <bits/stdc++.h>
using namespace std;

int a[20005], g[10005][10005];
int n, m, k;
struct Node
{
    int step, x;
};
queue <Node> q;

int bfs()
{
    q.push(Node{0, 1});
    while (!q.empty())
    {
        int step = q.front().step, x = q.front().x;
        q.pop();
        if (x == n)
            if (step % k == 0) return step;
        for (int i = 1; i <= m; i++)
        {
            if (g[x][i] == 1) q.push(Node{step + 1, i});
        }
    }
    return -1;
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
        g[u][v] = 1;
    }
    cout << bfs() << endl;
    return 0;
}
