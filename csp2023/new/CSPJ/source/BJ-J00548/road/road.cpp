// Wish my son recovering soon.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 10;
ll n, d, a[maxn], v[maxn], pre[maxn];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &v[i]);
        pre[i + 1] = pre[i] + v[i];
    }
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ll rest = 0, ans = 0;
    int cur = 1;
    while (cur != n) {
        int nxt = n;
        for (int i = cur + 1; i <= n; i++)
            if (a[i] < a[cur]) {
                nxt = i;
                break;
            }
        if (rest < pre[nxt] - pre[cur]) {
            ans += (pre[nxt] - pre[cur] - rest + d - 1) / d * a[cur];
            rest += (pre[nxt] - pre[cur] - rest + d - 1) / d * d;
        }
        rest -= pre[nxt] - pre[cur];
        cur = nxt;
    }
    printf("%lld\n", ans);
    return 0;
}
