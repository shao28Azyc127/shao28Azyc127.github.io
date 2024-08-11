#include<cstdio>
#include<cstring>
using namespace std;
int x[500005], y[500005];
int xnew[500005], ynew[500005];
int px[500005], py[500005];
int vx[500005], vy[500005];
inline int solve1(int *x, int *y, int n, int m) {
    // puts("B");
    bool f[2005][2005];
    memset(f, 0, sizeof(f));
    f[1][1] = 1;
    // printf("1");
    for (int j = 2; j <= m; ++j) {
        if (y[j] > x[1]) f[1][j] = f[1][j-1];
        // printf(" %d", f[1][j]);
    }
    for (int i = 2; i <= n; ++i) {
        // puts("");
        for (int j = 1; j <= m; ++j) {
            if (y[j] > x[i]) f[i][j] = f[i-1][j] || f[i][j-1];
            // printf(" %d", f[i][j]);
        }
    }
    // puts("");
    return f[n][m];
}
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int c, n, m, q;
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", x + i);
    for (int i = 1; i <= m; ++i) scanf("%d", y + i);
    if (c < 8) {
        int kx = 0, ky = 0;
        memcpy(xnew+1, x+1, n << 2);
        memcpy(ynew+1, y+1, m << 2);
        do {
            // puts("A");
            if (xnew[1] < ynew[1]) {
                printf("%d", solve1(xnew, ynew, n, m));
            } else if (xnew[1] > ynew[1]) {
                printf("%d", solve1(ynew, xnew, m, n));
            } else printf("0");
            if (!q) break;
            for (int i = 1; i <= kx; ++i) xnew[px[i]] = x[px[i]];
            for (int i = 1; i <= ky; ++i) ynew[py[i]] = y[py[i]];
            scanf("%d%d", &kx, &ky);
            for (int i = 1; i <= kx; ++i) scanf("%d%d", px + i, vx + i), xnew[px[i]] = vx[i];
            for (int i = 1; i <= ky; ++i) scanf("%d%d", py + i, vy + i), ynew[py[i]] = vy[i];
            q--;
        } while (true);
        puts("");
    } else {
        for (int i = 0; i <= q; ++i) printf("1");
        puts("");
    }
    return 0;
}