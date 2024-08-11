#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
const int M = 3000017;
int c, t, n, m, ans, val[maxn];
int fa[maxn], sz[maxn], vis[maxn], vis2[maxn]; // vis2: dfn
int id[maxn], tot; // Á¬Í¨¿é±àºÅ
bool isU[maxn];
queue<int> q;
vector<int> b[30];
vector<pair<int,bool> > e[maxn];
struct Node {
    ll data;
    int p, nxt;
} node[maxn];
int cnt, head[M];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    fa[x] = y, sz[y] += sz[x];
}
inline int f(int x) {
    if (x == n+1) return n+2;
    if (x == n+2) return n+1;
    if (x == n+3) return n+3;
    return 0;
}
inline void setU(int st) {
    while (q.size()) q.pop();
    q.push(st); vis[st] = 1; isU[st] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i].first;
            if (!vis[v]) {
                isU[v] = vis[v] = 1;
                q.push(v);
            }
        }
    }
}
inline bool FindLoop(int u, int id) {
    if (vis2[u] && (id - vis2[u] & 1)) return 1;
    vis2[u] = id;
    int ret = 0;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i].first, used = e[u][i].second;
        if (!used) {
            e[u][i].second = 1;
            if (FindLoop(v, id+1)) return 1;
        }
    }
    return 0;
}
inline void differ(int st, int t) {
    while (q.size()) q.pop();
    q.push(st); id[st] = t;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i].first;
            if (!id[v]) {
                id[v] = t; q.push(v);
            }
        }
    }
}
inline ll encode(int x, int y) {
    return x + y * (tot+1);
}
inline void insert(int x) {
    ll t = encode(id[x], find(x));
    int u = t % M;
    node[++cnt] = {t, x, head[u]};
    head[u] = cnt;
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> c >> t;
    while (t--) {
        cin >> n >> m;
        tot = cnt = ans = 0;
        for (int i = 1; i <= n; i++) val[i] = i, e[i].clear(), id[i] = vis2[i] = vis[i] = isU[i] = 0;
        for (int i = 0; i < M; i++) head[i] = 0;
        for (int i = 1; i <= m; i++) {
            char op; cin >> op;
            int x, y; cin >> x;
            if (op == '+') {
                cin >> y;
                val[x] = val[y];
            } else if (op == '-') {
                cin >> y;
                val[x] = (val[y] > n ? f(val[y]) : -val[y]);
            } else if (op == 'T') {
                val[x] = n+1;
            } else if (op == 'F') {
                val[x] = n+2;
            } else if (op == 'U') {
                val[x] = n+3;
            }
        }

        for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;

        for (int i = 1; i <= n; i++) {
            if (-n <= val[i] && val[i] <= -1) {
                e[i].push_back({-val[i], 0});
                e[-val[i]].push_back({i, 0});
            } else if (1 <= val[i] && val[i] <= n) {
                merge(i, val[i]);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (val[i] == n+3) {
                isU[i] = 1;
                isU[find(i)] = 1;
                if (!vis[i]) setU(i);
            }
        }

        for (int i = 1; i <= n; i++) if (val[i] <= n && !vis2[i]) {
            bool t = FindLoop(i, 1);
            if (t) setU(i);
        }


        // for (int i = 1; i <= n; i++) {
        // printf("%d ", isU[i]);
        // }
        // putchar('\n');

        for (int i = 1; i <= n; i++) if (!id[i]) differ(i, ++tot);
        for (int i = 1; i <= n; i++) insert(i);
        for (int i = 0; i < M; i++) if (node[head[i]].nxt != 0) {
            for (int j = 0; j < 30; j++) b[j].clear();
            for (int j = head[i]; j; j = node[j].nxt) {
                int tmp = node[i].data / M;
                b[tmp].push_back(node[j].p);
            }
            for (int j = 0; j < 30; j++) if (b[j].size() >= 2) {
                int u = b[j][0];
                setU(u);
                isU[find(u)] = 1;
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     printf("%d ", isU[i]);
        // }
        // putchar('\n');

        for (int i = 1; i <= n; i++) if (isU[i]) isU[find(i)] = 1;
        for (int i = 1; i <= n; i++) if (isU[find(i)]) isU[i] = 1;
        for (int i = 1; i <= n; i++) if (isU[i]) ans++;
        printf("%d\n", ans);
        // for (int i = 1; i <= n; i++) {
        //     printf("%d ", id[i]);
        // }
        // putchar('\n');
    }
    return 0;
}
