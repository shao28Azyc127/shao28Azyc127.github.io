#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005], b[100005], c[100005], ans;
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ans = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
        long long now = b[i] + i * c[i], ti = 0;
        while (now < a[i]) {
            if (now < 1) {
                ti += a[i];
                a[i] = 0;
                break;
            }
            ti++;
            a[i] -= now;
            now += c[i];
        }
        if (a[i] > 0) ti++;
        ans = max(ans, ti);
    }
    printf("%lld", ans);
    return 0;
}
