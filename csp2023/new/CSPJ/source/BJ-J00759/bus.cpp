#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, k;
bool ok = false;
vector<pair<int, int> > g[10005];
void dfs(int u, int t) {
    if (u == 1) {
        if (t % k == 0) ok = true;
        return;
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first, a = g[u][i].second;
        if (t <= a) continue;
        dfs(v, t - 1);
        if (ok) return;
    }
}
bool check(int x) {
    ok = false;
    dfs(n, x);
    return ok;
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, aoj;
        cin >> u >> v >> aoj;
        g[v].push_back(make_pair(u, aoj));
    }
    int l = 0, r = 1000005 / k, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid * k)) ans = mid * k, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}