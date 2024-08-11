#include <iostream>
#include <cstdio>
using namespace std;

int n, m, k, ans;
bool f[1005][1005];

void dfs(int x, int t)
{
    if (x == n && t % k == 0)
    {
        ans = min(ans, t);
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (f[x][i]) dfs(i, t + 1);
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        f[x][y] = true;
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}