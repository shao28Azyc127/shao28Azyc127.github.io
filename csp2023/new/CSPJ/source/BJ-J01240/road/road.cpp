#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, d, a[maxn], v[maxn];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 1; i < n; i++)  scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++)  scanf("%d", &a[i]);
    int now_ition = 1, ans = 0, tmp = 0;
    while (now_ition < n) {
        int sum = 0, last_ition = now_ition;
        for (; now_ition < n && a[last_ition] <= a[now_ition]; now_ition++)  sum += v[now_ition];
        ans += ((sum - tmp) / d + 1) * a[last_ition];
        if ((sum-tmp) % d == 0)  ans -= a[last_ition];
        tmp = d - (sum-tmp) % d;
    }
    printf("%d", ans);
    return 0;
}