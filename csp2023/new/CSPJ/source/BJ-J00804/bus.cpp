#include <bits/stdc++.h>
using namespace std;

int n, m, k, flag, a[20005], maxn, cnt;
vector<int> s[20005];

void dfs(int x, int y) {
    if (x == n) {
        if (y % k == 0) flag = 1, cnt = y;
        return;
    }
    for (auto i : s[x]) {
        if (flag) return;
        int w = maxn;
        maxn = max(maxn, a[i]);
        dfs(i, y + 1);
        if (flag) return;
        maxn = w;
    }
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d%d", &u, &v, &a[i]);
        s[u].push_back(v);
    }
    dfs(1, 0);
    if (flag) {
        printf("%d\n", maxn + maxn % k + cnt);
    } else printf("-1\n");
    return 0;
}
