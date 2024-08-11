#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[10005][10005], n, m, k, ans = 1e9;
void dfs(int step, int t)
{
    if (step == n && t % k == 0)
    {
        ans = min(ans, t);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != step && a[step][i] != -1 && t >= a[step][i])
        {
            dfs(i, t + 1);
        }
    }
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = -1;
        }
    }
    int maxn = -1;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v >> a[u][v];
        maxn = max(maxn, a[u][v]);
    }
    dfs(1, ((maxn - 1) / k + 1) * k);
    cout << ans << endl;
    return 0;
}
