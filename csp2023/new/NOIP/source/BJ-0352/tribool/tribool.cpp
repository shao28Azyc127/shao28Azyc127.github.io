#include <cstdio>
#include <algorithm>
using namespace std;
const int NR = 1e5;
int C,T,n,m,f[NR + 5],val[NR + 5],op[NR + 5],t,to[NR + 5],nxt[NR + 5],head[NR + 5],typ[NR + 5],siz,ans,a[NR + 5],b[NR + 5],c[NR + 5],d[NR + 5],e[NR + 5];
bool vis[NR + 5],mrk[NR + 5];
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}
inline void write(int x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
inline void add(int x,int y,int z)
{
    t++;
    to[t] = y;
    typ[t] = z;
    nxt[t] = head[x];
    head[x] = t;
    return;
}
inline void dfs1(int x)
{
    vis[x] = true;
    siz++;
    for (int i = head[x];i != 0;i = nxt[i])
    {
        int y = to[i];
        if (mrk[y] == false)
            dfs1(y);
    }
    return;
}
inline void dfs2(int x,int rt)
{
    vis[x] = true;
    for (int i = head[x];i != 0;i = nxt[i])
    {
        int y = to[i];
        if (y != rt)
            dfs2(y,rt);
        else
        {
            int cnt = 0,p = x;
            siz = 0;
            while (p != rt)
            {
                mrk[p] = true;
                p = f[p];
            }
            mrk[rt] = true;
            while (x != rt)
            {
                dfs1(x);
                if (op[x] == 2)
                    cnt++;
                x = f[x];
            }
            dfs1(x);
            if (op[x] == 2)
                cnt++;
            if (cnt & 1)
                ans += siz;
            return;
        }
    }
    return;
}
inline void dfs(int x,int cnt)
{
    if (x <= n)
    {
        for (int i = 1;i <= 3;i++)
        {
            d[x] = i;
            if (i == 3)
                dfs(x + 1,cnt + 1);
            else
                dfs(x + 1,cnt);
        }
    }
    else
    {
        for (int i = 1;i <= n;i++)
            e[i] = d[i];
        for (int i = 1;i <= m;i++)
        {
            if (a[i] == 1)
                e[b[i]] = c[i];
            else
            {
                if (a[i] == 2)
                    e[b[i]] = e[c[i]];
                else
                {
                    if (e[c[i]] == 3)
                        e[b[i]] = 3;
                    else
                        e[b[i]] = 3 - e[c[i]];
                }
            }
        }
        for (int i = 1;i <= n;i++)
            if (e[i] != d[i])
                return;
        ans = min(ans,cnt);
    }
    return;
}
inline void work()
{
    n = read();
    m = read();
    for (int i = 1;i <= m;i++)
    {
        char ch = getchar();
        while (ch != 'T' && ch != 'F' && ch != 'U' && ch != '+' && ch != '-')
            ch = getchar();
        if (ch == 'T' || ch == 'F' || ch == 'U')
        {
            a[i] = 1;
            b[i] = read();
            if (ch == 'T')
                c[i] = 1;
            else
            {
                if (ch == 'F')
                    c[i] = 2;
                else
                    c[i] = 3;
            }
        }
        else
        {
            if (ch == '+')
                a[i] = 2;
            else
                a[i] = 3;
            b[i] = read();
            c[i] = read();
        }
    }
    ans = n;
    dfs(1,0);
    write(ans);
    putchar('\n');
    return;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    C = read();
    T = read();
    while (T--)
    {
        if (C <= 2)
        {
            work();
            continue;
        }
        ans = 0;
        n = read();
        m = read();
        t = 0;
        for (int i = 1;i <= n;i++)
        {
            f[i] = -1;
            val[i] = 0;
            op[i] = 1;
            head[i] = 0;
            vis[i] = false;
            mrk[i] = false;
        }
        for (int i = 1;i <= m;i++)
        {
            char ch = getchar();
            while (ch != 'T' && ch != 'F' && ch != 'U' && ch != '+' && ch != '-')
                ch = getchar();
            if (ch == 'T' || ch == 'F' || ch == 'U')
            {
                int x = read();
                f[x] = 0;
                if (ch == 'T')
                    val[x] = 1;
                else
                {
                    if (ch == 'F')
                        val[x] = 2;
                    else
                        val[x] = 3;
                }
            }
            else
            {
                int x = read(),y = read();
                if (ch == '+')
                {
                    if (f[y] == 0)
                    {
                        f[x] = 0;
                        val[x] = val[y];
                    }
                    else
                    {
                        f[x] = y;
                        op[x] = 1;
                    }
                }
                else
                {
                    if (f[y] == 0)
                    {
                        f[x] = 0;
                        if (val[y] == 1)
                            val[x] = 2;
                        else
                        {
                            if (val[y] == 2)
                                val[x] = 1;
                            else
                                val[x] = 3;
                        }
                    }
                    else
                    {
                        f[x] = y;
                        op[x] = 2;
                    }
                }
            }
        }
        for (int i = 1;i <= n;i++)
            if (f[i] != 0 && f[i] != -1)
                add(f[i],i,op[i]);
        for (int i = 1;i <= n;i++)
            if (f[i] == 0)
            {
                siz = 0;
                dfs1(i);
                if (val[i] == 3)
                    ans += siz;
            }
        for (int i = 1;i <= n;i++)
            if (vis[i] == false)
                dfs2(i,i);
        write(ans);
        putchar('\n');
    }
    return 0;
}