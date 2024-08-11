// 100pts
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 9;
int n, d, a[N], v[N];
LL sum[N], ans = 0;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &v[i]);
        sum[i] = sum[i - 1] + v[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    a[n] = 0;
    LL l = 0, p = 1, s = 0;
    while (p < n) {
        int nxt = 0;
        for (int i = p + 1; i <= n; i++) {
            if (a[i] < a[p]) {nxt = i; break;}
        }
        LL dis = sum[nxt] - sum[p];
        LL c = max(0ll, (dis - s + d - 1) / d);
//        cout << l << ' ' << p << ' ' << s << ' ' << nxt << ' ' << c << ' ' << ans << endl;
        if (l >= c) {
            l -= c, p = nxt, s = c * d + s - dis;
        } else {
            ans += a[p] * (c - l), s = c * d + s - dis, p = nxt, l = 0;
        }
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
