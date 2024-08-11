#include <bits/stdc++.h>
using namespace std;
int test, T, n, m, dir[100010], w[100010];
char op[100010];
int u[100010], v[100010];
int ans[100010], fans = 2e9, x[100010];
bool vis[100010];
int f(char c)
{
    if (c == 'U') return -2;
    if (c == 'T') return -1;
    if (c == 'F') return 0;
}
int rev (int x)
{
    if (x == 2) return 2;
    return 1 - x;
}
//T:1,F:0,U:2
int get (int x, int ww)
{
    //cout << vis[x] << " " << x << " " << ww << endl;

    if (vis[x] && ww == -1) return -2;
    if (vis[x] && ww == 1) return x;
    vis[x] = 1;
    if (dir[x] <= 0) return dir[x];
    return get(dir[x], w[x] * ww);
}
void dfs (int p, int unk)
{
    if (unk > fans) return;
    if (p > n)
    {
        for (int i = 1; i <= n; i++)
        {
            x[i] = ans[i];
        }
        for (int i = 1; i <= m; i++)
        {
            if (op[i] == '+') x[u[i]] = x[v[i]];
            else if (op[i] == '-') x[u[i]] = rev(x[v[i]]);
            else x[u[i]] = -f(op[i]);
        }
        bool f = 1;
        for (int i = 1; i <= n; i++)
        {
            if (x[i] != ans[i])
            {
                f = 0;
                break;
            }
        }
        if (f == 1) fans = min(fans, unk);
        return;
    }
    for (ans[p] = 0; ans[p] <= 2; ans[p]++) dfs(p + 1, unk + (ans[p] == 2));
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> test >> T;
    while (T--)
    {
        if (test <= 2)
        {
            cin >> n >> m;
            fans = 2e9;
            for (int i = 1; i <= m; i++)
            {
                cin >> op[i];
                cin >> u[i];
                if (op[i] == '+' || op[i] == '-') cin >> v[i];
            }
            dfs(1, 0);
            cout << fans << endl;
        }
        else
        {
            cin >> n >> m;
            for (int i = 1; i <= n; i++) dir[i] = -1, w[i] = ans[i] = 0;
            while (m--)
            {
                char opt; int u, v;
                cin >> opt >> u;
                if (opt == '+')
                {
                    cin >> v;
                    dir[u] = v, w[u] = 1;
                }
                else if (opt == '-')
                {
                    cin >> v;
                    dir[u] = v, w[u] = -1;
                }
                else dir[u] = f(opt);
            }
            //cout << endl;
            for (int u = 1; u <= n; u++)
            {
                if (dir[u] <= 0) ans[u] = dir[u];
                else ans[u] = -114;
            }
            //for (int i = 1; i <= n; i++) cout << dir[i] << " " << w[i] << endl;
            for (int i = 1; i <= n; i++)
            {
                if (ans[i] != -114) continue;
                for (int j = 1; j <= n; j++) vis[j] = 0;
                int finale = get(i, 1);
                ans[i] = finale;
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++) if (ans[i] == -2) cnt++;
            cout<<cnt << endl;
        }

    }

    return 0;
}
