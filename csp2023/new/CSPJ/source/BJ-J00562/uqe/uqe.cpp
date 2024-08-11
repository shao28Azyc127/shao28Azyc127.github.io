#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long l;
l t, m, n, a, b, c, x1, x2;

l gcd(l a, l b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void yls(l a, l b) {
    l g = gcd(a, b);
    b /= g;
    a /= g;
    if (b < 0) {
        a *= -1;
        b *= -1;
    }
    if (b == 1) printf("%lld", a);
    else printf("%lld/%lld", a, b);
}

void print(l b, l a, l n) {
    a = 2 * a;
    if (abs((l)(sqrt(n)) * (l)(sqrt(n)) - n) <= 1e-10) {
        b = (-b) + sqrt(n);
        yls(b, a);
    } else {
        if (b != 0) {
            yls(-b, a);
            printf("+");
        }
        l x = 1;
        for (l i = 2; i * i <= n; ++i) {
            while (n % (i * i) == 0) {
                x *= i;
                n /= (i * i);
            }
        }
        l g = gcd(a, x);
        x /= g;
        a /= g;
        if (x < 0) x *= -1;
        if (a < 0) a *= -1;
        if (a == x && x == 1) {
            printf("sqrt(%lld)", n);
        } else if (a == 1) {
            printf("%lld*sqrt(%lld)", x, n);
        } else if (x == 1) {
            printf("sqrt(%lld)/%lld", n, a);
        } else {
            printf("%lld*sqrt(%lld)/%lld", x, n, a);
        }
    }
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%lld%lld", &t, &m);
    for (l i = 1; i <= t; ++i) {
        scanf("%lld%lld%lld", &a, &b, &c);
        n = pow(b, 2) - 4 * a * c;
        if (n < 0) {
            printf("NO");
        } else if (n == 0) {
            yls(-b, 2 * a);
        } else {
            print(b, a, n);
        }
        printf("\n");
    }
    return 0;
}
