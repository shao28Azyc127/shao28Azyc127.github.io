#include <bits/stdc++.h>
using namespace std;
int c, n, m, q, kx, ky, p, v, a[100], b[100];
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    if (n == 1 && m == 1) {
        while (q--) {
            scanf("%d%d", &kx, &ky);
            for (int i = 1; i <= kx; i++) scanf("%d%d", &p, &v), a[p] = v;
            for (int i = 1; i <= ky; i++) scanf("%d%d", &p, &v), b[p] = v;
            if (a[1] != b[1]) printf("1");
            else printf("0");
        }
        return 0;
    }
    while (q--) {
        scanf("%d%d", &kx, &ky);
        for (int i = 1; i <= kx; i++) scanf("%d%d", &p, &v), a[p] = v;
        for (int i = 1; i <= ky; i++) scanf("%d%d", &p, &v), b[p] = v;
        if (n == 1 && m == 1) {
            if (a[1] != b[1]) printf("1");
            else printf("0");
        }
        else if (n == 2 && m == 1) {
            if (a[1] > b[1] && a[2] > b[1]) printf("1");
            else if (a[1] < b[1] && a[2] < b[1]) printf("1");
            else printf("0");
        }
        else if (n == 1 && m == 2) {
            if (a[1] > b[1] && a[1] > b[2]) printf("1");
            else if (a[1] < b[1] && a[1] < b[2]) printf("1");
            else printf("0");
        }
        else if (n == 2 && m == 2) {
            if (a[1] > b[1] && a[2] > b[2]) printf("1");
            else if (a[1] < b[1] && a[2] < b[2]) printf("1");
            else printf("0");
        }
    }
    return 0;
}