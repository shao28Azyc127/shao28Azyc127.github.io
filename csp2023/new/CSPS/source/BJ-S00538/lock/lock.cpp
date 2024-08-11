#include <bits/stdc++.h>
using namespace std;
int n, a[15][10], ans, path[10];
bool check() {
    for (int i = 1; i <= n; i++) {
        int sum = 0, num = 0, las = 0;
        for (int j = 1; j <= 5; j++) {
            if (a[i][j] == path[j]) continue;
            sum++;
            if (sum > 2 || (sum == 2 && j - 1 != las) || (sum == 2 && ((a[i][j] - path[j] + 10) % 10) != num)) return false;
            if (sum == 1) num = (a[i][j] - path[j] + 10) % 10, las = j;
        }
        if (sum == 0) return false;
    }
    return true;
}
void dfs(int wei) {
    if (wei == 6) {
        if (check()) ans++;
        return ;
    }
    for (int i = 0; i <= 9; i++) {
        path[wei] = i;
        dfs(wei + 1);
    }
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) scanf("%d", &a[i][j]);
    }
    ans = 0;
    dfs(1);
    printf("%d", ans);
    return 0;
}
