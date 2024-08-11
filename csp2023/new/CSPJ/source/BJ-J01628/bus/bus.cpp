#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, m, k;
vector<int> g[10005];
bool f[10005];
int ans = 114514199;

void dfs(int node, int time) {
    if (node == n) {
        if (time % k == 0)
            ans = min(ans, time);
        return ;
    }
    f[node] = 1;
    for (auto i: g[node])
        if (!f[i])
            dfs(i, time+1);
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        g[u].push_back(v);
    }
    dfs(1, 0);
    if (ans == 114514199)
        cout << "-1";
    else
        cout << ans;
    return 0;
}