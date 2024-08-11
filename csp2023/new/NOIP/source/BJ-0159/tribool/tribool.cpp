#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
struct node {
    int tp, val, iv;
    node(int aa = 0, int bb = 0, int cc = 0) : tp(aa), val(bb), iv(cc) {}
    // tp = 0: a[i] = a[val]
    //     iv = 1: a[i] = !a[val]
    // tp = 1: a[i] = val
    //     val: 1->T, 0->F, -1->U
} a[N];
node inv(node x) {
    if (!x.tp) return node(0, x.val, x.iv ^ 1);
    else if (x.val >= 0) return node(1, x.val ^ 1, 0);
    else return node(1, -1, 0);
}
struct edge {
    int v, w;
};
vector<edge> G[N];
int c, t, n, m;
int mp_bl[129];
struct DSU {
    int fa[N], siz[N];
    void init() {
        for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
    }
    int get(int x) {
        while (x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    void merge(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return;
        if (siz[x] > siz[y]) swap(x, y);
        fa[x] = y, siz[y] += siz[x];
    }
} T;
int ok, val[N], vis[N];
void dfs(int u, int vl) {
    if (!ok) return;
    if (val[u] >= 0) {
        if (val[u] != vl) ok = 0;
        return;
    }
    val[u] = vl;
    for (auto e : G[u]) {
        dfs(e.v, vl ^ e.w);
    }
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    mp_bl['T'] = 1, mp_bl['F'] = 0, mp_bl['U'] = -1;
    scanf("%d%d", &c, &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            a[i] = node(0, i, 0);
            G[i].clear(), val[i] = -114514, vis[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            char op; int x, y;
            scanf(" %c", &op);
            switch (op) {
                case '+':
                    scanf("%d%d", &x, &y);
                    a[x] = a[y]; break;
                case '-':
                    scanf("%d%d", &x, &y);
                    a[x] = inv(a[y]); break;
                default:
                    scanf("%d", &x);
                    a[x] = node(1, mp_bl[op], 0);
            }
        }
        //for (int i = 1; i <= n; i++) cout << a[i].tp << ' ' << a[i].val << ' ' << a[i].iv << endl;
        T.init();
        for (int i = 1; i <= n; i++) {
            if (a[i].tp) val[i] = a[i].val;
            else {
                G[a[i].val].push_back({i, a[i].iv});
                G[i].push_back({a[i].val, a[i].iv});
                T.merge(i, a[i].val);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i].tp && a[i].val < 0 && !vis[T.get(i)]) {
                ans += T.siz[T.get(i)];
                vis[T.get(i)] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i].tp && a[i].val >= 0 && !vis[T.get(i)]) {
                ok = 1; dfs(i, a[i].val);
                vis[T.get(i)] = 1;
                if (!ok) ans += T.siz[T.get(i)];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!a[i].tp && !vis[T.get(i)]) {
                ok = 1; dfs(i, 0);
                vis[T.get(i)] = 1;
                if (!ok) ans += T.siz[T.get(i)];
            }
        }
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
Ranger_HoFr(CW) AK IOI!
Imiya(Ocean) AK IOI!
zyctc AK IOI!
TonyYin AK IOI!
They can help me to be unable to guafen!
PLEASE!!! DONT GUAFEN!!!
*/
