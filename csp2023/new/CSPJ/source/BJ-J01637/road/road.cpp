#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, d, a[N], v[N], f[N], l[N], ans = 0x3f3f3f3f;
void dfs(int t, int c, int lo) {
    if (t == n) {
        ans = min(ans, c);
        return;
    }
    for (int i = t + 1; i <= n; ++i) {
        int dis = (v[i - 1] - v[t - 1] - lo);
        if (dis % d == 0) {
            int oil = dis / d;
            int cost = oil * a[i];
            dfs(i, cost + c, 0);
        } else {
            int oil = dis / d + 1;
            int cost = oil * a[i];
            dfs(i, cost + c, oil * d - dis);
        }
    }
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 1; i < n; ++i) {
        scanf("%d", v + i);
        v[i] = v[i - 1] + v[i];
    }
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    if (n <= 8) {
        dfs(1, 0, 0);
        printf("%d", ans);
    } else {
        memset(f, 0x3f, sizeof(f));
        f[1] = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                int dis = (v[i - 1] - v[j - 1] - l[j]);
                if (dis % d == 0) {
                    int oil = dis / d;
                    int cost = oil * a[i];
                    if (cost + f[j] < f[i]) {
                        f[i] = cost + f[j];
                        l[i] = 0;
                    }
                }
                else {
                    int oil = dis / d + 1;
                    int cost = oil * a[i];
                    if (cost + f[j] < f[i]) {
                        f[i] = cost + f[j];
                        l[i] = oil * d - dis;
                    }
                }
            }
        }
        printf("%d", f[n]);
    }
    return 0;
}