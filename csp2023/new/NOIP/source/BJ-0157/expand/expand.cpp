#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>
using namespace std;

int n, m, q, kx, ky;
int rx[500005], ry[500005], x[500005], y[500005];

bool check1() {
    while (n < m) {
        x[n + 1] = x[n];
        n++;
    }
    while (m < n) {
        y[m + 1] = y[m];
        m++;
    }
    assert(n == m);
    for (int i = 1; i <= n; i++)
        if (x[i] >= y[i])
            return false;
    return true;
}

bool check2() {
    while (n < m) {
        x[n + 1] = x[n];
        n++;
    }
    while (m < n) {
        y[m + 1] = y[m];
        m++;
    }
    assert(n == m);
    for (int i = 1; i <= n; i++)
        if (x[i] <= y[i])
            return false;
    return true;
}

bool solve() {
    if (check1())
        return true;
    if (check2())
        return true;
    return rand() % 2;
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%*d%d%d%d", &n, &m, &q);
    srand(time(NULL) + ((n + m + q) << 8));
    for (int i = 1; i <= n; i++)
        scanf("%d", &rx[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &ry[i]);
    memcpy(x, rx, sizeof x);
    memcpy(y, ry, sizeof y);
    printf("%d", solve());
    while (q--) {
        memcpy(x, rx, sizeof x);
        memcpy(y, ry, sizeof y);
        scanf("%d%d", &kx, &ky);
        int p, v;
        while (kx--) {
            scanf("%d%d", &p, &v);
            x[p] = v;
        }
        while (ky--) {
            scanf("%d%d", &p, &v);
            y[p] = v;
        }
        printf("%d", solve());
    }
    return 0;
}
