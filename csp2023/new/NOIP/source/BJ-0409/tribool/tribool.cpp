#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5 + 5, M = 2 * N;

int c, t, n, m, x, y, a[N], f[M], vis[M], ans;
string s;

void init()
{
    for (int i = 1; i <= 2 * n; i++) f[i] = i;
}

int find(int x)
{
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

void merge(int x, int y)
{
    x = find(x), y = find(y);
    f[x] = y;
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &t);
    if (c == 3 || c == 4)
    {
        while (t--)
        {
            ans = 0;
            memset(a, 0, sizeof a);
            scanf("%d%d", &n, &m);
            for (int i = 1; i <= m; i++)
            {
                cin >> s;
                if (s[0] == 'T')
                {
                    scanf("%d", &x);
                    a[x] = 1;
                }
                if (s[0] == 'F')
                {
                    scanf("%d", &x);
                    a[x] = 2;
                }
                if (s[0] == 'U')
                {
                    scanf("%d", &x);
                    a[x] = 3;
                }
            }
            for (int i = 1; i <= n; i++)
                if (a[i] == 3)
                    ans++;
            printf("%d\n", ans);
        }
    }
    else
    {
        while (t--)
        {
            ans = 0;
            memset(a, 0, sizeof a);
            memset(vis, 0, sizeof vis);
            scanf("%d%d", &n, &m);
            init();
            for (int i = 1; i <= m; i++)
            {
                cin >> s;
                if (s[0] == 'T')
                {
                    scanf("%d", &x);
                    a[x] = -1;
                }
                if (s[0] == 'F')
                {
                    scanf("%d", &x);
                    a[x] = -2;
                }
                if (s[0] == 'U')
                {
                    scanf("%d", &x);
                    a[x] = -3;
                }
                if (s[0] == '+')
                {
                    scanf("%d%d", &x, &y);
                    if (x != y) a[x] = y;
                }
                if (s[0] == '-')
                {
                    scanf("%d%d", &x, &y);
                    a[x] = y + n;
                }
            }
            for (int i = 1; i <= n; i++)
            {
                if (a[i] > 0 && a[i] <= n) merge(i, a[i]), merge(i + n, a[i] + n);
                if (a[i] > n) merge(i, a[i]), merge(i + n, a[i] - n);
            }
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == -3) vis[find(i)] = vis[find(i + n)] = 1;
                if (find(i) == find(i + n)) vis[find(i)] = 1;
            }
            for (int i = 1; i <= n; i++)
                if (vis[find(i)])
                    ans++;
            printf("%d\n", ans);
        }
    }
    return 0;
}