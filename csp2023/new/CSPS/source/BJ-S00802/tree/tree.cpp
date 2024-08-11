#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

const long long NR = 1e5;
struct Edge
{
    long long to, next, w;
}e[NR];
long long cnt, head[NR], a[NR], b[NR], c[NR], h[NR];
long long n, ans = 1e9;
bool vis[NR];

long long step = 1;

void add(long long x, long long y)
{
    e[++cnt] = (Edge){y, head[x]};
    head[x] = cnt;
}

bool check()
{
    for (long long i = 1; i <= n; i++)
        if (h[i] < a[i]) return false;
    return true;
}

bool full()
{
    for (long long i = 1; i <= n; i++)
        if (vis[i] == false) return false;
    return true;
}

void grow()
{
    for (long long i = 1; i <= n; i++)
        if (vis[i]) h[i] += max(b[i] + step * c[i], 1ll);
}

void back()
{
    for (long long i = 1; i <= n; i++)
        if (vis[i]) h[i] -= max(b[i] + step * c[i], 1ll);
}

void dfs()
{
    if (step >= ans) return;
    if (check())
    {
        ans = min(ans, step - 1);
        return;
    }
    for (long long i = 0; i <= n; i++)
    {
        if (vis[i] == false) continue;
        for (long long j = head[i]; j; j = e[j].next)
        {
            if (vis[e[j].to] == false)
            {
                vis[e[j].to] = true;
                grow();
                step++;
                dfs();
                step--;
                back();
                vis[e[j].to] = false;
            }
        }
    }
    if (full())
    {
        if (step >= ans) return;
        grow();
        step++;
        dfs();
        step--;
        back();
    }
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
        scanf("%lld%lld%lld", a + i, b + i, c + i);
    for (long long i = 1; i <= n - 1; i++)
    {
        long long u, v;
        scanf("%lld%lld", &u, &v);
        add(u, v);
        add(v, u);
    }
    add(0, 1);
    vis[0] = true;
    dfs();
    printf("%lld\n", ans);
    return 0;
}
