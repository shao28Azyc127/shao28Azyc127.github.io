#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long v[100005], tmp, a[100005], n, d, f[100005], cnt = 0, ans, buy, lft, least = 100005;

int main ()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf ("%lld%lld", &n, &d);
    for (int i = 2; i <= n; i++)
    {
        scanf("%lld", &tmp);
        v[i] = v[i - 1] + tmp;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] < least)
        {
           f[cnt++] = i;
           least = a[i];
        }
    }
    if (cnt == 1) ans = ceil((double)v[n] / d) * a[1];
        else
        {
            for (int i = 0; i < cnt; i++)
            {
                f[cnt] = n;
                buy = ceil((double)(v[f[i + 1]] - v[f[i]] - lft) / d);
                lft += buy * d - (v[f[i + 1]]-v[f[i]]);
                ans += buy * a[f[i]];
            }
        }
    printf("%lld", ans);
    return 0;
}
