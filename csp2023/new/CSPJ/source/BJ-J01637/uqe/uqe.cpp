#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int T, M, a, b, c;
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &M);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        if (b * b - 4 * a * c < 0) {
            printf("NO\n");
            continue;
        }
        else {
            int xa = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
            int xb = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
            printf("%d\n", max(xa, xb));
        }
    }
    return 0;
}