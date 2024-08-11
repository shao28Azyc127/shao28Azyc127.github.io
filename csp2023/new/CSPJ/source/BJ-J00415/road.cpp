#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int v[maxn], a[maxn], dp[maxn];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    a[n] = 0;
    v[0] = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        v[i] += v[i - 1];
    }
    int cur = 1, ans = 0;
    double left = 0;
    while (cur < n)
    {
        for (int i = cur + 1; i <= n; i++)
        {
            if (a[i] < a[cur])
            {
                double x = a[cur] * ceil(1.0 * (v[i - 1] - v[cur - 1]) / d - left);
                ans += (int)x;
                left = ceil(1.0 * (v[i - 1] - v[cur - 1]) / d - left) - (1.0 * (v[i - 1] - v[cur - 1]) / d - left);
                cur = i;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
