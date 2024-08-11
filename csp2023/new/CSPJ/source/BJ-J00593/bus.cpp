#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int NR = 1e4 + 10;
int G[NR][NR];
bool vis[NR];
    int n, m, k;
int ans = 2e9;

void dfs(int x, int t) {
    if(x == n) {
        if(t % k == 0) ans = min(ans, t);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(G[x][i] != -1) {
            int v = G[x][i];
            if(vis[v] || G[x][i] > t) continue;
            vis[v] = true;
            dfs(v, t + 1);
        }
    }
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    memset(G, -1, sizeof(G));
    scanf("%d%d%d", &n, &m, &k);
    int mx = 0;
    for(int i = 1; i <= m; i++) {
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        G[u][v] = a;
        mx = max(mx, a);
    }
    for(int i = 0; i <= mx; i += k) {
        memset(vis, 0, sizeof(vis));
        vis[1] = true;
        dfs(1, i);
    }
    printf("%d", ans);
    return 0;
}

