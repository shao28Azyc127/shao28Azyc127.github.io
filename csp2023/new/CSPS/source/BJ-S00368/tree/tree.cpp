#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int MAXN = 100005;
int n, ans = 1e9;
LL a[MAXN], b[MAXN], c[MAXN];
vector<int> g[MAXN];
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
LL readll()
{
    LL x = 0, flag = 1;
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
void add(int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
namespace Solve1
{
    int day[25];
    bool vis[25];
    bool near(int x)
    {
        for(int i = 0; i < g[x].size(); ++i)
        {
            int v = g[x][i];
            if(vis[v]) return 1;
        }
        return 0;
    }
    bool check(int i, int x)
    {
        if(c[i] > 0) //越长越快
        {
            return 1ll * (x - day[i] + 1) * b[i] + 1ll * (day[i] + x) * (x - day[i] + 1) / 2 * c[i] >= 1ll * a[i];
        }
        else if(c[i] == 0)
        {
            return (x - day[i] + 1) * b[i] >= a[i];
        }
        else
        {
            int tmp = (1 - b[i]) / c[i];
            if(b[i] + tmp * c[i] == 1) --tmp;
            //前tmp天都大于1
            if(tmp <= 0)
            {
                return x >= a[i];
            }
            else if(tmp >= x)
            {
                return (x - day[i] + 1) * b[i] + (day[i] + x) * (x - day[i] + 1) / 2 * c[i] >= a[i];
            }
            else
            {
                return (tmp - day[i] + 1) * b[i] + (day[i] + tmp) * (tmp - day[i] + 1) / 2 * c[i] + (x - tmp) >= a[i];
            }
        }
    }
    int calc()
    {
        int res = 0;
        for(int i = 1; i <= n; ++i)
        {
            int l = day[i], r = 1e9, tmp = r;
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                if(check(i, mid))
                {
                    r = mid - 1;
                    tmp = mid;
                }
                else l = mid + 1;
            }
            //printf("%d:%d\n", i, tmp);
            res = max(res, tmp);
            /*if(c[i] >= 0) //越长越快或速度恒定
            {
                double B = 1.0 * ((2 * day[i] - 1) * c[i] + b[i]) / 2.0;
                x = ceil((-B + sqrt(B * B + 2 * c[i] * a[i]))/c[i]);
                res = max(res, x);
            }
            else //越长越慢
            {
                ;
            }*/
        }
        return res;
    }
    void dfs(int x)
    {
        if(x == n)
        {
            /*printf("day:\n");
            for(int i = 1; i <= n; ++i)
            {
                printf("%d:%d\n", i, day[i]);
            }
            puts("");*/
            ans = min(ans, calc());
            return;
        }
        for(int i = 2; i <= n; ++i)
        {
            if(vis[i]) continue;
            if(near(i))
            {
                day[i] = x + 1;
                vis[i] = 1;
                dfs(x + 1);
                vis[i] = 0;
                day[i] = 0;
            }
        }
    }
    int main()
    {
        for(int i = 1; i <= n; ++i) vis[i] = 0;
        /*for(int i = 1; i <= n; ++i)
        {
            printf("%d:", i);
            if(c[i] > 0) printf("faster\n");
            else if(c[i] == 0) printf("const\n");
            else printf("slower\n");
        }*/
        vis[1] = 1;
        day[1] = 1;
        dfs(1);
        printf("%d\n", ans);
        return 0;
    }
}
namespace Solve3
{
    bool check(int i, int x)
    {
        if(c[i] > 0) //越长越快
        {
            return 1ll * (x - i + 1) * b[i] + 1ll * (i + x) * (x - i + 1) / 2 * c[i] >= 1ll * a[i];
        }
        else if(c[i] == 0)
        {
            return (x - i + 1) * b[i] >= a[i];
        }
        else
        {
            int tmp = (1 - b[i]) / c[i];
            if(b[i] + tmp * c[i] == 1) --tmp;
            //前tmp天都大于1
            if(tmp <= 0)
            {
                return x >= a[i];
            }
            else if(tmp >= x)
            {
                return (x - i + 1) * b[i] + (i + x) * (x - i + 1) / 2 * c[i] >= a[i];
            }
            else
            {
                return (tmp - i + 1) * b[i] + (i + tmp) * (tmp - i + 1) / 2 * c[i] + (x - tmp) >= a[i];
            }
        }
    }
    int main()
    {
        int res = 0;
        for(int i = 1; i <= n; ++i)
        {
            int l = i, r = 1e9, tmp = r;
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                if(check(i, mid))
                {
                    r = mid - 1;
                    tmp = mid;
                }
                else l = mid + 1;
            }
            //printf("%d:%d\n", i, tmp);
            res = max(res, tmp);
            /*if(c[i] >= 0) //越长越快或速度恒定
            {
                double B = 1.0 * ((2 * day[i] - 1) * c[i] + b[i]) / 2.0;
                x = ceil((-B + sqrt(B * B + 2 * c[i] * a[i]))/c[i]);
                res = max(res, x);
            }
            else //越长越慢
            {
                ;
            }*/
        }
        printf("%d\n", res);
        return 0;
    }
}
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; ++i)
        a[i] = readll(), b[i] = readll(), c[i] = readll();
    bool flagb = 1;
    for(int i = 1; i < n; ++i)
    {
        int u = read(), v = read();
        if(!(u == i && v == i + 1)) flagb = 0;
        add(u, v);
    }
    if(n <= 20)
    {
        Solve1::main();
        return 0;
    }
    else if(flagb)
    {
        Solve3::main();
        return 0;
    }
    return 0;
}
