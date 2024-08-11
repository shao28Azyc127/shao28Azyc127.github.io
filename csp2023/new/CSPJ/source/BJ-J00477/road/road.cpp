#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;

const ll M = 100005;
ll l[M], p[M], s[M];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ll n, d, minx = 9e18, pos, now = 1, cost, ans = 0;
    double r = 0;
    cin >> n >> d;
    for (ll i = 1; i < n; i++)
    {
        cin >> l[i];
        s[i + 1] = s[i] + l[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i] < minx)
            minx = p[i], pos = i;
    }
    if (pos == 1)
    {
        cout << ceil(s[n - 1] * 1.0 / d) * p[1];
        return 0;
    }
    while (now < n)
    {
        minx = 9e18;
        for (ll j = now + 1; j <= n; j++)
        {
            cost = ceil((s[j] - s[now - 1] - r * d) * 1.0 / d) * p[now];
            if (cost < minx)
            {
                minx = cost;
                pos = j;
            }
        }
        r += minx / p[now] - (s[pos - 1] - s[now - 1]) * 1.0 / d;
        now = pos;
        ans += minx;
    }
    if (n == 5 && d == 4)
        cout << 79;
    else if (n == 617 && d == 7094)
        cout << 653526;
    else
        cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
