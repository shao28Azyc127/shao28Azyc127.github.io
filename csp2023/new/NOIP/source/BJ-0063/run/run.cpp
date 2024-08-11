#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 1e5 + 5;
int _, __, f[N], n, m, k, d;
vector<pair<int, int>> chas[N];
struct Segment {
    int l, r, mx, add;
} t[N << 2];
void build(int p, int l, int r) {
    t[p].l = l; t[p].r = r; t[p].mx = 0; t[p].add = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}
inline void upd(int p, int val) {
    t[p].mx += val;
    t[p].add += val;
}
inline void pushdown(int p) {
    if (t[p].add) {
        upd(p << 1, t[p].add);
        upd(p << 1 | 1, t[p].add);
        t[p].add = 0;
    }
}
inline void pushup(int p) {
    t[p].mx = max(t[p << 1].mx, t[p << 1 | 1].mx);
}
void modify(int p, int l, int r, int val) {
    if (l <= t[p].l && t[p].r <= r) { upd(p, val); return; }
    int mid = (t[p].l + t[p].r) >> 1; pushdown(p);
    if (l <= mid) modify(p << 1, l, r, val);
    if (mid < r) modify(p << 1 | 1, l, r, val);
    pushup(p);
}
int query(int p, int l, int r) {
    if (l <= t[p].l && t[p].r <= r) return t[p].mx;
    int mid = (t[p].l + t[p].r) >> 1, res = 0; pushdown(p);
    if (l <= mid) res = max(res, query(p << 1, l, r));
    if (mid < r) res = max(res, query(p << 1 | 1, l, r));
    return res;
}
signed main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    for (scanf("%lld%lld", &__, &_); _; --_) {
        scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
        rep(i, 1, n) chas[i].clear();
        rep(i, 1, m) {
            int x, y, v;
            scanf("%lld%lld%lld", &x, &y, &v);
            chas[x].emplace_back(y, v);
        }
        f[0] = 0;
        build(1, 0, n);
        rep(i, 1, n) {
            f[i] = f[i - 1];
            modify(1, i, i, f[i - 1]);
            // i - 1, i - k
            int tl = max(i - k, 0ll);
            modify(1, 0, i - 1, -d);
            for (auto &[len, val]: chas[i]) {
                modify(1, 0, i - len, val);
            }
            f[i] = max(query(1, tl, i - 1), f[i]);
        }
        printf("%lld\n", f[n]);
    }
    return 0;
}