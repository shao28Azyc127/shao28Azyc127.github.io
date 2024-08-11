#include <iostream>
#include <cmath>
using namespace std;

int t, m;
int tr, x, y;
int a, b, c;
int v, p, q;
int r, q1, q2, q3;

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &m);
    while (t--) {
        scanf("%d%d%d", &a, &b, &c);
        tr = b*b - 4*a*c;
        if (tr < 0) {
            printf("NO\n");
            continue;
        }
        x = (0-b+sqrt(tr))/(2*a);
        y = (0-b-sqrt(tr))/(2*a);
        printf("%d\n", max(x, y));
    }

    return 0;
}
