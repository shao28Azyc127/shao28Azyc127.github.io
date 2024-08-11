#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 1e5 + 5;

int sid, T, n, m, col[NR];
vector < int > v[NR];
vector < pair < int, int > > e[NR];

struct Node {
    int tp, id;
} a[NR];

struct dsu {
    int father[NR], sz[NR];
    inline void init() {
        for (int i = 1; i <= n; ++i) father[i] = i, sz[i] = 1;
    }
    inline int find(int x) {
        if (father[x] == x) return x;
        return father[x] = find(father[x]);
    }
    inline void merge(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        sz[ry] += sz[rx], father[rx] = ry;
    }
} d;

inline bool dfs(int x, int y) {
    if (col[x]) return !(col[x] == y);
    col[x] = y; bool flg = 0;
    for (auto it : e[x]) {
        int v = it.first, w = it.second;
        if (w == 2) flg |= dfs(v, y);
        else flg |= dfs(v, 3 - y);
    }
    return flg;
}

inline void solve() {
    cin >> n >> m, d.init();
    for (int i = 1; i <= n; ++i) a[i].tp = 2, a[i].id = i, col[i] = 0, v[i].clear(), e[i].clear();
    while (m --) {
        char op; int x, y; cin >> op;
        if (op == '+') cin >> x >> y, a[x] = a[y];
        else if (op == '-') {
            cin >> x >> y;
            if (a[y].tp == 1) {
                a[x].tp = 1;
                if (a[y].id == 3) a[x].id = 3;
                else a[x].id = 3 - a[y].id;
            }
            else {
                a[x].tp = 5 - a[y].tp;
                a[x].id = a[y].id;
            }
        }
        else {
            cin >> x, a[x].tp = 1;
            if (op == 'T') a[x].id = 1;
            if (op == 'F') a[x].id = 2;
            if (op == 'U') a[x].id = 3;
        }
    }
    for (int i = 1; i <= n; ++i) 
        if (a[i].tp != 1) d.merge(i, a[i].id);
    int ans = 0;
    for (int i = 1; i <= n; ++i) v[d.find(i)].push_back(i);
    for (int i = 1; i <= n; ++i) {
        if (v[i].size() == 0) continue;
        bool flg = 0;
        for (auto j : v[i])
            if (a[j].tp == 1 && a[j].id == 3) flg = 1;
        if (flg) {
            ans += d.sz[i];
            continue;
        }
        int p = 0, q;
        for (auto j : v[i]) {
            if (a[j].tp == 1) p = j, q = a[j].id;
            else e[j].push_back(make_pair(a[j].id, a[j].tp));
        }
        if (!p) p = v[i][0], q = 1;
        if (dfs(p, q)) ans += d.sz[i];
    }
    cout << ans << '\n';
}

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0);
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> sid >> T;
    while (T --) solve();
    return 0;
}