#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, k, dis[N];
vector<int> G[N];
void bfs() {
    queue<int> q;
    q.push(1);
    memset(dis, 0x3f, sizeof dis);
    dis[1] = k;
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        if(f == n) {
            return;
        }
        for(int i = 0; i < G[f].size(); i++) {
            int v = G[f][i];
            if(dis[v] == 0x3f3f3f3f) {
                dis[v] = dis[f] + 1;
                q.push(v);
            }
        }
    }
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++) {
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        G[u].push_back(v);
    }
    bfs();
    printf("%d", (dis[n] + k - 1) / k * k);
    return 0;
}
