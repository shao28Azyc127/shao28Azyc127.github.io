#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
long long n, d, a[maxn], ans, cur, v[maxn];
int main() {
    ios::sync_with_stdio(false);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 2; i <= n; i++) cin >> v[i], v[i] += v[i - 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, r = 1; i < n; i = r) {
        while (r < n && a[i] <= a[r]) ++r;
        long long val = v[r] - v[i] - cur;
        cur = max(-val, 0ll);
        if (val > 0) cur += (val % d == 0) ? 0 : (d - val % d), ans += a[i] * ((val + d - 1ll) / d);
    }
    cout << ans << '\n';
    return 0;
}