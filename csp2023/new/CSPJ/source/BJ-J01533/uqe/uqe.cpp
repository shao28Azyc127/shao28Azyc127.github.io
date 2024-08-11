#include <bits/stdc++.h>
using namespace std;

int T, M, a, b, c;

inline void solve() {
    scanf("%d%d%d", &a, &b, &c);
    if (a < 0) {
        a = -a, b = -b, c = -c;
    }
    int delta = b * b - 4 * a * c;
    if (delta < 0) {
        puts("NO");
        return;
    }
    if (delta == 0) {
        int tmp = 2 * a;
        int g = abs(__gcd(b, tmp));
        if (b == 0) 
            puts("0");
        else if (tmp / g != 1) 
            printf("%d/%d\n", -b / g, tmp / g);
        else
            printf("%d\n", -b / g);
        return;
    }
    int tmp = 2 * a;
    int g = abs(__gcd(b, tmp));
    int co = 1, sqr = 0;
    for (int i = sqrt(delta); i >= 1; i--)
        if (delta % (i * i) == 0) {
            if (i * i == delta) sqr = 1;
            co = i; 
            delta /= i * i;
            break;
        }
    if (sqr) co -= b;
    int q = abs(__gcd(co, tmp));
    if (sqr) {
        if (tmp / q != 1)
            printf("%d/%d\n", co / q, tmp / q);
        else
            printf("%d\n", co / q);
    } else {
        if (b != 0) {
            if (tmp / g != 1)
                printf("%d/%d", -b / g, tmp / g);
            else
                printf("%d", -b / g);
            putchar('+');
        }
        if (tmp / q != 1) {
            if (co / q != 1)
                printf("%d*sqrt(%d)/%d\n", co / q, delta, tmp / q);
            else
                printf("sqrt(%d)/%d\n", delta, tmp / q);
        } else {
            if (co / q != 1)
                printf("%d*sqrt(%d)\n", co / q, delta);
            else
                printf("sqrt(%d)\n", delta);
        }
            
    }
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &M);
    while (T--) solve();
    return 0;
}

// g++ uqe.cpp -o uqe && ./uqe
// expected 100pts

// Good Luck.