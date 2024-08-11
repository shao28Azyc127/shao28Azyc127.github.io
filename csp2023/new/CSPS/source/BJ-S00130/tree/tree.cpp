#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int NR = 100010;
long long a[NR], b[NR], c[NR], d[NR];
vector<int> G[NR];
int n, inv[NR], tot;
bool vis[NR];
long long ans = 9e18;
bool cmp(long long x, long long y)
{
    long long X = 0, Y = 0;
    if (a[x] % b[x] == 0) X = a[x] / b[x];
    else X = a[x] / b[x] + 1;
    if (a[y] % b[y] == 0) Y = a[y] / b[y];
    else Y = a[y] / b[y] + 1;
    return X > Y;
}
void dfs(int u, int step, int fa)
{
    if (tot == n - 1)
    {
        d[n] = u;
        long long tot = 0;
        for (int i = 1; i <= n; i++)
        {
            long long X = 0;
            if (a[d[i]] % b[d[i]] == 0) X = a[d[i]] / b[d[i]];
            else X = a[d[i]] / b[d[i]] + 1;
            tot = max(tot, X + i - 1);
        }
        cout << tot << '\n';
        exit(0);
    }
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == fa) continue;
        d[++tot] = v;
        dfs(v, step + 1, u);
    }
}
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(G[i].begin(), G[i].end(), cmp);
    dfs(1, 1, 0);
    return 0;
}
