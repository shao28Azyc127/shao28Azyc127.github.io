#include <bits/stdc++.h>
using namespace std;

int n, a[10][10], r[6] = {0, -1, -1, -1, -1, -1}, ans;

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d%d", &a[i][1], &a[i][2], &a[i][3], &a[i][4], &a[i][5]);
    }
    for (int i = 2; i <= n; i++) {
        int cnt = 0, b[6];
        for (int j = 1; j <= 5; j++) {
            if (a[i][j] != a[i - 1][j]) cnt++, b[cnt] = j;
        }
        if (cnt == 1) {
            for (int j = 1; j <= 5; j++) {
                if (j == b[1]) continue;
                r[j] = a[i][j];
            }
        }
        if (cnt == 2) {
            for (int j = 1; j <= 5; j++) {
                if (j == b[1] || j == b[2]) continue;
                r[j] = a[i][j];
            }
        }
        if (cnt == 3) {
            for (int j = 1; j <= 5; j++) {
                if (j == b[1] || j == b[2] || j == b[3]) continue;
                r[j] = a[i][j];
            }
        }
        if (cnt == 4) {
            for (int j = 1; j <= 5; j++) {
                if (j == b[1] || j == b[2] || j == b[3] || j == b[4]) continue;
                r[j] = a[i][j];
            }
        }
    }
    if (n == 1) {
        printf("81\n");
        return 0;
    }
    for (int i = 1; i <= 5; i++) if (r[i] == -1) ans += 10;
    for (int i = 1; i < 5; i++) if (r[i] == -1 && r[i + 1] == -1) ans += 10;
    printf("%d\n", ans);
    return 0;
}
