#include <bits/stdc++.h>
using namespace std;
const int N = 25, M = 1e5 + 10;
#define int long long
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int n, ans;
int a[M], b[M], c[M], d[M];
int Map[N][N];
int cal(int pos)
{
    int l = 0, r = 1e9, mid, res = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (c[pos] >= 0)
        {
            if ((b[pos] * 2 + (d[pos] * 2 + mid) * c[pos]) * (mid + 1) / 2 >= a[pos]) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        if (c[pos] < 0)
        {
            if ((mid + d[pos]) * c[pos] + b[pos] <= 0)
            {
                int t = (b[pos] + abs(c[pos]) - 1) / abs(c[pos]);
                if (d[pos] >= t)
                {
                    if (mid + 1 >= a[pos]) res = mid, r = mid - 1;
                    else l = mid + 1;
                }
                if ((b[pos] + d[pos] * c[pos] + b[pos] + (t - 1) * c[pos]) * (t - d[pos]) / 2 + (mid + d[pos] - t + 1) >= a[pos]) res = mid, r = mid - 1;
                else l = mid + 1;
            }
            else
            {
                if ((b[pos] + d[pos] * c[pos] + b[pos] + (d[pos] + mid) * c[pos]) * (mid + 1) / 2 >= a[pos]) r = mid - 1, res = mid;
                else l = mid + 1;
            }
        }
    }
    return res;
}
void dfs(int x)
{
    if (x == n)
    {
        int t = 0;
        // for (int i = 1; i <= n; i++) cout << d[i] << ' ';
        // cout << endl;
        for (int i = 1; i <= n; i++)
        {
            t = max(t, d[i] + cal(i));
            // cout << i << ' ' << cal(i) << endl;
        }
        // cout << endl;
        if (ans == -1) ans = t;
        else ans = min(ans, t);
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i]) continue;
        int flag = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!Map[i][j]) continue;
            if (d[j]) flag = 1;
        }
        if (!flag) continue;
        d[i] = x + 1;
        dfs(x + 1);
        d[i] = 0;
    }
}
signed main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read(), c[i] = read();
    if (n <= 20)
    {
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read();
            Map[u][v] = 1; Map[v][u] = 1;
        }
        d[1] = 1;
        ans = -1;
        dfs(1);
        printf("%lld\n", ans);
    }
    else
    {
        int minn = 0;
        for (int i = 1; i <= n; i++)
        {
            d[i] = i;
            minn = max(minn, d[i] + cal(i));
        }
        printf("%lld\n", minn);
    }
    return 0;
}