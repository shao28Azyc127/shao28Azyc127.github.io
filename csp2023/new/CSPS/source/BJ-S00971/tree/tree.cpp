#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
#define Cl(x, y) ((x) / (y) + !!((x) % (y)))
ll a[N], b[N], c[N];
ll F(int i, int t) {
    ll C = 2 * b[i] * t + t * (t + 1) * c[i] - 2 * a[i];//-C actually
    ll B = 2 * b[i] + c[i], A = c[i], D = B * B + 4 * A * C;
    if (D < 0) return -1; ll x = sqrt(D) / (2 * A);
    return x;
}
int nxt[N<<1], to[N<<1], hd[N], tot;
void addedge(int u, int v) { nxt[++tot] = hd[u]; to[tot] = v; hd[u] = tot; }
ll dep[N], wid[N], fw[N], md;
vector<int> vv[N];
void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1; wid[dep[u]]++; if (dep[u] > md) md = dep[u];
    vv[dep[u]].push_back(u);
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = to[i]; if (v == fa) continue;
        dfs(v, u);
    }
}
ll f[N], g[N]; int n;
int check(int t) {
    for (int i = 1; i <= n; i++) {
        f[i] = F(i, t);
        if (f[i] < 0) return 0;
        if (f[i] > dep[i]) return 0;
    }
    for (int i = 1; i <= md; i++) {
        sort(vv[i].begin(), vv[i].end(), [](int a, int b) { return f[a] < f[b]; });
        int c = 1;
        for (int j : vv[i]) {
            if (f[j] < fw[i-1] + c) return 0;
            c++;
        }
    }
    return 1;
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", a + i, b + i, c + i);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        addedge(u, v); addedge(v, u);
    }
    dfs(1, 0);
    for (int i = 1; i <= md; i++) {
        fw[i] = fw[i-1] + wid[i];
    }
    int l = n, r = 1e9 + 5;
    while (l <= r) {
        int mid = l + r >> 1;
        if (!check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", l + 1);
    return 0;
}