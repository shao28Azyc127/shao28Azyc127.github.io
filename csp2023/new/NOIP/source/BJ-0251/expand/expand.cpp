#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int NR = 2010;
int x[NR], y[NR], a[NR], b[NR], c, n, m, q;
bool flag = false;
void dfs(int l, int r, int op, int x[], int y[])
{
    // cout << l << " " << r << '\n';
    if (flag) return;
    if (l >= n && r >= m) {flag = true; return;}
    if (op == 1)
    {
        if (l < n && r < m && x[l + 1] > y[r + 1]) dfs(l + 1, r + 1, op, x, y);
        if (r < m && x[l] > y[r + 1]) dfs(l, r + 1, op, x, y);
        if (l < n && x[l + 1] > y[r]) dfs(l + 1, r, op, x, y);
    }
    else
    {
        if (l < n && r < m && x[l + 1] < y[r + 1]) dfs(l + 1, r + 1, op, x, y);
        if (r < m && x[l] < y[r + 1]) dfs(l, r + 1, op, x, y);
        if (l < n && x[l + 1] < y[r]) dfs(l + 1, r, op, x, y);
    }
}
bool f[NR][NR];
bool task(int op, int x[], int y[])
{
    memset(f, false, sizeof(f));
    if (op == 0)
    {
        f[1][1] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (i < n && j < m && x[i + 1] < y[j + 1]) f[i + 1][j + 1] |= f[i][j];
                if (i < n && x[i + 1] < y[j]) f[i + 1][j] |= f[i][j];
                if (j < m && x[i] < y[j + 1]) f[i][j + 1] |= f[i][j];
            }
        return f[n][m];
    }
    if (op == 1)
    {
        f[1][1] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (i < n && j < m && x[i + 1] > y[j + 1]) f[i + 1][j + 1] |= f[i][j];
                if (i < n && x[i + 1] > y[j]) f[i + 1][j] |= f[i][j];
                if (j < m && x[i] > y[j + 1]) f[i][j + 1] |= f[i][j];
            }
        return f[n][m];
    }
}
int work(int x[], int y[])
{
    int op = 0;
    if (x[1] < y[1] && x[n] < y[m]) op = 0;
    else if (x[1] < y[1] && x[n] > y[m]) return 0;
    else if (x[1] > y[1] && x[n] < y[m]) return 0;
    else if (x[1] == y[1] || x[n] == y[m]) return 0;
    else op = 1;
    if (c <= 4)
    {
        dfs(1, 1, op, x, y);
        return flag;
    }
    return task(op, x, y);
}
signed main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= m; i++) cin >> y[i];
    cout << work(x, y);
    while (q--)
    {
        int kx, ky; cin >> kx >> ky;
        for (int i = 1; i <= n; i++) a[i] = x[i];
        for (int i = 1; i <= m; i++) b[i] = y[i];
        for (int i = 1; i <= kx; i++)
        {
            int px, vx;
            cin >> px >> vx, a[px] = vx;
        }
        for (int i = 1; i <= ky; i++)
        {
            int py, vy;
            cin >> py >> vy, b[py] = vy;
        }
        // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        // cout << '\n';
        // for (int i = 1; i <= m; i++) cout << b[i] << ' ';
        // cout << '\n';
        flag = false;
        cout << work(a, b);
    }
    return 0;
}
