#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, a[9][9], b[9], mis[9], ans;
void dfs(int u) {
    if (u > 5) {
        for (int i = 1; i <= n; i++) {
            int tp = 0;
            for (int j = 1; j <= 5; j++) {
                if (a[i][j] != b[j]) mis[++tp] = j;
            }
            if (!tp || tp > 2) return;
            else if (tp == 2) {
                if (mis[1] + 1 != mis[2]) return;
                int c1 = a[i][mis[1]] - b[mis[1]];
                int c2 = a[i][mis[2]] - b[mis[2]];
                if (c1 < 0) c1 = 10 + c1;
                if (c2 < 0) c2 = 10 + c2;
                if (c1 != c2) return;
            }
        }
        ans++;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        b[u] = i;
        dfs(u + 1);
    }
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) scanf("%d", &a[i][j]);
    }
    dfs(1);
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
// 0 0 1 1 5
