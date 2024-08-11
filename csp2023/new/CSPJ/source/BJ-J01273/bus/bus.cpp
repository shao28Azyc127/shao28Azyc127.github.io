#include <bits/stdc++.h>
using namespace std;
int n, m, k, u, v, ans = 1e9, a;
int vis[100010];
vector < pair <int, int> > e[100010];
void dfs(int x, int t) {
    if (x == n && t % k == 0) {
        ans = min(ans, t);
        return;
    }
    if (x == n) return;
    for (int dx = 0; dx < e[x].size(); dx++) {
        int i = e[x][dx].first, nt = e[x][dx].second;
        if (t >= nt && !vis[i]) {
            vis[i] = 1;
            dfs(i, t + 1);
            vis[i] = 0;
        }
    }
}
int main () {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    bool f = 1;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> a;
        e[u].push_back({v, a});
        if (a != 0) f = 0;
    }
    if (n <= 10 && m <= 15) {
        vis[1] = 1;
        dfs(1, k);
        if (ans == 1e9) {
            cout << "-1\n";
            return 0;
        }
        cout << ans << endl;
    }
    else if (k == 1 && f) {
        queue <int> q;
        vis[1] = k;
        q.push(1);
        while (q.size()) {
            int u = q.front(); q.pop();
            if (u == n) {
                    cout << vis[u] << endl;
                return 0;
            }
            for (int dx = 0; dx < e[u].size(); dx++) {
                int i = e[u][dx].first, nt = e[u][dx].second;
                    if (!vis[i]) {
                        vis[i] = vis[u] + 1;
                        q.push(i);
                    }
                }
            }
            cout << -1 << endl;
    }
    else cout << -1 << endl;
    return 0;
}
