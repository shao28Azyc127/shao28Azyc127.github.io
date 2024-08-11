/*
20pts 暴力
+20pts 直接输出最终被赋值了的U的个数
+20pts 从每个U开始dfs
*/
#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
int c, t, n, m;
int read()
{
    int x = 0, flag = 1;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') flag = 0;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return flag ? x : -x;
}
namespace Solve1
{
    const int MAXN = 10, MAXM = 10;
    struct operation
    {
        int type;
        char v;
        int x, y;
    } op[MAXM];
    int ans, tmp, a[MAXN], b[MAXN];
    int change(int x)
    {
        if(x == 0) return 1;
        if(x == 1) return 0;
        if(x == 2) return 2;
    }
    bool check()
    {
        for(int i = 1; i <= n; ++i) b[i] = a[i];
        for(int i = 1; i <= m; ++i)
        {
            if(op[i].type == 0)
            {
                char v = op[i].v;
                int x = op[i].x;
                if(v == 'F') b[x] = 0;
                else if(v == 'T') b[x] = 1;
                else b[x] = 2;
            }
            else if(op[i].type == 1)
                b[op[i].x] = b[op[i].y];
            else
                b[op[i].x] = change(b[op[i].y]);
        }
        tmp = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(b[i] == 2) ++tmp;
            if(b[i] != a[i]) return 0;
        }
        return 1;
    }
    void dfs(int x)
    {
        if(x == n + 1)
        {
            if(check()) ans = min(ans, tmp);
            return;
        }
        for(int i = 0; i <= 2; ++i)
        {
            a[x] = i;
            dfs(x + 1);
        }
        a[x] = 0;
    }
    int main()
    {
        while(t--)
        {
            n = read(), m = read();
            for(int i = 1; i <= m; ++i)
            {
                char type;
                scanf(" %c", &type);
                if(type == 'T' || type == 'F' || type == 'U')
                {
                    int x = read();
                    op[i] = {0, type, x, 0};
                }
                else if(type == '+')
                {
                    int x = read(), y = read();
                    op[i] = {1, type, x, y};
                }
                else
                {
                    int x = read(), y = read();
                    op[i] = {2, type, x, y};
                }
            }
            ans = n;
            dfs(1);
            printf("%d\n", ans);
        }
        return 0;
    }
}
namespace Solve2
{
    const int MAXN = 100005;
    int a[MAXN];
    int main()
    {
        while(t--)
        {
            n = read(), m = read();
            for(int i = 1; i <= n; ++i) a[i] = 0;
            for(int i = 1; i <= m; ++i)
            {
                char type;
                scanf(" %c", &type);
                int x = read();
                if(type == 'F') a[x] = 0;
                else if(type == 'T') a[x] = 1;
                else a[x] = 2;
            }
            int ans = 0;
            for(int i = 1; i <= n; ++i)
                if(a[i] == 2) ++ans;
            printf("%d\n", ans);
        }
        return 0;
    }
}
namespace Solve3
{
    const int MAXN = 100005, MAXM = 100005;
    int a[MAXN];
    struct operation
    {
        int type;
        char v;
        int x, y;
    } op[MAXM];
    int tot = 0;
    int main()
    {

        while(t--)
        {
            n = read(), m = read();
            for(int i = 1; i <= n; ++i) a[i] = 0;
            tot = 0;
            for(int i = 1; i <= m; ++i)
            {
                char type;
                scanf(" %c", &type);
                if(type == 'U')
                {
                    int x = read();
                    //op[i] = {0, type, x, 0};
                    a[x] = 2;
                }
                else
                {
                    int x = read(), y = read();
                    if(a[y] != 2) op[++tot] = {1, type, x, y};
                    a[x] = a[y];
                }
            }
            //printf("tot = %d\n", tot);
            bool flag = 0;
            for(int i = 1; i <= tot; ++i)
            {
                if(a[op[i].x] != a[op[i].y])
                {
                    a[op[i].x] = a[op[i].y];
                    flag = 1;
                }
            }
            while(flag)
            {
                flag = 0;
                for(int i = 1; i <= tot; ++i)
                {
                    if(a[op[i].x] != a[op[i].y])
                    {
                        //printf("new:%d = %d\n", op[i].x, a[op[i].x]);
                        a[op[i].x] = a[op[i].y];
                        flag = 1;
                    }
                }
            }
            int ans = 0;
            for(int i = 1; i <= n; ++i)
                if(a[i] == 2) ++ans;
            printf("%d\n", ans);
        }
        return 0;
    }
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    c = read(), t = read();
    if(c <= 2)
    {
        Solve1::main();
    }
    else if(c <= 4)
    {
        Solve2::main();
    }
    else if(c <= 6)
    {
        Solve3::main();
    }
    return 0;
}
