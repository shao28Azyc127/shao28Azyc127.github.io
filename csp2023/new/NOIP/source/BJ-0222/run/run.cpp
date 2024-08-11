#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c, t, ans;
ll n, m, k, d;
ll x, y, v;

int main ()
{
    freopen ("run5.in", "r", stdin);
    freopen ("run.out", "w", stdout);
    cin >> c >> t;
    while (t --)
    {
        ans = 0;
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= m; i ++)
        {
            cin >> x >> y >> v;
            if (y > k) continue;
            if (y * d >= v) continue;
            ans += (v - y * d);
        }
        cout << ans << endl;
    }
    return 0;
}
