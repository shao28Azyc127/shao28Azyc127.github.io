#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, u, v, a, ans = 1e18;
struct edge
{
    ll v, a;
};
vector<edge> e[100005];
void dfs(ll u, ll tme, ll q)
{
    if (tme > ans) return;
    if (u == n)
    {
        if (q % k != 0) q = (q / k + 1) * k;
        tme = tme + q;
        if (tme % k == 0)
        {
            ans = min(ans, tme);
        }
        return;
    }
    for (int i = 0; i < e[u].size(); i++)
    {
        dfs(e[u][i].v, tme + 1, max(q, e[u][i].a - tme));
    }
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &a);
        e[u].push_back((edge) {v, a});
    }
    dfs(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}
