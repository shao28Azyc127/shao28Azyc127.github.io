#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n, m, k, dis[10005][105], c;
vector<int> g[20005], a[20005];
bool vis[10005], f;
bool dfs(int mid)
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[n][0] = 1e9;
    queue<int> q;
    q.push(1);
    dis[1][0] = mid;
    vis[1] = 1;
    while(!q.empty())
    {
        c++;
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = 0; i < g[x].size(); i++)
        {
            int y = g[x][i];
            for (int j = 0; j < k; j++)
            {
                if (a[x][i] > mid + dis[x][j]) continue;
                int z = (dis[x][j] + 1) % k;
                if (dis[y][z] > dis[x][j] + 1)
                {
                    dis[y][z] = dis[x][j] + 1;
                    if (!vis[y]) q.push(y), vis[y] = 1;
                }
            }
        }
    }
    if (dis[n][0] != 1e9) return true;
    return false;
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        g[u].push_back(v);
        a[u].push_back(x);
        if (x > 0) f = 1;
    }
    if (!dfs(1000000 / k * k))
    {
        cout << "-1" << endl;
        return 0;
    }
    if (!f)
        if (dfs(0))
        {
            cout << dis[n][0] << endl;
            return 0;
        }
    int l = 0, r = 1e6;
    while (l < r)
    {
        int mid = (l + r) / 2 / k * k;
        if (mid < l || mid > r) break;
        if (dfs(mid)) r = mid;
        else l = mid + 1;
    }
    cout << dis[n][0] << endl;
    return 0;
}
