#include <iostream>
#include <cstdio>
using namespace std;
const int NR = 100010;
char op[NR], a[NR], b[NR];
int x[NR], y[NR], n, m, ans = 1e9;
char get_reverse(char x)
{
    if (x == 'T') return 'F';
    if (x == 'F') return 'T';
    return 'U';
}
void dfs(int step)
{
    if (step > n)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++) b[i] = a[i];
        for (int i = 1; i <= n; i++)
            if (a[i] == 'U') cnt++;
        for (int i = 1; i <= m; i++)
        {
            if (op[i] == '+') b[x[i]] = b[y[i]];
            else if (op[i] == '-') b[x[i]] = get_reverse(b[y[i]]);
            else b[x[i]] = op[i];
        }
        bool vis = true;
        for (int i = 1; i <= n; i++)
            if (b[i] != a[i]) vis = false;
        if (vis == true) ans = min(ans, cnt);
        return;
    }
    a[step] = 'T'; dfs(step + 1);
    a[step] = 'F'; dfs(step + 1);
    a[step] = 'U'; dfs(step + 1);
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> op[i];
            if (op[i] == '+' || op[i] == '-')
                cin >> x[i] >> y[i];
            else cin >> x[i];
        }
        if (c == 1 || c == 2)
        {
            ans = 1e9;
            dfs(1);
            cout << ans << '\n';
        }
        else if (c == 3 || c == 4)
        {
            int cnt = 0;
            for (int i = 1; i <= m; i++)
                a[x[i]] = op[i];
            for (int i = 1; i <= n; i++)
                if (a[i] == 'U') cnt++;
            cout << cnt << '\n';
        }
    }
    return 0;
}
