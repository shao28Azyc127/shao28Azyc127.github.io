#include <bits/stdc++.h>
using namespace std;
long long n, m, k, u, v, x, ans = 0x3f3f3f3f, maxl;
vector <long long> a[200005], b[200005];
void dfs(long long now, long long sum)
{
    if (now == n)
    {
        if (sum % k == 0)
        {
            ans = min(ans, sum);
        }
        return;
    }
    for (long long i = 0; i < a[now].size(); i++)
    {
        if (b[now][i] <= sum)
        {
            dfs(a[now][i], sum + 1);
        }
    }
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (long long i = 1; i <= m; i++)
    {
        cin >> u >> v >> x;
        a[u].push_back(v);
        b[u].push_back(x);
        maxl = max(maxl, x);
    }
    cout << maxl;
    for (long long i = 0; i <= maxl; i += k)
    {
        dfs(1, i);
    }
    if (ans == 0x3f3f3f3f)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
    return 0;
}
