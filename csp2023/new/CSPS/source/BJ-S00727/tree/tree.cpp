#include <bits/stdc++.h>
using namespace std;
int n, x, y, a[510], b[510], c[510], num[510], flag[510];
int ans = 2e9;
vector<int> v[510];
void dfs(int x, int num[]) {
    int flag1 = 1;
    for (int i = 1; i <= n; i++) {
        if (!flag[i]) continue;
        num[i] += max(1, b[i] + x * c[i]);
        if (num[i] < a[i]) flag1 = 0;
    }
    if (flag1) {
        ans = min(ans, x);
        return;
    }
    if (x > n) dfs(x + 1, num);
    for (int i = 1; i <= n; i++) {
        if (!flag[i]) continue;
        for (int j = 0; j < v[i].size(); j++) {
            int y = v[i][j];
            if (!flag[y]) {
                flag[y] = 1;
                num[y] = max(b[y] + x * c[y], 1);
                dfs(x + 1, num);
                flag[y] = 0;
                num[y] = 0;
            }
        }
    }
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    flag[1] = 1;
    num[1] = max(1, b[1] + x * c[1]);
    dfs(2, num);
    printf("%d", ans);
    return 0;
}