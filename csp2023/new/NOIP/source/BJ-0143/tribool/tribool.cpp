#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
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
int C, T, n, m, tot, cnt, cnt2, tot2, cnt3, flag;
int head[N], ver[N * 2], last[N * 2], edge[N * 2], a[N], t[N];
int head2[N], ver2[N * 2], last2[N * 2];
int bl[N], bl2[N], col[N], c[N], d[N];
char opt;
map<pair<int, int>, int> M;
void add(int x, int y, int z)
{
    ver[++tot] = y;
    last[tot] = head[x];
    edge[tot] = z;
    head[x] = tot;
}
void add2(int x, int y)
{
    ver2[++tot2] = y;
    last2[tot2] = head2[x];
    head2[x] = tot2;
}
void dfs(int x, int fa)
{
    for (int i = head[x]; i; i = last[i])
    {
        int y = ver[i], z = edge[i];
        if (y == fa) continue;
        if (z == 2)
        {
            if (bl[y] == bl[x]) d[bl[x]] = 1;
            continue;
        }
        if (bl[y]) continue;
        bl[y] = bl[x];
        dfs(y, x);
    }
}
void dfs2(int x, int fa)
{
    if (d[x]) flag = 0;
    for (int i = head2[x]; i; i = last2[i])
    {
        int y = ver2[i];
        if (y == fa) continue;
        if (bl2[y])
        {
            if (col[y] == col[x]) flag = 0;
            continue;
        }
        bl2[y] = bl2[x];
        col[y] = col[x] ^ 1;
        dfs2(y, x);
    }
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    C = read(), T = read();
    while (T--)
    {
        n = read(), m = read();
        memset(head, 0, sizeof(head));
        memset(head2, 0, sizeof(head2));
        memset(a, 0, sizeof(a));
        memset(t, 0, sizeof(t));
        memset(bl, 0, sizeof(bl));
        memset(bl2, 0, sizeof(bl2));
        memset(c, 0, sizeof(c));
        memset(col, 0, sizeof(col));
        memset(d, 0, sizeof(d));
        tot = cnt = cnt2 = tot2 = cnt3 = 0;
        M.clear();
        cnt = n + 3;
        for (int i = 1; i <= n; i++) a[i] = 3 + i;
        for (int i = 1; i <= m; i++)
        {
            cin >> opt;
            if (opt == 'T')
            {
                int x = read();
                cnt++;
                add(cnt, 1, 1);
                add(1, cnt, 1);
                a[x] = cnt; t[x] = i;
            }
            if (opt == 'F')
            {
                int x = read();
                cnt++;
                add(cnt, 2, 1);
                add(2, cnt, 1);
                a[x] = cnt; t[x] = i;
            }
            if (opt == 'U')
            {
                int x = read();
                cnt++;
                add(cnt, 3, 1);
                add(3, cnt, 1);
                a[x] = cnt; t[x] = i;
            }
            if (opt == '+')
            {
                int x = read(), y = read();
                if (x == y) continue;
                if (t[y] != i - 1)
                {
                    cnt++;
                    add(a[y], cnt, 1);
                    add(cnt, a[y], 1);
                    a[y] = cnt, t[y] = i - 1;
                }
                cnt++;
                a[x] = cnt, t[x] = i;
                add(a[x], a[y], 1);
                add(a[y], a[x], 1);
            }
            if (opt == '-')
            {
                int x = read(), y = read();
                if (t[y] != i - 1)
                {
                    cnt++;
                    add(a[y], cnt, 1);
                    add(cnt, a[y], 1);
                    a[y] = cnt, t[y] = i - 1;
                }
                cnt++;
                add(cnt, a[y], 2);
                add(a[y], cnt, 2);
                a[x] = cnt, t[x] = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == i + 3)
            {
                cnt++;
                add(cnt, a[i], 1);
                add(a[i], cnt, 1);
                continue;
            }
            if (t[i] != m)
            {
                cnt++;
                add(cnt, a[i], 1);
                add(a[i], cnt, 1);
                a[i] = cnt;
            }
            add(a[i], i + 3, 1);
            add(i + 3, a[i], 1);
        }
        for (int i = 1; i <= cnt; i++)
        {
            if (bl[i]) continue;
            bl[i] = ++cnt2;
            dfs(i, 0);
        }
        for (int i = 1; i <= tot; i += 2)
        {
            if (edge[i] != 2) continue;
            int x = bl[ver[i]], y = bl[ver[i + 1]];
            if (x == y) continue;
            if (M[make_pair(x, y)] || M[make_pair(y, x)]) continue;
            M[make_pair(x, y)] = 1;
            add2(x, y);
            add2(y, x);
        }
        for (int i = 1; i <= cnt2; i++)
        {
            if (bl2[i] != 0) continue;
            bl2[i] = ++cnt3;
            flag = 1;
            col[i] = 1;
            dfs2(i, 0);
            if (!flag) c[bl2[i]] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (bl2[bl[i + 3]] == bl2[bl[3]]) ans++;
            else if (c[bl2[bl[i + 3]]]) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}