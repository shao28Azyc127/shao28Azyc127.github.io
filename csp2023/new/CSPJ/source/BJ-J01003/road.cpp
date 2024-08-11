#include <bits/stdc++.h>
using namespace std;
int n, d;
int a[100010], b[100010], ans = 0x3f3f3f3f;
void dfs(int x, int p, int sum)
{
    if (x == n)
    {
        ans = min(ans, sum);
        return;
    }
    if (sum >= ans)
    {
        return;
    }
    for (int i = max(0, (int)ceil(1.0 * (a[x] - p) / d)); i <= (ans - sum) / b[x]; i++)
    {
        dfs(x + 1, p + d * i - a[x], sum + b[x] * i);
    }
}
int main ()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
