#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10, INF2 = 2e9;
typedef long long ll;
const ll INF = 1e16;
struct SegmentTree{
    int l, r;
    ll mx, add;
}tr[N << 3];

struct node{
    int L, R;
    ll v;
}a[N];

vector <node> G1[N * 2];

int b[N * 2], tot, n, m, k;
ll d, f[N * 2];

void pushup(int p)
{
    tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
}

void pushadd(int p, ll add)
{
    tr[p].add += add, tr[p].mx += add;
}

void pushdown(int p)
{
    if(tr[p].add)
    {
        pushadd(p << 1, tr[p].add), pushadd(p << 1 | 1, tr[p].add);
        tr[p].add = 0;
    }
}

void change(int p, int x, int y, ll add)
{
    if(x > y) return;
    if(x <= tr[p].l && tr[p].r <= y)
    {
        pushadd(p, add);
        return;
    }
    pushdown(p);
    int mid = tr[p].l + tr[p].r >> 1;
    if(x <= mid) change(p << 1, x, y, add);
    if(y > mid) change(p << 1 | 1, x, y, add);
    pushup(p);
}

ll query(int p, int x, int y)
{
    if(x > y) return -INF;
    if(x <= tr[p].l && tr[p].r <= y)
    {
        return tr[p].mx;
    }
    pushdown(p);
    int mid = tr[p].l + tr[p].r >> 1; ll res = -INF;
    if(x <= mid) res = max(res, query(p << 1, x, y));
    if(y > mid) res = max(res, query(p << 1 | 1, x, y));
    return res;
}

void build(int p, int l, int r)
{
    tr[p].l = l, tr[p].r = r, tr[p].add = tr[p].mx = 0ll;
    if(l == r) return;
    int mid = l + r >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}

ll read()
{
    ll x = 0, t = 1; char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') x = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10ll + ch - '0';
        ch = getchar();
    }
    return x * t;
}

int valb(int x)
{
    return lower_bound(b + 1, b + tot + 1, x) - b;
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int id = read(), T = read();
    while(T--)
    {
        tot = 0;
        n = read(), m = read(), k = read(), d = read();
        for(int i = 1; i <= m; i++)
        {
            a[i].R = read(), a[i].L = read(), a[i].v = read();
            a[i].L = a[i].R - a[i].L + 1;
            b[++tot] = a[i].L, b[++tot] = a[i].R + 1;
        }
        b[++tot] = 0, b[++tot] = INF2;
        sort(b + 1, b + tot + 1);
        tot = unique(b + 1, b + tot + 1) - b - 1;
        for(int i = 1; i <= tot; i++) G1[i].clear();
        for(int i = 1; i <= m; i++)
        {
            G1[valb(a[i].R + 1)].push_back(a[i]);
        }
        build(1, 1, tot);
        for(int i = 1; i <= tot; i++)
        {
            if(i > 2) change(1, 1, i - 2, -(ll)(b[i] - b[i - 1]) * d);
            for(auto& p : G1[i])
            {
                int L = p.L, R = p.R; ll v = p.v;
                change(1, 1, valb(L) - 1, v);
            }
            int l = 1, r = i;
            while(l < r)
            {
                int mid = l + r >> 1;
                if((b[i] - 1) - (b[mid]) + 1 > k) l = mid + 1;
                else r = mid;
            }
            if((b[i] - 1) - (b[l]) + 1 <= k) f[i] = query(1, l - 1, i - 1);
            else f[i] = -INF;
            if(i == 1) f[i] = 0;
            change(1, i, i, f[i]);
            //ans = max(ans, f[i]);
        }
        printf("%lld\n", f[tot]);
    }
}
