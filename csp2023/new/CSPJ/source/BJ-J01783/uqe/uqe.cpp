// 100pts
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL x, LL y) {
    if (!y) return x;
    return gcd(y, x % y);
}
bool chk(LL x) {
    LL sq = sqrtl(x);
    return sq * sq == x;
}
struct node {
    LL p, q, r;
    void f() {
        LL sq = sqrtl(r), i = 2, j = 0;
        while (i <= sq && r > 1) {
            while (r % i == 0) r /= i, j++;
            p *= (LL)(powl(i, (int)(j / 2)));
            if (j & 1) r *= i;
            i++, j = 0;
        }
        LL g = gcd(abs(p), abs(q));
        p /= g, q /= g;
        if (q < 0) p = -p, q = -q;
    }
    void print() {
        f();
        if (!r) {
            if (q == 1) printf("%lld", p);
            else printf("%lld/%lld", p, q);
        } else {
            if (p == 1 && q == 1) printf("sqrt(%lld)", r);
            else if (q == 1) printf("%lld*sqrt(%lld)", p, r);
            else if (p == 1) printf("sqrt(%lld)/%lld", r, q);
            else printf("%lld*sqrt(%lld)/%lld", p, r, q);
        }
    }
} c1, c2;
LL t, M, a, b, c, D;
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%lld%lld", &t, &M);
    while (t--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        D = b * b - 4 * a * c;
        if (D < 0) {
            printf("NO\n");
            continue;
        } else if (!D) {
            c1.p = -b, c1.q = 2 * a;
            c1.print();
        } else if (chk(D)) {
            c1.q = 2 * a;
            if (a > 0) c1.p = -b + sqrtl(D);
            else c1.p = -b - sqrtl(D);
            c1.print();
        } else {
            c1.p = -b, c1.q = 2 * a, c1.f();
            if (c1.p) c1.print(), putchar('+');
            c2.q = 2 * a, c2.r = D, c2.p = (a > 0 ? 1 : -1);
            c2.print();
        }
        putchar('\n');
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
