#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

vector<ll> G[N];
ll n;
ll a[N], b[N], c[N];

ll dp[N];
bool cmp(int u, int v)
{
    return dp[u] > dp[v];
}
void dfs(int u, int fa)
{
    for (int v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u);
    }
    dp[u] = a[u] / b[u];
    if (a[u] % b[u] != 0) dp[u]++;
    sort(G[u].begin(), G[u].end(), cmp);
    for (int i = 0; i < G[u].size(); i++)
    {
        dp[u] = max(dp[u], i + dp[G[u][i]] + 1);
    }
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
        b[i] = max(b[i], 1LL);
    }
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, -1);
    cout << dp[1] << endl;
    return 0;
}
