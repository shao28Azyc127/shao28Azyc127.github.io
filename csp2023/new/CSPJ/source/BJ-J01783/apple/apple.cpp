// 100pts
#include <bits/stdc++.h>
using namespace std;
int n, ans1, ans2;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    while (n) {
        if (!ans2 && n % 3 == 1) ans2 = ans1 + 1;
        ans1++, n -= (n - 1) / 3 + 1;
    }
    printf("%d %d\n", ans1, ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
