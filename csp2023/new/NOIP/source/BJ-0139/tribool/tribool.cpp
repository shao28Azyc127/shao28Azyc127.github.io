#include <bits/stdc++.h>
#define d(x) ((x) + n + 3)
using namespace std;

const int N = 100010, M = 200010;
int tid, T, n, m, t, f, u, type[N], a[N];
int fa[M], val[M];
int fd(int x) {return x == fa[x] ? x : fa[x] = fd(fa[x]); }
void merge(int x, int y) {
    x = fd(x), y = fd(y);
    fa[y] = x;
}
void merge0(int x, int y) {
    int dx = fd(d(x)), dy = fd(d(y));
    x = fd(x), y = fd(y);
    if (val[x] || val[y] || val[dx] || val[dy] || x == dy || y == dx) {
        merge(x, y), merge(x, dx), merge(dx, dy);
        x = fd(x);
        val[x] = 1;
        return;
    }
    merge(x, y), merge(dx, dy);
}
void merge1(int x, int y) {
    int dx = fd(d(x)), dy = fd(d(y));
    x = fd(x), y = fd(y);
    if (val[x] || val[y] || val[dx] || val[dy] || x == y || dx == dy) {
        merge(x, y), merge(x, dx), merge(dx, dy);
        x = fd(x);
        val[x] = 1;
        return;
    }
    merge(x, dy), merge(y, dx);
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &tid, &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        t = n + 1, f = n + 2, u = n + 3;
        for (int i=1; i<=n; ++i)
            type[i] = 0, a[i] = i;
        type[f] = 1, a[f] = t;
        for (int i=1; i<=m; ++i) {
            char op[5]; int x, y;
            scanf("%s%d", op, &x);
            if (op[0] == 'T') type[x] = 0, a[x] = t;
            else if (op[0] == 'F') type[x] = 0, a[x] = f;
            else if (op[0] == 'U') type[x] = 0, a[x] = u;
            else if (op[0] == '+') {
                scanf("%d", &y);
                type[x] = type[y], a[x] = a[y];
            } else {
                scanf("%d", &y);
                type[x] = (type[y] ^ 1), a[x] = a[y];
            }
        }
        /*
        for (int i=1; i<=n+3; ++i)
            printf("%d %d\n", type[i], a[i]);*/
        for (int i=1; i<=n+n+6; ++i)
            fa[i] = i, val[i] = 0;
        val[u] = val[d(u)] = 1;
        merge1(t, f);
        for (int i=1; i<=n; ++i) {
            if (type[i]) merge1(i, a[i]);
            else merge0(i, a[i]);
        }
        /*
        for (int i=1; i<=n; ++i)
            printf("%d ", fd(i)); putchar(10);*/
        int ans = 0;
        for (int i=1; i<=n; ++i)
            if (val[fd(i)]) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
