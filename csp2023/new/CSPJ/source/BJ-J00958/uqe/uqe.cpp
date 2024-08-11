#include <cstdio>
#include <sstream>
using namespace std;
typedef long long LL;
LL v1, v2, v3, v4, T, M, a, b, c, d;
LL maxSquRoot(LL x) {
    LL r = 0;
    for (int i = 1; i * i <= x; i ++ ) {
        if (x % (i * i) == 0) r = i;
    }

    return r;
}

LL gcd(LL x, LL y) {
    if (x < y) {
        swap(x, y);
    }

    if (y == 0) {
        return x;
    } else {
        return gcd(y, x % y);
    }
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%lld%lld", &T, &M);
    for (int i = 0; i < T; i ++ ) {
        scanf("%lld%lld%lld", &a, &b, &c);
        d = b * b - 4 * a * c;
        if (d < 0) {
            printf("NO\n");
            continue;
        }

        v4 = maxSquRoot(d);
        if (v4 * v4 == d || d == 0) {
            if (a > 0) v1 = 0 - b + v4;
            else v1 = 0 - b - v4;
            v2 = 2 * a;
            v3 = gcd(abs(v1), abs(v2));
            v1 = v1 / v3;
            v2 = v2 / v3;
            if (v2 < 0) {
                v1 = -v1;
                v2 = -v2;
            }

            if (v2 == 1) {
                printf("%lld\n", v1);
                continue;
            } else {
                printf("%lld/%lld\n", v1, v2);
                continue;
            }
        } else {
            v1 = 0 - b;
            v2 = 2 * a;
            v3 = gcd(abs(v1), abs(v2));
            v1 = v1 / v3;
            v2 = v2 / v3;
            if (v1 != 0) {
                if (v2 < 0) {
                    v1 = -v1;
                    v2 = -v2;
                }

                if (v2 == 1) {
                    printf("%lld+", v1);
                } else {
                    printf("%lld/%lld+", v1, v2);
                }
            }

            d = d / v4 / v4;
            v2 = 2 * a;
            v3 = gcd(abs(v4), abs(v2));
            v4 = v4 / v3;
            v2 = v2 / v3;
            if (v2 < 0) {
                v2 = -v2;
            }

            if (v4 == 1 && v2 == 1) {
                printf("sqrt(%lld)\n", d);
                continue;
            } else if (v2 == 1) {
                printf("%lld*sqrt(%lld)\n", v4, d);
            } else if (v4 == 1) {
                printf("sqrt(%lld)/%lld\n", d, v2);
            } else {
                printf("%lld*sqrt(%lld)/%lld\n", v4, d, v2);
            }
        }
    }

    return 0;
}

