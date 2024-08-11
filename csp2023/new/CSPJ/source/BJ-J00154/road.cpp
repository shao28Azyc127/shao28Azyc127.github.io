#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, d, v[N], a[N];
int minn = 1e9, ans, tot;
signed main(void) {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i < n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        minn = min(minn, a[i]);
        if (tot < v[i]) {
            int tmp = ceil(1.0 * (v[i] - tot) / d);
            ans += tmp * minn;
            tot += tmp * d;
        }
        tot -= v[i];
    }
    cout << ans << endl;
    return 0;
}
