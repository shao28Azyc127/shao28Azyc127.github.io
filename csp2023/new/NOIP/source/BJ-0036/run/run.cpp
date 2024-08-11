#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int N = 2e5 + 5, M = 4e5 + 5;
inline void read(int &x) {
    x = 0; int f = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f *= -1;
    for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
    x *= f;
}
template <typename T> inline T& Min(T &x, T y) { if (x > y) x = y; return x; }
template <typename T> inline T& Max(T &x, T y) { if (x < y) x = y; return x; }

struct chal {
    int l, r, v;
} p[N];
namespace Bf {
    LL tre[N << 2], tag[N << 2];
    #define ls(x) (x << 1)
    #define rs(x) (x << 1 | 1)
    inline void pushup(int p) {
        tre[p] = max(tre[ls(p)], tre[rs(p)]);
    }
    void build(int p, int l, int r) {
        if (l == r) {
            tre[p] = tag[p] = 0; return;
        }
        int mid = (l + r) >> 1;
        build(ls(p), l, mid); build(rs(p), mid + 1, r);
        tre[p] = tag[p] = 0;
        pushup(p);
    }
    inline void pushdown(int p) {
        tre[ls(p)] += tag[p]; tre[rs(p)] += tag[p];
        tag[ls(p)] += tag[p]; tag[rs(p)] += tag[p];
        tag[p] = 0;
    }
    void upd(int p, int uL, int uR, int l, int r, LL v) {
        if (uL <= l && r <= uR) {
            tre[p] += v; tag[p] += v; return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if (uL <= mid) upd(ls(p), uL, uR, l, mid, v);
        if (mid < uR) upd(rs(p), uL, uR, mid + 1, r, v);
        pushup(p);
    }
    LL query(int p, int qL, int qR, int l, int r) {
        if (qL <= l && r <= qR) return tre[p];
        pushdown(p);
        int mid = (l + r) >> 1; LL ret = -(LLONG_MAX >> 1);
        if (qL <= mid) Max(ret, query(ls(p), qL, qR, l, mid));
        if (mid < qR) Max(ret, query(rs(p), qL, qR, mid + 1, r));
        return ret;
    }
    LL f[N], sf[N];
    vector <pii> G[N];
    void Main(int n, int m, int k, int d) {
        build(1, 1, n);
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i <= m; i++) G[p[i].r].emplace_back(p[i].l, p[i].v);
        for (int i = 1; i <= n; i++) {
            upd(1, 1, i, 1, n, -d);
            for (auto v : G[i]) {
                int l = v.first;
                upd(1, 1, l, 1, n, v.second);
            }
            f[i] = query(1, max(1, i - k + 1), i, 1, n);
            sf[i] = max(sf[i - 1], f[i]);
            if (i + 2 <= n) upd(1, i + 2, i + 2, 1, n, sf[i]);
        }
        cout << sf[n] << '\n';
    }
}
namespace std {
    LL tre[M << 2], tag[M << 2];
    #define ls(x) (x << 1)
    #define rs(x) (x << 1 | 1)
    inline void pushup(int p) {
        tre[p] = max(tre[ls(p)], tre[rs(p)]);
    }
    void build(int p, int l, int r) {
        if (l == r) {
            tre[p] = tag[p] = 0; return;
        }
        int mid = (l + r) >> 1;
        build(ls(p), l, mid); build(rs(p), mid + 1, r);
        tre[p] = tag[p] = 0;
        pushup(p);
    }
    inline void pushdown(int p) {
        tre[ls(p)] += tag[p]; tre[rs(p)] += tag[p];
        tag[ls(p)] += tag[p]; tag[rs(p)] += tag[p];
        tag[p] = 0;
    }
    void updset(int p, int uX, int l, int r, LL v) {
        if (l == r) {
            Max(tre[p], v); return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if (uX <= mid) updset(ls(p), uX, l, mid, v);
        else updset(rs(p), uX, mid + 1, r, v);
        pushup(p);
    }
    void upd(int p, int uL, int uR, int l, int r, LL v) {
        if (uL <= l && r <= uR) {
            tre[p] += v; tag[p] += v; return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if (uL <= mid) upd(ls(p), uL, uR, l, mid, v);
        if (mid < uR) upd(rs(p), uL, uR, mid + 1, r, v);
        pushup(p);
    }
    LL query(int p, int qL, int qR, int l, int r) {
        if (qL <= l && r <= qR) return tre[p];
        pushdown(p);
        int mid = (l + r) >> 1; LL ret = -(LLONG_MAX >> 1);
        if (qL <= mid) Max(ret, query(ls(p), qL, qR, l, mid));
        if (mid < qR) Max(ret, query(rs(p), qL, qR, mid + 1, r));
        return ret;
    }
    LL f[M], sf[M];
    vector <pii> G[M];
    int B[M], btot;
    inline void Main(int n, int m, int k, int d) {
        btot = 0;
        for (int i = 1; i <= m; i++) {
            B[++btot] = p[i].l, B[++btot] = p[i].r;
            // if (p[i].l > 1) B[++btot] = p[i].l - 1;
            if (p[i].l > 2) B[++btot] = p[i].l - 2;
        }
        sort(B + 1, B + btot + 1);
        btot = unique(B + 1, B + btot + 1) - B - 1;
        for (int i = 1; i <= m; i++) {
            p[i].l = lower_bound(B + 1, B + btot + 1, p[i].l) - B;
            p[i].r = lower_bound(B + 1, B + btot + 1, p[i].r) - B;
        }
        for (int i = 1; i <= btot; i++) G[i].clear();
        for (int i = 1; i <= m; i++) {
            G[p[i].r].emplace_back(p[i].l, p[i].v);
        }
        build(1, 1, btot);
        int tpos = 1;
        for (int i = 1; i <= btot; i++) {
            if (i > 1) upd(1, 1, i - 1, 1, btot, -(LL)d * (B[i] - B[i - 1]));
            upd(1, i, i, 1, btot, -d);
            for (auto v : G[i]) {
                int l = v.first;
                upd(1, 1, l, 1, btot, v.second);
            }
            while (tpos < i && B[i] - B[tpos] + 1 > k) tpos++;
            f[i] = query(1, tpos, i, 1, btot);
            sf[i] = max(sf[i - 1], f[i]);
            if (i < btot && B[i + 1] > B[i] + 1) updset(1, i + 1, 1, btot, sf[i]);
            else if (i < btot - 1 && B[i + 2] > B[i] + 1) updset(1, i + 2, 1, btot, sf[i]);
            // if (i + 2 <= btot) updset(1, i + 2, 1, btot, sf[i]);
        }
        cout << sf[btot] << '\n';
    }
}
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Case, T; cin >> Case >> T;
    for (int n, m, k, d; T--; ) {
        cin >> n >> m >> k >> d;
        for (int x, y, v, i = 1; i <= m; i++) {
            cin >> x >> y >> v;
            p[i] = {x - y + 1, x, v};
        }
        // if (n <= 100000) Bf::Main(n, m, k, d);
        // else
        std::Main(n, m, k, d);
    }
    return 0;
}