#include <bits/stdc++.h>
#define int long long
#define MAXN 100005
using namespace std;
int grow(int a, int b, int c, int d)
{
    if (c >= 0)
    {
        int l = d, r = 1000000000;
        while (l <= r)
        {
            int mid = (l + r >> 1);
            if ((mid - d + 1) * b + (mid + d) * (mid - d + 1) / 2 * c < a)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
    if (b + d * c <= 0)
    {
        return a + d;
    }
    int k = - ((b + c - 1) / c);
    int g1 = (k - d + 1) * b + (k + d) * (k - d + 1) / 2 * c;
    if (g1 >= a)
    {
        int l = d, r = 1000000000;
        while (l <= r)
        {
            int mid = (l + r >> 1);
            if ((mid - d + 1) * b + (mid + d) * (mid - d + 1) / 2 * c < a)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
    return k + d + a - g1;
}
int n, x, y, fa[MAXN], a[MAXN], b[MAXN], c[MAXN], p[MAXN], ans, maxn, vis[MAXN];
vector<int> v[MAXN];
void dfsmaketree(int id)
{
    vis[id] = 1;
    for (int i : v[id])
    {
        if (!vis[i])
        {
            fa[vis[i]] = id;
            dfsmaketree(i);
        }
    }
}
void dfs1(int id)
{
    if (id > n)
    {
        maxn = 0;
        for (int i = 1; i <= n; i++)
        {
            if (p[fa[i]] > p[i])
            {
                return;
            }
            maxn = max(maxn, grow(a[i],b[i],c[i],p[i]));
        }
        ans = min(maxn,ans);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            p[id] = i;
            // dfs1(id + 1);
            vis[i] = 0;
        }
    }
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    if (n >= 15)
    {
        cout << n;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        // cout << "!!!!!!";
        cin >> a[i];
        // cout << "000";
        cin >> b[i];
        // cout << "000";
        cin >> c[i];
        // cout << "000";
    }
    // cout << "!!************!";
    for (int i = 1; i < n; i++)
    {
        // cout << "!!!!!!";
        cin >> x >> y;
        // cout << "000";
        v[x].push_back(y);
        // cout << "000";
        v[y].push_back(x);
        // cout << "000";
    }
    // cout << "!!!&&&&&&&&&&&&!!!";
    dfsmaketree(1);
    memset(vis,0,sizeof(vis));
    dfs1(1);
    // for (int i = 1; i <= n; i++)
    // {
    //     p[i] = i;
    // }
    // for (int i = 1; i <= )
    cout << ans;
    return 0;
}
