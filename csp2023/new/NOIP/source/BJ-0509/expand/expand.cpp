#include <bits/stdc++.h>
using namespace std;
int c, n, m, q, kx, ky, amax, amin = 1e9, bmax, bmin = 1e9;
int a[500005], b[500005];
int e[500005], d[500005];
int tmp1, tmp2;
bool cmp() {
    amax = 0;
    amin = 1e9;
    bmax = 0;
    bmin = 1e9;
    for (int i = 1; i <= n; i++) {
        amax = max(amax, a[i]);
        amin = min(amin, a[i]);
        bmax = max(bmax, b[i]);
        bmin = min(bmin, b[i]);

    }
    //printf("%d%d%d%d\n", amax, amin, bmax, bmin);
    if (amax > bmax && amin < bmin || amax < bmax && amin > bmin) return false;
    if (a[1] > b[1]) {
        if (a[n] > b[n]) {
            int f1 = 0;
            if (amax > bmax && amin > bmin) return true;
        }
    } else {
        if (b[n] > a[n])
            if (amax < bmax && amin < bmin) return true;
    }
    return false;
}
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        e[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        d[i] = b[i];
    }
    if (cmp()) printf("1");
    else printf("0");

    while (q--) {
        for (int i = 1; i <= n; i++) {
            a[i] = e[i];
        }
        for (int i = 1; i <= n; i++) {
            b[i] = d[i];
        }
        scanf("%d%d", &kx, &ky);
        while (kx--) {
            scanf("%d%d", &tmp1, &tmp2);
            a[tmp1] = tmp2;
        }
        while (ky--) {
            scanf("%d%d", &tmp1, &tmp2);
            b[tmp1] = tmp2;
        }
        //for (int i = 1; i <= n; i++) printf("%d", a[i]);
        //for (int i = 1; i <= n; i++) printf("%d", b[i]);
        if (cmp()) printf("1");
        else printf("0");
    }
    return 0;
}
