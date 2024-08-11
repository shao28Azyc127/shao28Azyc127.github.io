#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, lian[25];
ll a[25], b[25], c[25], now[25], ans = 2000000000;
vector<int> v[25];
bool vis[25];
void dfs(int day) {
    if (day > n) {
        ll mf = 0;
        for (int i = 1; i <= n; ++i)
            if (now[i] < a[i])
                mf = max(mf, (a[i] - now[i] - 1) / b[i] + 1);
        ans = min(ans, day - 1 + mf);
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (vis[i])
            now[i] += b[i];
    for (int x = 1; x <= n; ++x) {
        if (vis[x] || lian[x] == 0)
            continue;
        for (auto y : v[x])
            ++lian[y];
        vis[x] = 1;
        now[x] += b[x];
        dfs(day + 1);
        for (auto y : v[x])
            --lian[y];
        vis[x] = 0;
        now[x] -= b[x];
    }
    for (int i = 1; i <= n; ++i)
        if (vis[i])
            now[i] -= b[i];
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}