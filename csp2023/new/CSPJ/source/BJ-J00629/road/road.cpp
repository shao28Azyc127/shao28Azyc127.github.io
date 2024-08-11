

#include <iostream>

#define int long long
#define endl '\n'

using namespace std;

const int MAXI = 1e5 + 9;
int n, d, v[MAXI], a[MAXI];
int k, mini, oil, money, ans = 0;

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    mini = 1e18;
    for (int i = 1; i <= n - 1; i++) {
        mini = min(mini, a[i]);
        int solo = max(0ll, v[i] - k);
        oil = (solo + d - 1) / d;
        money = oil * mini, ans += money;
        k += oil * d, k -= v[i];
    }

    cout << ans << endl;

    return 0;
}
