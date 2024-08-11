#include <bits/stdc++.h>
using namespace std;

long long n, m, k, ans = 1e18;
int a[10010], v[100010];
int g[20010][20010];
bool vis[20010];

void dfs(int x, long long cnt)
{
    if(x == n)
    {
        ans = min(ans, cnt);
        return ;
    }
    for(int i = 1; i <= m; i ++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(g[x][i], cnt + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v >> a[i];
        g[u][v] = a[i];
        if(a[i] != 0)
        {

            cout << -1;
            return 0;
        }
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}
