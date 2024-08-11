#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> g[2010], W[2010];
void add(int u, int v, int w)
{
    g[u].push_back(v);
    W[u].push_back(w);
}
bool vis[1010];
int ans = 0x3f3f3f3f;
void dfs(int t, int u)
{
    if (u == n)
    {
        if (t % k == 0)
        {
            ans = min(ans, t);
        }
        return;
    }
    if (t >= ans)
    {
        return;
    }
    for (int i = 0; i < g[u].size(); i++)
    {
        if (!vis[g[u][i]] && W[u][i] <= t)
        {
            vis[g[u][i]] = 1;
            dfs(t + 1, g[u][i]);
            vis[g[u][i]] = 0;
        }
    }
}
int main ()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int mx = -1;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        mx = max(mx, w);
    }
    for (int i = 0; i <= mx; i += k)
    {
        dfs(i, 1);
    }
    if (ans == 0x3f3f3f3f)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
