#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
int n, a[10];
int can[100005];
inline int calc() {
    int res = 0;
    rep(i, 1, 5) (res *= 10) += a[i];
    return res;
}
signed main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    rep(i, 1, n) {
        rep(j, 1, 5) scanf("%d", &a[j]);
        rep(j, 1, 5) {
            rep(k, 1, 9) {
                (a[j] += k) %= 10;
                ++can[calc()];
                // printf("de:%d\n", calc());
                (a[j] += 10 - k) %= 10;
            }
        }
        rep(j, 1, 4) {
            rep(k, 1, 9) {
                (a[j] += k) %= 10;
                (a[j + 1] += k) %= 10;
                ++can[calc()];
                // printf("de:%d\n", calc());
                (a[j] += 10 - k) %= 10;
                (a[j + 1] += 10 - k) %= 10;
            }
        }
    }
    int ans = 0;
    rep(i, 0, 99999) if (can[i] == n) ++ans;
    printf("%d\n", ans);
    return 0;
}