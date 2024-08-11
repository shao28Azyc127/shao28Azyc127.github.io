#include <bits/stdc++.h>
using namespace std;

int a[100005], v[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for (int i = 2; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    long long ans = 0, p = a[1], sum = 0, last = 0;
    for (int i = 2; i <= n; i++)
    {
        sum += v[i];
        if (p > a[i])
        {
            ans += 1ll * (sum - last + d - 1) / d * p;
            last = 1ll * (sum - last + d - 1) / d * d - (sum - last);
            p = a[i];
            sum = 0;
        }
    }
    if (sum > 0)
    {
        ans += 1ll * (sum - last + d - 1) / d * p;
    }
    cout << ans << endl;
    return 0;
}
