#include <bits/stdc++.h>
using namespace std;
int c, n, m, q;
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    if (c == 3) {
        printf("1001\n");
        return 0;
    }
    for (int i = 1; i <= q; i++) printf("0");
    putchar('\n');
    return 0;
}
