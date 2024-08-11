#include <bits/stdc++.h>
using namespace std;
int n, m, ans, a[200010], fan[200010], f[200010];
bool now[200010];
vector<int> v[200010];
stack<int> s;
bool dfs(int x, int y)
{
    s.push(x);
    if (f[x] && (now[x] || y != 2 * n + 3))
    {
        if (f[x] != y && now[x]) return false;
        return true;
    }
    now[x] = true;
    f[x] = y;
    bool flag = true;
    for (auto i : v[x])
    {
        if (i <= n)
        {
            if (!dfs(i, y)) flag = false;
        }
        else
        {
            if (!dfs(i - n, fan[y])) flag = false;
        }
    }
    now[x] = false;
    return flag;
}
signed main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= 2 * n + 3; i++)
        {
            a[i] = i;
            v[i].clear();
            f[i] = 0;
        }
        for (int i = 1; i <= n; i++) fan[i] = i + n;
        for (int i = n + 1; i <= 2 * n; i++) fan[i] = i - n;
        fan[2 * n + 1] = 2 * n + 2;
        fan[2 * n + 2] = 2 * n + 1;
        fan[2 * n + 3] = 2 * n + 3;
        for (int i = 1; i <= m; i++)
        {
            char op;
            int x, y;
            cin >> op >> x;
            if (op == 'T') a[x] = 2 * n + 1;
            else if (op == 'F') a[x] = 2 * n + 2;
            else if (op == 'U') a[x] = 2 * n + 3;
            else if (op == '+')
            {
                cin >> y;
                a[x] = a[y];
            }
            else if (op == '-')
            {
                cin >> y;
                a[x] = fan[a[y]];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > n && a[i] <= 2 * n) v[fan[a[i]]].push_back(fan[i]);
            else v[a[i]].push_back(i);
        }
        dfs(2 * n + 1, 2 * n + 1);
        dfs(2 * n + 2, 2 * n + 2);
        dfs(2 * n + 3, 2 * n + 3);
        for (int i = 1; i <= n; i++)
        {
            if (f[i]) continue;
            if (!dfs(i, 2 * n + 1))
            {
                while (!s.empty()) f[s.top()] = 0, s.pop();
                if (!dfs(i, 2 * n + 2))
                {
                    while (!s.empty()) f[s.top()] = 0, s.pop();
                    dfs(i, 2 * n + 3);
                }
            }
            while (!s.empty()) s.pop();
        }
        ans = 0;
        for (int i = 1; i <= n; i++) if (f[i] == 2 * n + 3) ans++;
        cout << ans << '\n';
    }
    return 0;
}