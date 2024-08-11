#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int T, m;
int a, b, c;
int gcd2(int x, int y) {
    if(y == 0) {
        return x;
    }
    return gcd2(y, x % y);
}
int gcd(int x, int y) {
    int xx = max(x, -x);
    int yy = max(y, -y);
    int g = gcd2(xx, yy);
    if(y < 0) {
        return -g;
    } else {
        return g;
    }
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &m);
    for(int ti = 1; ti <= T; ti++) {
        scanf("%d%d%d", &a, &b, &c);
        int dt = b * b - 4 * a * c;
        if(dt < 0) {
            printf("NO\n");
            continue;
        }
        int q = 0;
        int re = 0;
        for(int i = 2240; i >= 1; i--) {
            if(dt % (i * i) == 0) {
                q = i;
                break;
            }
        }
        if(dt == 0) {
            q = 0;
            re = 1;
        } else {
            re = dt / q / q;
        }
        if(re == 1) {
            //(q-b)/2a
            int p;
            int r = 2 * a;
            if(a < 0) {
                p = min(- q - b, q - b);
            } else {
                p = max(- q - b, q - b);
            }
            int g = gcd(p, r);
            p /= g, r /= g;
            if(r == 1) {
                printf("%d\n", p);
            } else {
                printf("%d/%d\n", p, r);
            }
            continue;
        }
        int p, r;
        if(b != 0) {
            p = -b;
            r = 2 * a;
            int g = gcd(p, r);
            p /= g, r /= g;
            if(r == 1) {
                printf("%d+", p);
            } else {
                printf("%d/%d+", p, r);
            }
        }
        int g;
        p = q;
        r = 2 * a;
        g = gcd(p, r);
        p /= g, r /= g;
        if(p < 0) {
            p *= -1;
        }
        if(p == 1 && r == 1) {
            printf("sqrt(%d)\n", re);
        } else if(p == 1) {
            printf("sqrt(%d)/%d\n", re, r);
        } else if(r == 1) {
            printf("%d*sqrt(%d)\n", p, re);
        } else {
            printf("%d*sqrt(%d)/%d\n", p, re, r);
        }
    }
    return 0;
}
