#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int c, t, n, m, k, d, maxx;
long long ans, res;
int num[100000];
int y[100001], v[100001];

void dfs(int x, int len)
{
    if (x >= n)
    {
        res = max(ans, res);
        return;
    }

    if (x > maxx && ans <= res)
    {
        return;
    }

    dfs(x + 1, 0);

    if (len < k)
    {
        if (num[x] && len + 1 >= y[num[x]])
        {
            ans += v[num[x]] - d;
            dfs(x + 1, len + 1);
            ans -= v[num[x]] - d;
        }
        else
        {
            ans -= d;
            dfs(x + 1, len + 1);
            ans += d;
        }
    }
}

int main(void)
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    cin >> c >> t;
    while (t--)
    {
        res = 0;
        cin >> n >> m >> k >> d;
        for (int i = 0; i < n; i++)
        {
            num[n] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x >> y[i] >> v[i];
            num[--x] = i;
            maxx = max(maxx, x);
        }
        dfs(0, 0);
        cout << res << endl;
    }

    return 0;
}
