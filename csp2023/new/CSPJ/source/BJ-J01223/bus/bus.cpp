#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010], c[1000010];
int n, m, k, ans = -1;

void dfs(int step, int sum)
{
    if (step == n)
    {
        if (sum % k != 0)
        {
            return;
        }
        ans = min(ans, sum);
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        if (a[i] < b[i] && a[i] == step && sum >= c[i])
        {
            dfs(b[i], sum + 1);
        }
        dfs(step, sum);
    }
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
