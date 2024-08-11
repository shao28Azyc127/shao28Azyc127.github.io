#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

const long long NR = 1e5 + 10;
long long n, m, k, d, ans = LONG_LONG_MIN;
long long x[NR], y[NR], z[NR];

void dfs(long long step, long long keep, long long score)
{
    if (step > n)
    {
        ans = max(score, ans);
        return;
    }
    if (keep > k) return;
    for (int i = 1; i <= m; i++)
    {
        if (x[i] == step - 1 && keep >= y[i]) score += z[i];
    }
    dfs(step + 1, keep + 1, score - d);
    dfs(step + 1, 0, score);
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    long long c, t;
    scanf("%lld%lld", &c, &t);
    while (t--)
    {
        scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
        for (long long i = 1; i <= m; i++)
            scanf("%lld%lld%lld", x + i, y + i, z + i);
        dfs(1, 0, 0);
        printf("%lld\n", ans);
    }

    return 0;
}
