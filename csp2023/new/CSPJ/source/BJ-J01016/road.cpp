#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, d, top, ans, a[N], val[N], st[N], f[N], s[N];
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for (int i = 2; i <= n; i++) {
        scanf("%lld", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &val[i]);
    }
    for (int i = n; i; i--) {
        while (top && val[i] < val[st[top]]) top--;
        f[i] = st[top];
        if (!f[i]) f[i] = n;
        st[++top] = i;
    }
    int pos = 1, last = 0;
    while (pos < n) {
        int dis = (s[f[pos]] - s[pos] - last);
        int cnt;
        if (dis % d) cnt = dis / d + 1;
        else cnt = dis / d;
        ans += cnt * val[pos];
        last = last + cnt * d - s[f[pos]] + s[pos];
        pos = f[pos];
    }
    printf("%lld", ans);
    return 0;
}