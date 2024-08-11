#include <bits/stdc++.h>
using namespace std;
int m, t;
int a, b, c, r;
bool f1, f2, f3;
int refe[2005];
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= 2000; i++) {
        refe[i] = i * i;
    }

    while (t--) {
        f1 = 0, f2 = 0, f3 = 0, r = 1;
        scanf("%d%d%d", &a, &b, &c);
        if (c == 0) {
            //b/a
            if (a < 0) f1 = 1;
            if (b < 0) f2 = 1;
            b = abs(b);
            a = abs(a);
            int g = __gcd(a, b);
            b /= g;
            a /= g;
            if (b == 0) {
                printf("0\n");
                continue;
            }
            if (f1 != f2) {
                if (a == 1) printf("%d\n", b);
                else printf("%d/%d\n", b, a);
            } else {
                printf("0\n");
            }
        }
        int d = pow(b, 2) - 4 * a * c;
        if (d < 0) printf("NO\n");
        else if (d == 0) {
            if (a < 0) f1 = 1;
            if (b < 0) f2 = 1;
            b = abs(b);
            a = abs(a);
            a *= 2;
            int g = __gcd(a, b);
            b /= g;
            a /= g;
            if (b == 0) {
                printf("0\n");
                continue;
            }
            if (f1 != f2) {
                if (a == 1) printf("%d\n", b);
                else printf("%d/%d\n", b, a);
            } else {
                if (a == 1) printf("-%d\n", b);
                else printf("-%d/%d\n", b, a);
            }
        } else {
            if (a < 0) f1 = 1;
            if (b < 0) f2 = 1;
            b = abs(b);
            a = abs(a);
            a *= 2;

            int i = 2;
            while (refe[i] <= d) {
                if (d % refe[i] == 0) {
                    d /= refe[i];
                    r *= sqrt(refe[i]);
                }
                else i++;
            }
            int g = __gcd(a, __gcd(b, r));
            b /= g;
            a /= g;
            r /= g;
            int g1 = __gcd(a, b + 1);
            int g2 = __gcd(a, b + r);
            int g3 = __gcd(a, b);
            int g4 = __gcd(a, r);
            if (f1 != f2) {
                if (a == 1) {
                    if (r == 1) {
                        if (d == 1) printf("%d\n", b + 1);
                        else if (b==0) printf("sqrt(%d)\n", d);
                        else printf("%d+sqrt(%d)\n", b, d);
                    } else {
                        if (d == 1) printf("%d\n", b + r);
                        else if (b!=0) printf("%d+%d*sqrt(%d)\n", b, r, d);
                        else printf("%d*sqrt(%d)\n", r, d);
                    }
                } else {
                    if (r == 1) {
                        if (d == 1) {
                            a /= g1;
                            int ans = (b + 1) / g1;
                            if (a != 1) printf("%d/%d\n", b + 1, a);
                            else printf("%d\n", ans);
                        }
                        else if (b!=0) printf("%d/%d+sqrt(%d)/%d\n", b/g3, a/g3, d ,a);
                        else printf("sqrt(%d)/%d\n", d ,a);
                    } else {
                        if (d == 1) {
                            a /= g2;
                            int ans = (b + r) / g2;
                            if (a != 1) printf("%d/%d\n", b + r, a);
                            else printf("%d\n", ans);
                        } else if (b!=0) printf("%d/%d+%d*sqrt(%d)/%d\n", b/g3, a/g3, r/g4, d, a/g4);
                        else printf("%d*sqrt(%d)/%d\n", r/g4, d, a/g4);
                    }
                }
            } else {
                if (a == 1) {
                    if (r == 1) {
                        if (d == 1) printf("-%d\n", b + 1);
                        else if (b!=0) printf("-%d+sqrt(%d)\n", b, d);
                        else printf("sqrt(%d)\n", d);
                    } else {
                        if (d == 1) printf("-%d\n", b + r);
                        else if (b!=0) printf("-%d+%d*sqrt(%d)\n", b, r, d);
                        else printf("%d*sqrt(%d)\n", r, d);
                    }
                } else {
                    if (r == 1) {
                        if (d == 1) {
                            a /= g1;
                            int ans = (b + 1) / g1;
                            if (a != 1) printf("-%d/%d\n", b + 1, a);
                            else printf("-%d\n", ans);
                        }
                        else if (b!=0) printf("-%d/%d+sqrt(%d)/%d\n", b/g3, a/g3, d ,a);
                        else printf("sqrt(%d)/%d\n", d ,a);
                    } else {
                        if (d == 1) {
                            a /= g2;
                            int ans = (b + r) / g2;
                            if (a != 1) printf("-%d/%d\n", b + r, a);
                            else printf("-%d\n", ans);
                        } else if (b!=0) printf("-%d/%d+%d*sqrt(%d)/%d\n", b/g3, a/g3, r/g4, d, a/g4);
                        else printf("%d*sqrt(%d)/%d\n", r/g4, d, a/g4);
                    }
                }
            }
        }
    }
    return 0;
}
