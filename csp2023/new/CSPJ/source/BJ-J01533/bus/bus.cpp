#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 5;
typedef long long ll;

int n, m, k, vis[MAXN];
vector<pair<int, int>> e[MAXN], g[MAXN];

struct Node {
    int u, cur;
};

inline bool check(int mid) {
    mid *= k;
    queue<Node> q;
    q.push({n, mid});
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        int u = now.u, cur = now.cur;
        if (u == 1 && cur % k == 0) return true;
        for (auto p: g[u]) {
            int v = p.first, a = p.second;
            if (cur >= a) q.push({v, cur - 1});
        }
    }
    return false;
}

int bfs() {
    vector<int> dis(MAXN, 0x3f3f3f3f);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto p: e[u]) {
            int v = p.first, a = p.second;
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[n];
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    ll sum = 0;
    for (int i = 1, u, v, a; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &a);
        sum += a;
        e[u].push_back({v, a});
        g[v].push_back({u, a});
    }
    if (sum == 0) {
        printf("%d\n", bfs());
        return 0;
    }
    int l = 0, r = 1000000, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    if (ans == -1) puts("-1");
    else printf("%d\n", ans * k);
}

// g++ bus.cpp -o bus && ./bus