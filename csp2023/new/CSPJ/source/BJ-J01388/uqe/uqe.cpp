#include <stdio.h>
#include <math.h>
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int findsqr(int n) {
    for (int i = sqrt(n); i >= 1; i--) if (n % (i * i) == 0) return i;
    return 1;
}
int output(int p, int q) {//q>0
    if (p == 0) return 1;
    int g = gcd(p, q); if (g < 0) g = -g;
    if (g != 0) { p /= g; q /= g; }
    printf("%d", p); if (q != 1) printf("/%d", q);
    return 0;
}
void solve(int a, int b, int c) {
    if (a < 0) { a = -a; b = -b; c = -c; }
    int delta = b * b - 4 * a * c;
    if (delta < 0) { puts("NO"); return; }
    int sqr = findsqr(delta); delta /= sqr * sqr;
    int ret = 1;
    if (delta == 1) ret &= output(-b + sqr, a * 2);
    else {
        ret &= output(-b, a * 2);
        if (delta != 0) {
            if (!ret) printf("+"); int p = sqr, q = a * 2;
            int g = gcd(p, q);
            if (g != 0) { p /= g; q /= g; }
            if (p != 1) printf("%d*", p);
            printf("sqrt(%d)", delta);
            if (q != 1) printf("/%d", q);
            ret = 0;
        }
    }
    if (ret) printf("0");
    puts("");
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, m; scanf("%d%d", &T, &m);
    while (T--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        solve(a, b, c);
    }
    return 0;
}