#include <stdio.h>
#define ll long long
#define N 100005
int a[N]; ll f[N];
int stk[N], top, p[N];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d; scanf("%d%d", &n, &d);
    for (int i = 1, v; i < n; i++) {
        scanf("%d", &v);
        f[i+1] = f[i] + v;
    }
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    stk[0] = n;
    for (int i = n; i; i--) {
        while (top && a[stk[top]] >= a[i]) top--;
        p[i] = stk[top]; stk[++top] = i;
    }
    ll ans = 0, now = 0;
    for (int i = 1; i < n; i = p[i]) {
        ll s = f[p[i]] - f[i] - now;
        ll x = s / d + !!(s % d);
        ans += x * a[i]; now = x * d - s;
    }
    printf("%lld\n", ans);
    return 0;
}