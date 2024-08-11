#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, k, cnt[N];
vector<int> g[N];
struct node {
    int t, x;
};
queue<node> q;
void bfs() {
    q.push({1, 0});
    while (!q.empty()) {
        int x = q.front().x;
        int t = q.front().t;
        q.pop();
        ++cnt[x];
        if (cnt[x] > k) {
            printf("%d", -1);
            exit(0);
        }
        if (x == n && t % k == 0) {
            printf("%d", t);
            exit(0);
        }
        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i];
            q.push(node{y, t + 1});
        }
    }
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    int u, v, w;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(v);
    }
    bfs();
    return 0;
}