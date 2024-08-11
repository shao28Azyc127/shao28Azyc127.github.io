#include <bits/stdc++.h>
using namespace std;
int n;
long long d, ans, now, v[100005], value, now_min;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%lld", &n, &d);
    for (int i = 1; i < n; i++) scanf("%lld", &v[i]);
    now = ans = 0;
    now_min = 1e18;
    for (int i = 1; i < n; i++) {
        scanf("%lld", &value);
        now_min = min(now_min, value);
        if (now >= v[i]) {
            now = now - v[i];
            continue;
        }
        v[i] = v[i] - now;

        if (v[i] % d == 0) {
            ans += v[i] / d * now_min;
            now = 0;
        } else {
            ans += (v[i] / d + 1) * now_min;
            now = (v[i] / d + 1) * d - v[i];
        }
    }
    printf("%lld", ans);
    return 0;
}
