#include <cstdio>
#include <cmath>

int T, M, a, b, c;

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d %d", &T, &M);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &a, &b, &c);
        double delta = b * b - (4 * a * c);
        if (delta < 0) {
            printf("NO\n");
            continue;
        }
        if (delta == 0) {
            if ((0 - b) % (2 * a) == 0)
                printf("%d\n", (0 - b) / (2 * a));
            else
                printf("-%d/%d\n", b, (2 * a));
        }
        if (delta > 0) {
            if (((0 - b + sqrt(delta)) / (2 * a)) > ((0 - b - sqrt(delta)) / (2 * a))) {
                if (sqrt(delta) * sqrt(delta) == delta) {
                    if (int(0 - b + sqrt(delta)) % (2 * a) == 0)
                        printf("%d\n", ((0 - b + sqrt(delta)) / (2 * a)));
                    else
                        printf("%d/%d\n", (0 - b + sqrt(delta)), (2 * a));
                } else {
                    if ((0 - b) / (2 * a) != 0) {
                        if ((0 - b) % (2 * a))
                            printf("%d+", (0 - b) / (2 * a));
                        else
                            printf("%d/%d+", 0 - b, 2 * a);
                    }
                    if (2 * a == 1)
                        printf("sqrt(%d)\n", delta);
                    else {
                        if (2 * a > 1)
                            printf("sqrt(%d)/%d\n", delta, 2 * a);
                        else
                            printf("%d*sqrt(%d)\n", 1 / (2 * a), delta);
                    }
                }
            }
        }
    }
    return 0;
}
