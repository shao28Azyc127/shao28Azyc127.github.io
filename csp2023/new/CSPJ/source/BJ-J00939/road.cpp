#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int v[100000], sum[100000], a[100005], n, d, ans = 1e9;
void dfs(int step, double num, int p)
{
    if (step == n)
    {
        ans = min(ans, p);
    }
    for (int i = step + 1; i <= n; i++)
    {
        dfs(i, ceil(1.0 * (sum[i - 1] - sum[step - 1]) / d - num) - (1.0 * (sum[i - 1] - sum[step - 1]) / d - num), p + ceil(1.0 * (sum[i - 1] - sum[step - 1]) / d - num) * a[step]);
    }
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }
    int minn = 1e9, i_minn;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < minn)
        {
            minn = a[i];
            i_minn = i;
        }
    }
    if (i_minn == 1)
    {
        cout << ceil(1.0 * sum[n - 1] / d) * a[1] << endl;
        return 0;
    }
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
