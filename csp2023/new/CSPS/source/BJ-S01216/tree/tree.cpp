#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[100010], b[100010], c[100010];
vector<int> v[100010];
int dep[100010], log_2[100010], f[100010][20];
void dfs(int x, int fa)
{
    dep[x] = dep[fa] + 1, f[x][0] = fa;
    for (auto i : v[x])
    {
        if (i == fa) continue;
        dfs(i, x);
    }
}
int t[100010], id[100010];
bool vis[100010];
int my_ceil(int x, int y)
{
    return (x + y - 1) / y;
}
int get(int x, int y)
{
    if (c[x] == 0) return y - my_ceil(a[x], max(b[x], 1ll)) + 1;
    if (c[x] > 0)
    {
        int tim = (b[x] >= 1 ? 1 : my_ceil(1 - b[x], c[x]));
        int h = b[x];
        int l = min(y + 1, tim), r = y, ans;
        __int128 kkk = (l + r) * (r - l + 1) / 2;
        kkk *= c[x];
        kkk += h * (r - l + 1);
        if (kkk < a[x]) return l - (a[x] - kkk);
        int R = r;
        while (l <= r)
        {
            int mid = l + r >> 1;
            kkk = (mid + R) * (R - mid + 1) / 2;
            kkk *= c[x];
            kkk += h * (R - mid + 1);
            if (kkk >= a[x]) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
    if (c[x] < 0)
    {
        int tim = (b[x] <= 1 ? 1 : my_ceil(b[x] - 1, -c[x]));
        int h = b[x];
        int l = 1, r = min(tim - 1, y), ans = 0;
        if ((y - r) >= a[x]) return y - a[x] + 1;
        int R = r;
        while (l <= r)
        {
            int mid = l + r >> 1;
            __int128 kkk = (mid + R) * (R - mid + 1) / 2;
            kkk *= c[x];
            kkk += h * (R - mid + 1);
            kkk += y - r;
            if (kkk >= a[x]) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
}
bool check(int x)
{
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        t[i] = get(i, x), id[i] = i;
        if (t[i] < 1) return false;
    }
    sort(id + 1, id + n + 1, [&](int x, int y){ return t[x] < t[y]; });
    int now = 0;
    for (int i = 1; i <= n; i++)
    {
        int y = id[i];
        if (vis[y]) continue;
        while (y && !vis[y])
        {
            vis[y] = true;
            y = f[y][0], now++;
        }
        if (now > t[id[i]]) return false;
    }
    return true;
}
signed main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    for (int i = 2; i <= n; i++) log_2[i] = log_2[i >> 1] + 1;
    dfs(1, 0);
    int l = 1, r = 1e9, ans;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}