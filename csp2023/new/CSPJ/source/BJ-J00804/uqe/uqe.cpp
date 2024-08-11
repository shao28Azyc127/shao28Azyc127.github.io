#include <bits/stdc++.h>
using namespace std;

int t, m;

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &m);
    while (t--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int w = b * b - 4 * a * c;
        if (w < 0) {
            printf("NO\n");
            continue;
        }
        int ans1 = -b + sqrt(w) / (2 * a), ans2 = -b - sqrt(w) / (2 * a);
        printf("%d\n", max(ans1, ans2));
    }
    return 0;
}
