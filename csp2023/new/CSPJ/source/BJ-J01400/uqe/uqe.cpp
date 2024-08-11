#include <cstdio>
#include <cmath>
using namespace std;

int t, top;
int a, b, c, delta;

bool check(int x) {
    int sqr = sqrt(x);
    if (sqr * sqr == x) return true;
    return false;
}
int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &top);
    while (t--) {
        scanf("%d%d%d", &a, &b, &c);
        delta = b * b - 4 * a * c;
        if (delta < 0) puts("NO");
        else if (check(delta)) {
            int num = -b + sqrt(delta) * ((a > 0) ? 1 : -1);
            if (num == 0) {
                puts("0");
                continue;
            }
            int w = ((num > 0) ? 1 : -1) * ((a > 0) ? 1 : -1); // negative
            if (w == -1) printf("-");
            if (a < 0) a = -a; if (num < 0) num = -num;
            int g = gcd(2 * a, num);
            if (g == 2 * a) printf("%d\n", num / g);
            else printf("%d/%d\n", num / g, 2 * a / g);
        } else if (b == 0) {
            int p, q;
            for (int i = sqrt(delta); i >= 1; i--) {
                if (delta % (i * i) == 0) {
                    p = i;
                    q = delta / (i * i);
                    break;
                }
            }
            if (a < 0) a = -a;
            if (2 * a == p) {
                printf("sqrt(%d)\n", q);
                continue;
            }
            int g = gcd(2 * a, p);
            if (g == 2 * a) printf("%d*sqrt(%d)\n", p / g, q);
            else if (g == p) printf("sqrt(%d)/%d\n", q, 2 * a / g);
            else printf("%d*sqrt(%d)/%d\n", p / g, q, 2 * a / g);
        } else {
            int num = -b;
            int w = ((num > 0) ? 1 : -1) * ((a > 0) ? 1 : -1); // negative
            if (w == -1) printf("-");
            if (a < 0) a = -a; if (num < 0) num = -num;
            int g = gcd(2 * a, num);
            if (g == 2 * a) printf("%d", num / g);
            else printf("%d/%d", num / g, 2 * a / g);
            int p, q;
            for (int i = sqrt(delta); i >= 1; i--) {
                if (delta % (i * i) == 0) {
                    p = i;
                    q = delta / (i * i);
                    break;
                }
            }
            printf("+");
            if (a < 0) a = -a;
            if (2 * a == p) {
                printf("sqrt(%d)\n", q);
                continue;
            }
            g = gcd(2 * a, p);
            if (g == 2 * a) printf("%d*sqrt(%d)\n", p / g, q);
            else if (g == p) printf("sqrt(%d)/%d\n", q, 2 * a / g);
            else printf("%d*sqrt(%d)/%d\n", p / g, q, 2 * a / g);
        }
    }
    return 0;
}
