#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e4 + 5;
const int inf = 1e9 + 5;
int n, m, k;
struct node {
    int to;
    int a;
};
node make(int to0, int tim0) {
    node res;
    res.to = to0;
    res.a = tim0;
    return res;
}
vector<node> g[N * 100];
int dis[N * 100];
int vis[N * 100];
bool operator<(node p1, node p2) {
    if(p1.a != p2.a) {
        return p1.a > p2.a;
    }
    return p1.to > p2.to;
}
priority_queue<node> pq;
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    int u, v, a;
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &a);
        for(int kk = 0; kk < k; kk++) {
            g[u + kk * n].push_back(make(v + (kk + 1) % k * n, a));
        }
    }
    for(int i = 1; i <= k * n; i++) {
        dis[i] = inf;
    }
    dis[1] = 0;
    pq.push(make(1, 0));
    while(!pq.empty()) {
        node now = make(-1, -1);
        while(!pq.empty()) {
            now = pq.top();
            pq.pop();
            if(vis[now.to] == 0) {
                break;
            } else {
                now.to = -1;
            }
        }
        if(now.to == -1) {
            break;
        }
        u = now.to;
        vis[u] = 1;
        for(int i = 0; i < g[u].size(); i++) {
            v = g[u][i].to;
            int tp = dis[u] + 1;
            if(tp <= g[u][i].a) {
                tp = ((g[u][i].a - tp) / k + 1) * k + tp;
            }
            if(tp < dis[v]) {
                dis[v] = tp;
                pq.push(make(v, dis[v]));
            }
        }
    }
    if(dis[n] == inf) {
        printf("-1\n");
    } else {
        printf("%d\n", dis[n]);
    }
    return 0;
}
