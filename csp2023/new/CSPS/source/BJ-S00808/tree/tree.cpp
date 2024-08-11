#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const ll inf = 2e18;

struct edge
{
    int v, next;
}e[maxn << 1];
int head[maxn], tot;
bool fl1 = true, fl2 = true;

inline void addedge(int u, int v)
{
    e[++tot] = (edge){v, head[u]};
    head[u] = tot;
}

int n, mxp[maxn];
ll a[maxn], b[maxn], c[maxn];

ll chk2(ll mid, int i, ll x)
{
    if (c[i] > 0)
    {
        ll nw = b[i] * (x - mid + 1);
        ll tmp = c[i] * (x - mid + 1);
        if (tmp > 2 * inf / (x + mid)) return inf;
        return min(inf, max(-inf, nw + tmp * (x + mid) / 2));
    }
    return 0;
}

bool chk(int x)
{
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = x, pos = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (chk2(mid, i, x) >= a[i]) pos = mid, l = mid + 1;
            else r = mid - 1;
            
        }
        if (!pos) return false;
        mxp[i] = pos;
    }

    if (fl1)
    {
        sort(mxp + 2, mxp + n + 1);
        for (int i = 2; i <= n; i++)
            if (mxp[i] > i) return false;
        return true;
    }
    if (fl2)
    {
        for (int i = 2; i <= n; i++)
            if (mxp[i] > i) return false;
        return true;
    }
    return false;
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u != 1) fl1 = false;
        if (u != i || v != i + 1) fl2 = false;
        addedge(u, v);
        addedge(v, u);
    }

    int l = n, r = 1000000000, pos = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (chk(mid)) pos = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << pos;
    return 0;
}