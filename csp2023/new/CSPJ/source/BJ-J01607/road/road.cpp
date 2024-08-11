#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, d, v[1000010], a[1000010], dis[1000010], ans, lasta, lastdis, tmp, lastdisi;

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(ll i = 1; i < n; i++) cin >> v[i];
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = n - 1; i >= 1; i--) dis[i] = dis[i + 1] + v[i];
    tmp = ceil(1.0 * dis[1] / d) * d - dis[1];
    for(ll i = 1; i <= n; i++) dis[i] += tmp;
    ans = dis[1] / d * a[1], lasta = a[1];
    for(ll i = 2; i < n; i++)
        if(a[i] < lasta)
        {
            ans -= dis[i] / d * (lasta - a[i]);
            lasta = a[i];
        }
    cout << ans << endl;
    return 0;
}
