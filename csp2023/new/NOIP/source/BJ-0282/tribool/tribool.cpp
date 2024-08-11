#include <cstdio>
#include <bitset>
#include <iostream>
using namespace std;

struct edge {
    int v, w, to;
} E[100015];

bitset<100015> s, vis, VIS;
int T, c, n, m, ans, eid, tri[100015], p[100015], opt[100015], sz[100015];

void insert(int u, int v, int w) {
    E[eid].v = v;
    E[eid].w = w;
    E[eid].to = p[u];
    p[u] = eid++;
    return;
}

void dfs(int u, int id, bool &res) {
    VIS[u] = vis[u] = 1;
    // printf("dfs(%d)\n", u);
    sz[id]++;
    int v, w;
    for (int i = p[u]; ~i; i = E[i].to) {
        v = E[i].v;
        w = E[i].w;
        if (!vis[v]) {
            if (!VIS[v]) {
                // printf("(%d, %d)\n", u, v);
                opt[v] = opt[u] ^ w;
                dfs(v, id, res);
            }
            else {
                sz[id] += sz[v];
            }
        }
        else {
            // printf("[%d, %d]\n", u, v);
            if (opt[u] ^ w ^ opt[v]) {
                res = 1;
            }
        }
    }
    vis[u] = 0;
    return;
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d %d", &c, &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; i++) {
            tri[i] = i;
            p[i] = -1;
            opt[i] = 0;
            sz[i] = 0;
        }
        eid = 0;
        char op;
        int x, y;
        while (m--) {
            op = getchar();
            op = getchar();
            if (op == 'T') {
                scanf("%d", &x);
                tri[x] = -2;
                s[x] = 0;
            }
            else if (op == 'F') {
                scanf("%d", &x);
                tri[x] = -1;
                s[x] = 0;
            }
            else if (op == 'U') {
                scanf("%d", &x);
                tri[x] = 0;
                s[x] = 0;
            }
            else if (op == '+') {
                scanf("%d %d", &x, &y);
                tri[x] = tri[y];
                s[x] = s[y];
            }
            else {
                scanf("%d %d", &x, &y);
                tri[x] = tri[y];
                s[x] = s[y] ^ 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            // cout << tri[i] << ' ' << s[i] << endl;
            if (!tri[i]) {
                insert(0, i, 0);
            }
            if (tri[i] > 0) {
                insert(tri[i], i, s[i]);
            }
        }
        bool res = 0;
        opt[0] = 0;
        dfs(0, 0, res);
        ans += sz[0] - 1;
        for (int i = 1; i <= n; i++) {
            if (!VIS[i]) {
                res = 0;
                opt[i] = 0;
                dfs(i, i, res);
                if (res) {
                    ans += sz[i];
                }
            }
        }
        printf("%d\n", ans);
        ans = 0;
        s.reset();
        vis.reset();
        VIS.reset();
    }
    return 0;
}