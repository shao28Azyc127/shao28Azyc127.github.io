#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int g[10005][10005];
int n, m, k, minn = 1e9;
bool vis[10005];

void dfs(int step, int x)
{
    if (x == n && step % k == 0)
    {
        minn = min(minn, step);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[x][i] > -1 && step >= g[x][i])
        {
            dfs(step + 1, i);
        }
    }
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    memset(vis, false, sizeof(vis));
    cin >> n >> m >> k;
    memset(g, -1, sizeof(g));
    int maxa = -1;
    for (int i = 1; i <= m; i++)
    {
        int u, v, a;
        cin >> u >> v >> a;
        g[u][v] = a;
        maxa = max(maxa, a);
    }
    for (int i = 0; i <= (maxa - 1) / k + 1; i++)
    {
        dfs(i * k, 1);
    }
    cout << minn << endl;
    return 0;
}
