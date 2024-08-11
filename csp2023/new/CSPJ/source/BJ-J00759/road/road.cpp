#include <iostream>
#include <cstdio>
using namespace std;
int n, d, v[100005], a[100005], mi[100005];
int m, vv[100005], aa[100005];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    mi[0] = 0x7fffffff;
    for (int i = 1; i <= n; i++) mi[i] = min(mi[i - 1], a[i]);
    for (int i = 1; i < n; i++) {
        if (mi[i] != mi[i - 1]) {
            ++m;
            vv[m] = v[i];
            aa[m] = mi[i];
        } else {
            vv[m] += v[i];
        }
    }
    long long now = 0, ans = 0;
    for (int i = 1; i <= m; i++) {
        if (now < vv[i]) {
            int num = (vv[i] - now) / d + (((vv[i] - now) % d == 0) ? 0 : 1);
            now += 1ll * num * d, ans += 1ll * num * aa[i];
        }
        now -= 1ll * vv[i];
    }
    cout << ans << '\n';
    return 0;
}