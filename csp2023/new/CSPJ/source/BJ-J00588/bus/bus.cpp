#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, ans = 2e9;
bool flag = false;
bool vis[10001];
vector<int> g[10001], w[10001];

void dfs(int x, int tim) {
    if (x == n) {
        if (tim % k == 0 && tim < ans) {
            ans = tim;
            flag = true;
        }
        return ;
    }
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (!vis[y] && tim >= w[x][i]) {
            vis[y] = true;
            dfs(y, tim + 1);
            vis[y] = false;
        }
    }
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    int maxa = -1;
    for (int i = 1; i <= m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        g[u].push_back(v);
        w[u].push_back(a);
        maxa = max(maxa, a);

    }
    for (int i = 0; (i - 1) * k <= maxa; i++) {
        int s = i * k;
        dfs(1, s);
    }
    if (!flag) cout <<-1 << endl;
    else cout << ans << endl;
    return 0;
}
