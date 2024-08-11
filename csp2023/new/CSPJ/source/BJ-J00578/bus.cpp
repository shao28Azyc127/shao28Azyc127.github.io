#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int NR = 1e4 + 10;
const ll INF = 9e18;

vector<int> g[NR];
int t[NR][NR];
// -2: caculating -1: not caculated
int vis[NR];
int n, m, k;
ll mn = INF;

void dfs(int pos, int sum, int st)
{
    if (pos == n)
    {
        if (sum % k == 0)
        {
            mn = min(mn, 1ll * sum + (st + k - 1) / k * k);
        }
        return;
    }
    if (vis[pos] == -2)
    {
        return;
    }
    vis[pos] = -2;
    for (int i: g[pos])
    {
        dfs(i, sum + 1, max(st, t[pos][i] - sum));
    }
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        cin >> t[u][v];
        g[u].push_back(v);
    }
    memset(vis, -1, sizeof vis);
    dfs(1, 0, 0);
    cout << mn << endl;
    return 0;
}
