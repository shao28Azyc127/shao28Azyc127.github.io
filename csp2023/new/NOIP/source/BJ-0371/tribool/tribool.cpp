#include <bits/stdc++.h>//20pts
#define int long long
//Good luck!
//freopen("dict.in", "r", stdin);
//我预判了迷惑行为大赏的预判
using namespace std;
int cc, _, n, m, op, u, fa[200005], sz[200005], x;
char c[5];
int vis[100005];
inline int fd(int x)
{
    return fa[x] == x ? x : (fa[x] = fd(fa[x]));
}
inline void iinit()
{
    for (int i = 1; i <= 2 * n; i++)
        fa[i] = i, sz[i] = 1;
}
inline void mg(int x, int y)
{
    x = fd(x), y = fd(y);
    if (x == y)
        return ;
    if (sz[x] > sz[y])
        fa[y] = x, sz[x] += sz[y];
    else
        fa[x] = y, sz[y] += sz[x];
}
set <int> st;
signed main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%lld %lld", &cc, &_);
    if (cc == 3 || cc == 4)
    {
        while (_--)
        {
            scanf("%lld %lld", &n, &m);
            memset(vis, 0, sizeof vis);
            u = 0;
            for (int i = 1; i <= m; i++)
            {
                scanf("%s %lld", c, &op);
                if (c[0] == 'U')
                    vis[op] = 1;
                else
                    vis[op] = 0;
            }
            for (int i = 1; i <= n; i++)
                u += vis[i];
            printf("%lld\n", u);
        }
    }
    else if (cc == 5 || cc == 6)
    {
        while (_--)
        {
            scanf("%lld %lld", &n, &m);
            memset(vis, 0, sizeof vis);
            st.clear();
            iinit();
            for (int i = 1; i <= m; i++)
            {
                scanf("%s %lld", c, &op);
                if (c[0] == '+')
                {
                    scanf("%lld", &x);
                    vis[op] = x;
                }
                else
                    vis[op] = -1;
            }
            for (int i = 1; i <= n; i++)
            {
                if (vis[i] == -1)
                    vis[i] = 1;
                else
                {
                    mg(i, vis[i]);
                    vis[i] = 0;
                }
            }
            u = 0;
            for (int i = 1; i <= n; i++)
            {
                if (!st.count(fd(i)))
                {
                    if (vis[i])
                    {
                        u += sz[fd(i)];
                        st.insert(fd(i));
                    }
                }
            }
            printf("%lld\n", u);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}