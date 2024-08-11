#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
vector<pair<int, int>> e[maxn];
int a[maxn];
bool vis[maxn];
void dfs(int u)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    for (pair<int, int> i : e[u])
    {
        a[i.first] = min(a[i.first], max(a[u] + 1, i.second));
        dfs(i.first);
    }
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        e[u].emplace_back(pair<int, int>(v, a));
    }
    for (int i = 2; i <= n; i++)
    {
        a[i] = INT_MAX;
    }
    dfs(1);
    printf("%d\n", a[n]);
    return 0;
}
