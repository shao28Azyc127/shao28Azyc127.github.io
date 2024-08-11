#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
const int maxp = 1e2;
const int maxval = 1e5;
const int base[] = {1, 10, 100, 1000, 10000};
int n, a[maxn], b[maxn][maxp], cnt[maxval];
inline void solve(int val) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            int d = (j - (val / base[i] % 10)) * base[i];
            if (d != 0) cnt[val + d]++;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int k = 1; k < 10; k++) {
            int j = i+1;
            int d1 = ((val / base[i] % 10) + k) % 10 - (val / base[i] % 10), d2 = (val / base[j] % 10 + k) % 10 - (val / base[j] % 10);
            int d = d1 * base[i] + d2 * base[j];
            if (d) cnt[val + d]++;
        }
    }
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int val = 0, t;
        for (int j = 0; j < 5; j++) {
            scanf("%d", &t);
            val = val * 10 + t;
        }
        a[i] = val;
        solve(val);
    }
    int ans = 0;
    for (int i = 0; i <= 99999; i++) if (cnt[i] == n) ans++;
    printf("%d\n", ans);
    return 0;
}
