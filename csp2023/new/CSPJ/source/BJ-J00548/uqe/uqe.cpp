// Wish my son recovering soon.

#include <bits/stdc++.h>
using namespace std;
int t, M, a, b, c;
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
void output(int x, int y, int z = 0) {
    if (x == 0) { printf("0"); return; }
    if (x < 0) { printf("-"); x = -x; }
    int g = gcd(x, y);
    x /= g;
    y /= g;
    if (!(z && x == 1)) printf("%d", x);
    if (z) {
        if (x != 1) printf("*");
        printf("sqrt(%d)", z);
    }
    if (y != 1) printf("/%d", y);
}
void solve() {
    scanf("%d%d%d", &a, &b, &c);
    if (a < 0) { a *= -1; b *= -1; c *= -1; }
    int delta = b * b - 4 * a * c, t;
    if (delta < 0) {
        printf("NO");
        return;
    }
    if (delta == 0) t = 0;
    else {
        for (t = sqrt(delta) + 2; t >= 1; t--)
            if (delta % (t * t) == 0)
                break;
    }
    if (t * t == delta) {
        output(-b+t, a * 2);
        return;
    }
    if (b) output(-b, a * 2);
    if (b) printf("+");
    output(t, a * 2, delta / (t * t));
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &M);
    while (t--) {
        solve();
        printf("\n");
    }
    return 0;
}
