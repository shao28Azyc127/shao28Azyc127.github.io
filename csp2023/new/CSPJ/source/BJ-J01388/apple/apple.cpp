#include <stdio.h>
int ceil3(int n) { return n / 3 + !!(n % 3); }
int ans1, ans2;
void solve(int n, int d) {
    if (n % 3 == 1 && ans2 == 0) ans2 = d + 1;
    if (n == 0) ans1 = d;
    else solve(n - ceil3(n), d + 1);
}
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n; scanf("%d", &n);
    solve(n, 0);
    printf("%d %d\n", ans1, ans2);
    return 0;
}