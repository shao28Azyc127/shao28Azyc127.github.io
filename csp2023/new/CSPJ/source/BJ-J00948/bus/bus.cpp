#include <bits/stdc++.h>
#define int long long
using namespace std; // 30
int n, m, k, cnt = 0;
struct Edge{
    int v, w;
    int next;
}e[20005];
int head[10005];
void addEdge(int u, int v, int w){
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
struct Node{
    int x, step;
};
queue<Node> q;
bool vis[10005][105];
int bfs(){
    q.push((Node){1, 0});
    vis[1][0] = true;
    while (!q.empty()){
        int x = q.front().x, step = q.front().step;
        q.pop();
        if (x == n && step % k == 0) return step;
        for (int i = head[x]; i; i = e[i].next){
            int nx = e[i].v;
            if (vis[nx][(step + 1) % k]) continue;
            vis[nx][(step + 1) % k] = true;
            q.push((Node){nx, step + 1});
        }
    }
    return -1;
}
signed main(){
    freopen("bus.in", "r",  stdin);
    freopen("bus.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    bool flag = true;
    while (m--){
        int u, v, a;
        scanf("%lld%lld%lld", &u, &v, &a);
        addEdge(u, v, a);
        flag |= (!a);
    }
    if (flag){
        printf("%lld\n", bfs());
        return 0;
    }
    printf("-1\n");
    return 0;
}
