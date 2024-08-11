#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

vector<int> v[100005];

int n, m, k;
int vis[100005];

void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == n)
        {
            cout << vis[x];
            exit(0);
        }

        for (int i = 0; i < v[x].size(); ++i)
        {
            int y = v[x][i];
            if (vis[y] != -1) continue;
            vis[y] = vis[x] + 1;
            q.push(y);
        }
    }

}


int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    memset(vis, -1, sizeof(vis));
    cin >>n>> m>> k;
    if (k == 1)
    {
        for (int i = 1; i <= m; ++i)
        {
            int x, y, z;
            cin >> x >> y >> z;
            v[x].push_back(y);
        }
        bfs();
    }
    cout << -1;
    return 0;
}
