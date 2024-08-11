#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int c, n, m, q, x[N], y[N], kx, ky;
struct Diff {
    int p, v, org;
} mx[N], my[N];
bool f[2005][2005];
int fun() {
    if (x[1] == y[1])
        return 0;
    if (x[1] < y[1]) {
        f[1][1] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                if (i == 1 && j == 1)
                    continue;
                f[i][j] = 0;
                if (x[i] < y[j]) {
                    if (i != 1)
                        f[i][j] |= f[i - 1][j];
                    if (j != 1)
                        f[i][j] |= f[i][j - 1];
                    if (i != 1 && j != 1)
                        f[i][j] |= f[i - 1][j - 1];
                }
            }
        return f[n][m];
    }
    else {
        f[1][1] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                if (i == 1 && j == 1)
                    continue;
                f[i][j] = 0;
                if (x[i] > y[j]) {
                    if (i != 1)
                        f[i][j] |= f[i - 1][j];
                    if (j != 1)
                        f[i][j] |= f[i][j - 1];
                    if (i != 1 && j != 1)
                        f[i][j] |= f[i - 1][j - 1];
                }
            }
        return f[n][m];
    }
}
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    if (1 <= c && c <= 7) {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &x[i]);
        for (int i = 1; i <= m; ++i)
            scanf("%d", &y[i]);
        printf("%d", fun());
        while (q--) {
            scanf("%d%d", &kx, &ky);
            for (int i = 1; i <= kx; ++i) {
                scanf("%d%d", &mx[i].p, &mx[i].v);
                mx[i].org = x[mx[i].p];
                x[mx[i].p] = mx[i].v;
            }
            for (int i = 1; i <= ky; ++i) {
                scanf("%d%d", &my[i].p, &my[i].v);
                my[i].org = y[my[i].p];
                y[my[i].p] = my[i].v;
            }
            printf("%d", fun());
            for (int i = 1; i <= kx; ++i)
                x[mx[i].p] = mx[i].org;
            for (int i = 1; i <= ky; ++i)
                y[my[i].p] = my[i].org;
        }
        return 0;
    }
}