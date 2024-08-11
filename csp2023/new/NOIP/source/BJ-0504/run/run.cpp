#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, d, ans;
struct node
{
    int x;
    int y;
    int v;
}a[105];
int p[105], f[105], Y[105], val[105];

void dfs(int s, int prv, int cnt)
{
    if (cnt > k && prv == 1)
    {
        return;
    }
    if (s == n)
    {
        int tot = 0;
        for (int i = 1; i <= n; i++)
        {
            tot += p[i];
        }
        int sum = -d * tot;
        int jsq = 1;
        for (int i = 1; i <= n; i++)
        {
            if ((p[i] == p[i - 1]) && p[i] == 1)
            {
                jsq++;
            }
            else
            {
                jsq = 1;
            }
            if (f[i])
            {
                if (jsq >= Y[i])
                {
                    sum += val[i];
                }
            }
        }
            //cout << v * flg << endl;
            /*
        if (sum > ans)
        {
            cout << sum << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << p[i];
            }
            cout << endl;
        }
        */
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        if (prv == i)
        {
            p[s + 1] = i;
            dfs(s + 1, i, cnt + 1);
        }
        else
        {
            p[s + 1] = i;
            dfs(s + 1, i, 1);
        }
    }
}

signed main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        if (c <= 4)
        {
            cin >> n >> m >> k >> d;
            for (int i = 1; i <= m; i++)
            {
                cin >> a[i].x >> a[i].y >> a[i].v;
                f[a[i].x] = 1;
                val[a[i].x] = a[i].v;
                Y[a[i].x] = a[i].y;
            }
            ans = -1e15;
            memset(a, 0, sizeof(a));
            memset(p, 0x3f, sizeof(p));
            dfs(0, 2, 0);
            cout << ans << endl;
            /*
            for (int i = 1; i <= n; i++)
            {
                cout << q[i];
            }
            */
            cout << endl;
        }
    }
    return 0;
}