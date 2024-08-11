#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005], dis[100005]; // dis i-> i +1
int st = 1, ndis, ans, ld;
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    scanf("%lld %lld", &n, &d);
    for (int i = 1; i < n; i++)
        scanf("%lld", &dis[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    a[n] = 0;
    for (int i = 2; i <= n; i++)
    {
        ndis += dis[i - 1];
        if (a[i] < a[st])
        {
            ans += a[st] * (int)ceil(1.0 * (ndis - ld) / d);
            ld = (int)(ceil(1.0 * (ndis - ld) / d)) * d - (ndis - ld);
            ndis = 0;
            st = i;
        }
    }
    printf("%lld", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
