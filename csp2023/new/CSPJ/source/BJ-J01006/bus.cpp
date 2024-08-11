#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int head[50010], nxt[100010], to[100010], a[100010], idx = 0;
void addEdge(int u, int v, int w) {
    nxt[++idx] = head[u];
    a[idx] = w;
    to[idx] = v;
    head[u] = idx;
}

int n, m, k;
int dis[50010];
bool vis[50010];
void dijkstra() {
    memset(dis, 0x3f, sizeof dis);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({dis[1] = k, 1});
    while (!q.empty()) {
        int stp = q.top().first, u = q.top().second;
        q.pop();
        if (u == n && stp % k == 0) {
            cout << stp;
            exit(0);
        }
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        for (int i = head[u]; i; i = nxt[i]) {
            if (stp < a[i]) {
                continue;
            }
            int v = to[i];
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push({dis[v], v});
            }
        }
    }
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int u, v, w; m; m--) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    dijkstra();
    cout << -1;
    return 0;
}
