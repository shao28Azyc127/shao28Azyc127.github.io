#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 1000 + 10
#define M 100000 + 10
typedef long long ll;

struct run
{
    int x;
    int y;
    int v;
};

run a[M];
ll ans;
int n, m, k, d;

void dfs(int i, int j, ll sum)
{
    if (i > n)
    {
        ans = max(ans, sum);
        return;
    }
    dfs(i + 1, 0, sum);
    if (j < k)
    {
        j++;
        for (int t = 1; t <= m; t++)
            if (a[t].x == i && a[t].y == j)
                sum += a[t].v;
        dfs(i + 1, j, sum - d);
    }
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    int c, t;
    scanf("%d%d", &c, &t);
    while (t--)
    {
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for (int i = 1; i <= m; i++)
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);

        ans = -1e18;
        dfs(0, 0, 0);

        printf("%lld\n", ans);
    }
    
    fclose(stdin);
    fclose(stdout);

    return 0;
}