#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5e5 + 5;

int c, n, m, q, ox[maxn], x[maxn], oy[maxn], y[maxn];

void work () {
    if (c == 1) {
        if (x[1] != y[1]) printf ("1");
        else printf ("0");
        return;
    }
    if (c == 2) {
        if ((x[1] > y[1] && x[n] > y[m]) || (x[1] < y[1] && x[n] < y[m])) printf ("1");
        else printf ("0");
        return;
    }
    if (x[1] == y[1]) {
        printf ("0");
        return;
    }
    int p = 1;
    bool flag = true;
    int o = x[1] > y[1] ? 1 : -1;
    for (int i = 1; i <= n; i ++) {
        while (p < m && o * x[i] <= o * y[p] && x[i] * o <= y[p + 1] * o) p ++;
        if (p >= m) {
            // out.
            flag = false;
            break;
        } else {

        }
    }
    p ++;
    while (p <= m && y[p] * o < x[n] * o) p ++;
    if (p <= m) flag = false;
    if (flag) printf ("1");
    else printf ("0");
}

int main () {
    freopen ("expand.in", "r", stdin);
    freopen ("expand.out", "w", stdout);
    scanf ("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; i ++) {
        scanf ("%d", &ox[i]);
    }
    for (int i = 1; i <= m; i ++) {
        scanf ("%d", &oy[i]);
    }
    memcpy (x, ox, sizeof(ox));
    memcpy (y, oy, sizeof(oy));
    work();
    while (q --) {
        memcpy (x, ox, sizeof(ox));
        memcpy (y, oy, sizeof(oy));
        int kx, ky;
        scanf ("%d%d", &kx, &ky);
        for (int i = 1; i <= kx; i ++) {
            int p, v;
            scanf ("%d%d", &p, &v);
            x[p] = v;
        }
        for (int i = 1; i <= ky; i ++) {
            int p, v;
            scanf ("%d%d", &p, &v);
            y[p] = v;
        }
        work();
    }
    printf ("\n");
    return 0;
}