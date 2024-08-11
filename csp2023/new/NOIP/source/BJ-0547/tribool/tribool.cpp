#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;
const int maxn = 1e5 + 5;

int n, m, t, c;

namespace Sub12 {
    // TFU
    int x[15][maxn], y[15][maxn], op[maxn], u[maxn], v[maxn];
    const int T = 1, F = 2, U = 3, P = 4, M = 5;
    int getop (char t) {
        if (t == 'T') return T;
        if (t == 'F') return F;
        if (t == 'U') return U;
        if (t == '+') return P;
        if (t == '-') return M;
        return 0;
    }
    int cnt = 1;
    void dfs (int p) {
        if (p > n) {
            cnt ++;
            for (int i = 1; i <= n; i ++) {
                x[i][cnt] = x[i][cnt - 1];
                y[i][cnt] = y[i][cnt - 1];
            }
            return;
        }
        for (int i = 1; i <= 3; i ++) {
            x[p][cnt] = i;
            y[p][cnt] = i;
            dfs (p + 1);
        }
    }
    void sub12 () {
        memset(x, 0, sizeof(x));
        scanf ("%d%d", &n, &m);
        for (int i = 1; i <= m; i ++) {
            char t;
            char str[5];
            scanf ("%s", str);
            t = str[0];
            op[i] = getop(t);
            if (op[i] >= 1 && op[i] <= 3) scanf ("%d", &v[i]);
            else scanf ("%d%d", &u[i], &v[i]);
        }
        cnt = 1;
        dfs (1);
        int ans = INT_MAX;
        for (int i = 1; i < cnt; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (op[j] >= 1 && op[j] <= 3) {
                    x[v[j]][i] = op[j];
                } else {
                    if (op[j] == P) {
                        x[u[j]][i] = x[v[j]][i];
                    }
                    if (op[j] == M) {
                        x[u[j]][i] = x[v[j]][i] == T ? F : (x[v[j]][i] == U ? U : T);
                        // printf ("- %d = %d %d (%d)\n", u[j], v[j], x[u[j]][i], x[v[j]][i]);
                    }
                }
            }
            bool flag = true;
            int d = 0;
            for (int j = 1; j <= n; j ++) {
                if (x[j][i] == U) d ++;
                if (x[j][i] != y[j][i]) {
                    flag = false;
                }
            }
            if (flag) {
                ans = min (ans, d);
            }
        }
        printf ("%d\n", ans);
    }
}

namespace Sub34 {
    // TFU
    int x[maxn];
    const int T = 1, F = 2, U = 3;
    void sub34 () {
        memset(x, 0, sizeof(x));
        scanf ("%d%d", &n, &m);
        for (int i = 1; i <= m; i ++) {
            char t; int v;
            char str[5];
            scanf ("%s%d", str, &v);
            t = str[0];
            x[v] = t == 'T' ? T : (t == 'F' ? F : U);
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            if (x[i] == U) ans ++;
        }
        printf ("%d\n", ans);
    }
}

namespace Sub56 {
    int x[maxn];
    const int U = 0, P = 1;
    int getop (char t) {
        if (t == 'U') return U;
        if (t == '+') return P;
        return 0;
    }

    vector <int> l, index[maxn];
    void sub56 () {
        scanf ("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++) {
            x[i] = i;
            index[i].clear();
        }
        for (int i = 1; i <= m; i ++) {
            char t;
            char str[5];
            scanf ("%s", str);
            t = str[0];
            int u, v;
            if (getop(t) == U) {
                scanf ("%d", &v);
                x[v] = U;
            } else {
                scanf ("%d%d", &u, &v);
                x[u] = x[v];
            }
        }
        int ans = 0;
        l.clear();
        for (int i = 1; i <= n; i ++) {
            index[x[i]].push_back(i);
            if (x[i] == 0) {
                ans ++;
                l.push_back(i);
            }
        }
        for (int i = 0; i < l.size(); i ++) {
            if (l[i] > 0 && l[i] <= n)
            for (int j = 0; j < index[l[i]].size(); j ++) {
                ans ++;
                l.push_back(index[l[i]][j]);
            }
        }
        printf ("%d\n", ans);
    }
}

namespace Sub78 {
    // +-
    struct Edge {
        int v, w;
        Edge () {}
        Edge (int _v, int _w) {
            v = _v, w = _w;
        }
    };
    int x[maxn];
    vector<Edge>adj[maxn];
    int key[maxn];
    int flag[maxn];
    int vis[maxn];
    vector <int> l, index[maxn];

    void dfs (int u, int f) {
        flag[u] = flag[f];
        for (int i = 0; i < adj[u].size() && !flag[u]; i ++) {
            int v = adj[u][i].v;
            int w = adj[u][i].w;
            if (key[v] != 0 && key[u] * w != key[v]) {
                //conflict
                flag[u] = true;
                break;
            }
        }
        for (int i = 0; i < adj[u].size(); i ++) {
            int v = adj[u][i].v;
            int w = adj[u][i].w;
            if (key[v] == 0) {
                key[v] = key[u] * w;
                dfs (v, u);
                flag[u] = flag[v];
            }
        }
    }

    void sub78 () {
        memset(vis, 0, sizeof(vis));
        memset(key, 0, sizeof(key));
        memset(flag, 0, sizeof(flag));
        scanf ("%d%d", &n, &m);
        for (int i = 0; i <= n; i ++) {
            adj[i].clear();
            x[i] = i;
            index[i].clear();
        }
        for (int i = 1; i <= m; i ++) {
            char t; int u, v;
            char str[5];
            scanf ("%s%d%d", str, &u, &v);
            t = str[0];
            x[u] = t == '+' ? x[v] : -x[v];
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            // if (x[i] == i) continue;
            // if (x[i] == -i) {
            //     flag[i] = true;
            //     continue;
            // }
            int v = 0, f = 0;
            if (x[i] > 0) v = x[i], f = 1;
            if (x[i] < 0) v = -x[i], f = -1;
            // printf ("%d - %d, %d\n", i, v, f);
            adj[v].push_back(Edge(i, f));
            adj[i].push_back(Edge(v, f));
        }
        for (int i = 1; i <= n; i ++) {
            if (key[i] == 0) {
                key[i] = 1;
                dfs (i, 0);
            }
        }
        // for (int i = 1; i <= n; i ++) {
        //     if (flag[i]) ans ++;
        // }
        l.clear();
        for (int i = 1; i <= n; i ++) {
            if (x[i] < 0) x[i] = -x[i];
            index[x[i]].push_back(i);
            if (flag[i]) {
                ans ++;
                l.push_back(i);
                vis[i] = true;
            }
        }
        for (int i = 0; i < l.size(); i ++) {
            if (l[i] > 0 && l[i] <= n)
            for (int j = 0; j < index[l[i]].size(); j ++) {
                if (!vis[index[l[i]][j]]) {
                    ans ++;
                    l.push_back(index[l[i]][j]);
                    vis[index[l[i]][j]] = true;
                }
            }
        }
        printf ("%d\n", ans);
    }
}

int main () {
    freopen ("tribool.in", "r", stdin);
    freopen ("tribool.out", "w", stdout);
    scanf ("%d%d\n", &c, &t);
    if (c == 1 || c == 2) while (t --) Sub12::sub12();
    if (c == 3 || c == 4) while (t --) Sub34::sub34();
    if (c == 5 || c == 6) while (t --) Sub56::sub56();
    if (c == 7 || c == 8) while (t --) Sub78::sub78();
    return 0;
}