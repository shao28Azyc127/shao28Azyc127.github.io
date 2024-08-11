#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long v[100005], a[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    long long n, d;
    cin >> n;
    cin >> d;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long minp = 9e18, f = 0, ans = 0;
    for (int i = 1; i < n; i++)
    {
        minp = min(minp, a[i]);
        v[i] -= f;
        long long temp = v[i] / d + (v[i] % d != 0);
        f = temp * d - v[i];
        ans += temp * minp;
    }
    cout << ans << endl;
    return 0;
}
