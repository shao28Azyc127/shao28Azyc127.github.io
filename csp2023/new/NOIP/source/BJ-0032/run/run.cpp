#include <iostream>
#include <algorithm>

typedef long long ll;
typedef double lf;

namespace FastIO
{
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc() (p1 == p2 && ((p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin)), p1 == p2) ? EOF : *p1++)
    template <typename T>
    inline void Read(T &x)
    {
        x = 0; bool sgn = 0; char ch = gc();
        while (ch < '0' || ch > '9') {if (ch == '-') sgn = 1; ch = gc();}
        while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
        if (sgn) x = -x;
    }
}

using FastIO::Read;
using namespace std;

const int MAXN = 1e5 + 10, MAXM = 2e5 + 10;

int n, m, K; ll d;

struct Data
{
    int l, r, w;
    bool operator < (const Data u) const {return r < u.r;}
}a[MAXN];
int b[MAXM], tot;

ll f[MAXM][2];

struct Node
{
    ll sum, lz;
}tr[MAXM << 2];
inline void Pushup(int cur) {tr[cur].sum = max(tr[cur << 1].sum, tr[cur << 1 | 1].sum);}
inline void Calc(int cur, ll k) {tr[cur].sum += k, tr[cur].lz += k;}
inline void Pushdown(int cur) {Calc(cur << 1, tr[cur].lz), Calc(cur << 1 | 1, tr[cur].lz), tr[cur].lz = 0;}
inline void Build(int cur, int l, int r)
{
    tr[cur].sum = tr[cur].lz = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    Build(cur << 1, l, mid), Build(cur << 1 | 1, mid + 1, r);
}
inline void Update(int cur, int l, int r, int x, int y, ll k)
{
    if (x <= l && r <= y) Calc(cur, k);
    else
    {
        Pushdown(cur);
        int mid = l + r >> 1;
        if (x <= mid) Update(cur << 1, l, mid, x, y, k);
        if (y > mid) Update(cur << 1 | 1, mid + 1, r, x, y, k);
        Pushup(cur);
    }
}
inline ll Query(int cur, int l, int r, int x, int y)
{
    if (x <= l && r <= y) return tr[cur].sum;
    Pushdown(cur);
    int mid = l + r >> 1; ll res = -1e18;
    if (x <= mid) res = max(res, Query(cur << 1, l, mid, x, y));
    if (y > mid) res = max(res, Query(cur << 1 | 1, mid + 1, r, x, y));
    return res;
}

inline void Solve()
{
    Read(n), Read(m), Read(K), Read(d);
    tot = 0;
    for (int i = 1, x, y; i <= m; i++)
    {
        Read(x), Read(y), Read(a[i].w);
        a[i].l = x - y + 1, a[i].r = x;
        b[++tot] = x - y, b[++tot] = x;
    }
    b[++tot] = 0;
    sort(b + 1, b + tot + 1);
    tot = unique(b + 1, b + tot + 1) - b - 1;
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++)
    {
        a[i].l = lower_bound(b + 1, b + tot + 1, a[i].l - 1) - b;
    }
    int wp = 1, tp = 1;
    f[1][0] = f[1][1] = 0;
    Build(1, 1, tot);
    for (int i = 2; i <= tot; i++)
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        while (wp <= m && a[wp].r <= b[i]) Update(1, 1, tot, 1, a[wp].l, a[wp].w), wp++;
        while (tp < i && b[i] - b[tp] > K) tp++;
        f[i][1] = (tp >= i ? 0 : Query(1, 1, tot, tp, i - 1) - d * b[i]);
        Update(1, 1, tot, i, i, f[i][0] + d * b[i]);
    }
    cout << max(f[tot][0], f[tot][1]) << "\n";
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int CASE, T;
    Read(CASE), Read(T);
    while (T--) Solve();
    return 0;
}