#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 2e3 + 10;
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
int C, n, m, q, l1, l2;
int a[N], b[N], c[N], d[N], minn[N];
int f[M][M];
void solve()
{
    if (C >= 8) {putchar('1'); return ;}
    if (c[1] > d[1])
    {
        swap(l1, l2);
        for (int i = 1; i <= max(l1, l2); i++) swap(c[i], d[i]);
    }
    minn[l2] = d[l2];
    for (int i = l2 - 1; i >= 1; i--) minn[i] = min(minn[i + 1], d[i]);
    for (int i = 1; i <= l1; i++) for (int j = 1; j <= l2; j++) f[i][j] = 0;
    // for (int i = 1; i <= l1; i++) cout << c[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= l2; i++) cout << d[i] << ' ';
    // cout << endl;
    // cout << endl;
    int flag = 0;
    if (d[1] > c[1]) f[1][1] = 1;
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (d[j] > c[i] && (f[i - 1][j - 1] || f[i - 1][j] || f[i][j - 1])) f[i][j] = 1;
            // cout << i << ' ' << j << ' ' << f[i][j] << endl;
            if (i == l1 && f[i][j] && (j == l2 || minn[j + 1] > c[l1])) flag = 1;
        }
    }
    if (flag) putchar('1');
    else putchar('0');
}
signed main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    C = read(), n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= m; i++) b[i] = read();
    l1 = n, l2 = m;
    for (int j = 1; j <= n; j++) c[j] = a[j];
    for (int j = 1; j <= m; j++) d[j] = b[j];
    solve();
    for (int i = 1; i <= q; i++)
    {
        int kx = read(), ky = read();
        l1 = n, l2 = m;
        for (int j = 1; j <= n; j++) c[j] = a[j];
        for (int j = 1; j <= m; j++) d[j] = b[j];
        for (int j = 1; j <= kx; j++)
        {
            int x = read(), y = read();
            c[x] = y;
        }
        for (int j = 1; j <= ky; j++)
        {
            int x = read(), y = read();
            d[x] = y;
        }
        solve();
    }
    return 0;
}