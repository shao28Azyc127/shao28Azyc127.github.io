//人有悲欢离合，月有阴晴圆缺，此事古难全。但愿人长久，千里共婵娟。
#include <bits/stdc++.h>
using namespace std;

char *p1, *p2, buf[1048577];
#define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)
template<typename T>

inline void Read(T &x)
{
    x = 0;
    char ch = gc;
    while (!isdigit(ch)) ch = gc;
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc;
}

typedef long long ll;
const int maxn = 4e5 + 5;
const ll inf = 1e18 + 7;

int n, m, k;
int l[maxn], r[maxn], b[maxn], pos[maxn], rk[maxn], len[maxn];
ll val[maxn], pre[maxn], d;
vector<int> v[maxn];

struct segtree
{
    ll mxd[maxn << 2], tag[maxn << 2];

    void pushdown(int k)
    {
        if (tag[k])
        {
            mxd[k << 1] += tag[k];
            mxd[k << 1 | 1] += tag[k];
            tag[k << 1] += tag[k];
            tag[k << 1 | 1] += tag[k];
            tag[k] = 0;
        }
    }

    void update(int k, int l, int r, int L, int R, ll d)
    {
        if (l <= L && R <= r)
        {
            tag[k] += d;
            mxd[k] += d;
            return;
        }
        pushdown(k);
        int mid = (L + R) >> 1;
        if (l <= mid) update(k << 1, l, r, L, mid, d);
        if (r > mid) update(k << 1 | 1, l, r, mid + 1, R, d);
        mxd[k] = max(mxd[k << 1], mxd[k << 1 | 1]);
    }

    void change(int k, int L, int R, int x, ll d)
    {
        if (L == R)
        {
            mxd[k] = d;
            return;
        }
        pushdown(k);
        int mid = (L + R) >> 1;
        if (x <= mid) change(k << 1, L, mid, x, d);
        else change(k << 1 | 1, mid + 1, R, x, d);
        mxd[k] = max(mxd[k << 1], mxd[k << 1 | 1]);
    }

    ll query(int k, int l, int r, int L, int R)
    {
        if (l <= L && R <= r) return mxd[k];
        pushdown(k);
        int mid = (L + R) >> 1;
        ll ans = -inf;
        if (l <= mid) ans = max(ans, query(k << 1, l, r, L, mid));
        if (r > mid) ans = max(ans, query(k << 1 | 1, l, r, mid + 1, R));
        return ans;
    }
}T;

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int sid, TQ;
    Read(sid), Read(TQ);
    while (TQ--)
    {
        Read(n); Read(m); Read(k); Read(d);
        int sz = 0;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            Read(x); Read(y); Read(val[i]);
            l[i] = x - y + 1, r[i] = x;
            b[++sz] = l[i], b[++sz] = r[i];
        }
        b[++sz] = n;
        sort(b + 1, b + sz + 1);
        sz = unique(b + 1, b + sz + 1) - b - 1;
        n = 0;
        if (b[1] != 1) len[++n] = b[1] - 1;
        for (int i = 1; i < sz; i++)
        {
            len[++n] = b[i], rk[i] = n;
            if (b[i] < b[i + 1] - 1) len[++n] = b[i + 1] - 1;
        }
        len[++n] = b[sz], rk[sz] = n;

        for (int i = 1; i <= n * 4; i++) T.mxd[i] = T.tag[i] = 0;
        for (int i = 1; i <= n; i++) v[i].clear();
        for (int i = 1; i <= m; i++)
        {
            l[i] = rk[lower_bound(b + 1, b + sz + 1, l[i]) - b];
            r[i] = rk[lower_bound(b + 1, b + sz + 1, r[i]) - b];
            v[r[i]].emplace_back(i);
        }

        for (int i = 1, j = 1; i <= n; i++)
        {
            while (len[i] - len[j - 1] > k) j++;
            pos[i] = max(1, j);
        }
        
        pre[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1];
            if (pos[i] > i) continue;
            T.change(1, 1, n, i, (i >= 2 ? pre[i - 2] : 0) + d * len[i - 1]);
            for (int x : v[i]) T.update(1, 1, l[x], 1, n, val[x]);
            pre[i] = max(pre[i], T.query(1, pos[i], i, 1, n) - d * len[i]);
        }
        cout << pre[n] << "\n";
    }
    return 0;
}