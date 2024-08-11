#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int sid, T;
int n, m;
struct node {
    int types;//0-same, 1-against, 2-T/F/U
    int id;//same with xxx / 1-T, 2-F, 3-U
} a[N];
int qf[4] = {0, 2, 1, 3};
struct Edge {
    int to;
    int tp;
};
Edge make(int v, int w) {
    Edge res;
    res.to = v;
    res.tp = w;
    return res;
}
vector<Edge> g[N];
int qd[N];
void link(int u, int v, int w) {
    g[u].push_back(make(v, w));
    g[v].push_back(make(u, w));
    //cout << u << " " << v << " " << w << endl;
}
int pnt;
int vis[N];
int siz = 0;
void findvl(int u) {
    vis[u] = 1;
    if(qd[u] != 0) pnt = u;
    if(qd[u] == 0) siz++;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].to;
        if(vis[v] != 0) continue;
        findvl(v);
    }
}
int ans = 0;
int tmp[N];
bool solve(int u) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].to;
        int now = 0;
        if(g[u][i].tp == 0) {
            now = tmp[u];
        } else {
            now = qf[tmp[u]];
        }
        if(tmp[v] == 0) {
            tmp[v] = now;
            if(!solve(v)) return false;
        } else if(now != tmp[v]) {
            return false;
        }
    }
    return true;
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &sid, &T);
    for(int ti = 1; ti <= T; ti++) {
        scanf("%d%d", &n, &m);
        ans = 0;
        for(int i = 1; i <= n; i++) {
            a[i].types = 0;
            a[i].id = i;
            g[i].clear();
            qd[i] = 0;
            vis[i] = 0;
            tmp[i] = 0;
        }
        char op;
        int x, y;
        for(int i = 1; i <= m; i++) {
            cin >> op;
            scanf("%d", &x);
            if(op == 'T') {
                a[x].types = 2;
                a[x].id = 1;
            } else if(op == 'F') {
                a[x].types = 2;
                a[x].id = 2;
            } else if(op == 'U') {
                a[x].types = 2;
                a[x].id = 3;
            } else if(op == '+') {
                scanf("%d", &y);
                a[x].types = a[y].types;
                a[x].id = a[y].id;
            } else if(op == '-') {
                scanf("%d", &y);
                if(a[y].types <= 1) {
                    a[x].types = a[y].types ^ 1;
                    a[x].id = a[y].id;
                } else {
                    a[x].types = 2;
                    a[x].id = qf[a[y].id];
                }
            } else {
                printf("dthkxy AK IOI\n");
            }
        }
        for(int i = 1; i <= n; i++) {
            if(a[i].types == 0) {
                if(a[i].id != i) {
                    link(a[i].id, i, 0);
                }
            } else if(a[i].types == 1) {
                if(a[i].id == i) {
                    qd[i] = 3;
                    ans++;
                } else {
                    link(a[i].id, i, 1);
                }
            } else if(a[i].types == 2) {
                qd[i] = a[i].id;
                if(qd[i] == 3) ans++;
            } else {
                printf("dthkxy AK IOI\n");
            }
        }
        for(int i = 1; i <= n; i++) {
            if(vis[i] == 0) {
                pnt = 0;
                siz = 0;
                findvl(i);
                if(pnt != 0) {
                    if(qd[pnt] == 3) {
                        ans += siz;
                    }
                    continue;
                }
                tmp[i] = 1;
                if(!solve(i)) {
                    ans += siz;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
