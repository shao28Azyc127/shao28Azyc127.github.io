#include <bits/stdc++.h>
using namespace std;

int n, m, r[100005], c[100005], cnt;
long long ans, oil;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) scanf("%d", &r[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1; i < n; i += cnt) {
        long long road = r[i];
        cnt = 1;
        while (true) {
            if (c[i + cnt] >= c[i]) road += r[i + cnt], cnt++;
            else break;
        }
        ans += 1LL * (road - oil) / m * c[i];
        if ((road - oil) % m) ans += c[i], oil = m - (road - oil) % m;
    }
    printf("%lld\n", ans);
    return 0;
}
