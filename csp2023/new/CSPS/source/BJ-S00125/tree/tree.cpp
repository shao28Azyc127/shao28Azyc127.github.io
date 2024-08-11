#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 30;
long long n, g[N][N], a[N], b[N], c[N], used[N], mytime[N], res = 1e9;

long long get_time(int i)
{
    return ( a[i] / (long long)max(b[i], 1ll) ) + (a[i] % max(b[i], 1ll) != 0) + mytime[i];
}

void dfs(long long p, long long t)
{
    if (t == n + 1)
    {
        long long r = 0;
        for (int i = 1; i <= n; ++ i )
            r = max(r, get_time(i));
        res = min(r, res);
    }

    used[p] = 1, mytime[p] = t;
    for (int i = 1; i <= n; ++ i )
    {
        bool flag = 0;
        for (int j = 1; j <= n; ++ j )
            if (g[i][j] && used[j])
            {
                flag = 1;
                break;
            }
        if (!flag) continue;

        dfs(i, t + 1);
    }
    used[p] = 0;
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++ i )
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i <= n - 1; ++ i )
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    dfs(1, 1);
    cout<<res<<endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
