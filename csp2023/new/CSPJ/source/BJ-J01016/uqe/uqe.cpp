#include <bits/stdc++.h>
using namespace std;
int T, M, a, b, c;
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &M);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        int d = b * b - 4 * a * c;
        if (d < 0) {
            puts("NO");
            continue;
        }
        int t = sqrt(d);
        if (t * t == d) {
            int m = 2 * a, z = (a > 0) ? -b + t : -b - t;
            bool f = 0;
            if (m * z < 0) f = 1;
            m = abs(m), z = abs(z);
            int gcd = __gcd(m, z);
            if (f) printf("-");
            if (m == gcd) printf("%d", z / m);
            else printf("%d/%d", z / gcd, m / gcd);
            puts("");
            continue;
        }
        if (b != 0) {
            bool f = 0;
            if (a * b > 0) f = 1;
            a = abs(a), b = abs(b);
            int gcd = __gcd(2 * a, b);
            if (f) printf("-");
            if (2 * a == gcd) printf("%d", b / (2 * a));
            else printf("%d/%d", b / gcd, 2 * a / gcd);
            if (d != 0) printf("+");
        }
        if (d == 0) {
            puts("");
            continue;
        }
        a = abs(a);
        int mul = 1;
        for (int i = 2; i * i <= d; i++) {
            while (d % (i * i) == 0) {
                mul *= i, d /= (i * i);
            }
        }
        int gcd = __gcd(2 * a, mul);
        if (2 * a == gcd) {
            if (mul == 2 * a) printf("sqrt(%d)", d);
            else printf("%d*sqrt(%d)", mul / (2 * a), d);
        }
        else if (mul == gcd) printf("sqrt(%d)/%d", d, 2 * a / gcd);
        else printf("%d*sqrt(%d)/%d", mul / gcd, d, 2 * a / gcd);
        puts("");
    }
    return 0;
}