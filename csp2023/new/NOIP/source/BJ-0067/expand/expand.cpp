//转朱阁，低绮户，照无眠。不应有恨，何事长向别时圆？
#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;

int n, m, a[maxn], b[maxn], px[maxn], py[maxn], dp[maxn];

struct segtree
{
    int mxd[maxn << 2], mnd[maxn << 2];

    void build(int k, int l, int r)
    {
        if (l == r)
        {
            mxd[k] = mnd[k] = b[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(k << 1, l, mid);
        build(k << 1 | 1, mid + 1, r);
        mxd[k] = max(mxd[k << 1], mxd[k << 1 | 1]);
        mnd[k] = min(mnd[k << 1], mnd[k << 1 | 1]);
    }

    int queryleft(int k, int x, int d, bool op, int l, int r)
    {
        if ((op && mnd[k] >= d) || (!op && mxd[k] <= d)) return 0;
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (x <= mid) return queryleft(k << 1, x, d, op, l, mid);
        else
        {
            int res = queryleft(k << 1 | 1, x, d, op, mid + 1, r);
            if (!res) return queryleft(k << 1, x, d, op, l, mid);
            else return res;
        }
    }

    int queryright(int k, int x, int d, bool op, int l, int r)
    {
        if ((op && mxd[k] < d) || (!op && mnd[k] > d)) return m + 1;
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (x > mid) return queryright(k << 1 | 1, x, d, op, mid + 1, r);
        else
        {
            int res = queryright(k << 1, x, d, op, l, mid);
            if (res == m + 1) return queryright(k << 1 | 1, x, d, op, mid + 1, r);
            else return res;
        }
    }
}T;

bool Solve()
{
    if (a[1] == b[1] || a[n] == b[m]) return false;
    if (a[1] > b[1] && a[n] < b[m]) return false;
    if (a[1] < b[1] && a[n] > b[m]) return false;
    T.build(1, 1, m);

    int nw = 0;
    if (a[1] > b[1])
    {
        b[m + 1] = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > b[nw + 1]) nw = T.queryright(1, nw + 1, a[i], 1, 1, m) - 1;
            else
            {
                int x = T.queryleft(1, nw, a[i], 1, 1, m);
                if (!x) return false;
                nw = x;
            }
        }
        return nw == m;
    }
    else
    {
        b[m + 1] = -1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < b[nw + 1]) nw = T.queryright(1, nw + 1, a[i], 0, 1, m) - 1;
            else
            {
                int x = T.queryleft(1, nw, a[i], 0, 1, m);
                if (!x) return false;
                nw = x;
            }
        }
        return nw == m;
    }
}

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int sid, q;
    cin >> sid >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> px[i], a[i] = px[i];
    for (int i = 1; i <= m; i++) cin >> py[i], b[i] = py[i];
    cout << Solve();
    for (int Q = 1; Q <= q; Q++)
    {
        int kx, ky;
        cin >> kx >> ky;
        for (int i = 1; i <= n; i++) a[i] = px[i];
        for (int i = 1; i <= m; i++) b[i] = py[i];
        for (int i = 1; i <= kx; i++)
        {
            int px, vx;
            cin >> px >> vx;
            a[px] = vx;
        }
        for (int i = 1; i <= ky; i++)
        {
            int py, vy;
            cin >> py >> vy;
            b[py] = vy;
        }
        cout << Solve();
    }
    cout << "\n";
    return 0;
}