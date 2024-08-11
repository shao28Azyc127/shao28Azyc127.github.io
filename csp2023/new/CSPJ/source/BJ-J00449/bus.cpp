#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<int> g[100010], t[100010];

long long ans = 9e18;

void dfs(int pos, int step, int starttime) {
    if (step > ans)
        return;
    if (pos == n && step % k == 0)
        ans = min(ans, 1ll * (starttime + step + k - 1) / k);
    for (int i = 0; i < g[pos].size(); i++)
        dfs(g[pos][i], step + 1, max(starttime, t[pos][i] - step));
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        int l, r, t_;
        scanf("%d%d%d", &l, &r, &t_);
        g[l].push_back(r);
        t[l].push_back(t_);
    }
    dfs(1, 0, 0);
    if (ans > 1e18)
        puts("-1");
    else
        printf("%lld\n", ans * k);
    return 0;
}
