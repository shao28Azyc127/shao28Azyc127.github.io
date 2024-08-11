#include <bits/stdc++.h>
using namespace std;

int n, b[100005], c[100005], u[100005], v[100005];
long long a[100005], maxday;

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%d%d", &a[i], &b[i], &c[i]);
    }
    for (int i = 1; i < n; i++) scanf("%d%d", &u[i], &v[i]);
    for (int i = 1; i <= n; i++) {
        long long day = 0, tall = 0;
        while (true) {
            if (tall > a[i]) break;
            day++;
            tall += 1LL * max(1LL, 1LL * b[i] + 1LL * day * c[i]);
        }
        day += i - 1;
        maxday = max(maxday, day);
    }
    printf("%lld\n", maxday);
    return 0;
}
