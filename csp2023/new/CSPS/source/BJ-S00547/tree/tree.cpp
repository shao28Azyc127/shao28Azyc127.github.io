#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;
int n, a[100005], b[100005], c[100005];
vector<int> g[100005];
bool vis[100005];
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        if (b[i] < 1) b[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<pair<int, int> > q;
    vis[1] = true;
    q.push(make_pair(1, 0));
    int ans = 0;
    while (!q.empty()) {
        int u = q.front().first, d = q.front().second; q.pop();
        ans = max(ans, d + a[u] / b[u] + ((a[u] % b[u] == 0) ? 0 : 1));
        for (int v : g[u]) {
            if (!vis[v]) vis[v] = true, q.push(make_pair(v, d + 1));
        }
    }
    cout << ans << '\n';
	return 0;
}

