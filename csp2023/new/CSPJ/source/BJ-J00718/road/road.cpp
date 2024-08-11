#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

#define ll long long
const int NR = 1e5 + 10;
ll v[NR], a[NR], am[NR];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ll n, d;
    scanf("%lld%lld", &n, &d);
    for (ll i = 1; i <= n - 1; i++) scanf("%lld", &v[i]);
    am[0] = 1e9;
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        am[i] = min(am[i - 1], a[i]);
    }
    ll ans = 0;
    double cur = 0; // 剩余油的升数，小数
    for (ll i = 1; i <= n - 1; i++)
    {
        ll needa = ceil(1.0 * v[i] / d - cur);
        cur += needa - 1.0 * v[i] / d;
        ans += am[i] * needa;
    }
    printf("%lld", ans);
    return 0;
}