#include <cstdio>

const int MAXN = 5e5 + 5;

int c, n, m, q, a[MAXN], b[MAXN];

void dfs(int i, int n) {
    //
}

bool check() {
    if (n == 1 && m == 1) return a[1] != b[1];
    return 1;
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
    printf("%d", check());
    while (q--) {
        int kx, ky;
        scanf("%d%d", &kx, &ky);
        for (int i = 1; i <= kx; ++i) {
            int x, v;
            scanf("%d%d", &x, &v);
            a[x] = v;
        }
        for (int i = 1; i <= ky; ++i) {
            int x, v;
            scanf("%d%d", &x, &v);
            b[x] = v;
        }
        printf("%d", check());
    }
    printf("\n");
    return 0;
}