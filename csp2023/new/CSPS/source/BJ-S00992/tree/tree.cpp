#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
const LL lim = 1000000000000000000ll;
LL A[N];
int b[N], c[N], ned[N];
vector <int> G[N];
inline LL Glen(int id, int r) {
    if (c[id] > 0) {
        if (((LL)r * (r + 1) >> 1) > lim / c[id]) return lim;
        return min(lim, (LL)b[id] * r + ((LL)r * (r + 1) >> 1) * c[id]);
    } else if (c[id] == 0) return min(lim, (LL)b[id] * r);
    int mpoint = (b[id] - 1) / (-c[id]) + 1;
    if (r < mpoint) {
        return min(lim, (LL)b[id] * r + ((LL)r * (r + 1) >> 1) * c[id]);
    } else if (mpoint == 1) {
        return r;
    } else {
        // assert((LL)b[id] * (mpoint - 1) + ((LL)mpoint * (mpoint - 1) >> 1) * c[id] <= lim);
        return min(lim, (LL)b[id] * (mpoint - 1) + ((LL)mpoint * (mpoint - 1) >> 1) * c[id] + (r - mpoint + 1));
    }
}
inline LL Getlen(int id, int l, int r) {
    // assert(l > 0);
    return l == 1 ? Glen(id, r) : (Glen(id, r) - Glen(id, l - 1));
}
void dfs1(int u, int Fa) {
    for (auto v : G[u]) if (v != Fa) {
        dfs1(v, u); ned[u] = min(ned[u], ned[v] - 1);
    }
}
int buc[N];
inline bool check(int v, int n) {
    for (int i = 1; i <= n; i++) {
        int l = 1, r = v;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (Getlen(i, mid, v) < A[i]) r = mid - 1;
            else l = mid + 1;
        }
        if (r == 0) return 0;
        ned[i] = r;
    }
    dfs1(1, 0);
    memset(buc, 0, sizeof buc);
    for (int i = 1; i <= n; i++) {
        if (ned[i] <= 0) return 0;
        if (ned[i] <= n) buc[ned[i]]++;
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) while (buc[i]--) ned[++tot] = i;
    for (int i = 1; i <= tot; i++) if (ned[i] < i) return 0;
    // sort(ned + 1, ned + n + 1);
    // for (int i = 1; i <= n; i++) if (ned[i] < i) return 0;
    return 1;
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld%d%d", A + i, b + i, c + i);
    for (int u, v, i = 1; i < n; i++) scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u);
    // for (int i = 1; i <= n; i++) assert(Glen(i, 1000000000) >= A[i]);
    int l = 1, r = 1000000000;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, n)) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", l);
    // cerr << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}