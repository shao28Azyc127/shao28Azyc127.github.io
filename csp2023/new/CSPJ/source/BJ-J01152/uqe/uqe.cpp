#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, maxn;
    scanf("%d%d", &t, &maxn);
    while (t--) {
        int a, b, c, flag;
        scanf("%d%d%d", &a, &b, &c);
        int p = b * b - 4 * a * c;
        if (p < 0) {
            printf("NO\n");
            continue;
        }
        int ans1 = (-b + sqrt(p)) / (2 * a);
        int ans2 = (-b - sqrt(p)) / (2 * a);
        printf("%d\n", max(ans1, ans2));
    }
    return 0;
}
