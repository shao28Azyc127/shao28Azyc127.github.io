#include <iostream>
using namespace std;

typedef long long ll;

ll a[100005], v[100005];

ll fun(ll x, ll y)
{
    if (x % y == 0) return x / y;
    return x / y + 1;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i < n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll now = 1e18, ans = 0, q = 0;
    for (int i = 1; i < n; i++)
    {
        now = min(now, a[i]);
        if (q > v[i]) q -= v[i];
        else
        {
            ans += now * fun(v[i] - q, d);
            q = (d - (v[i] - q) % d) % d;
        }
    }
    cout << ans << endl;
    return 0;
}
