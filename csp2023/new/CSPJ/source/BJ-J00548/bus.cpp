// Wish my son recovering soon!

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int maxn = 2e4 + 10;
const int maxk = 100 + 10;
const int maxpending = 2000000 + maxn;
const int inf = 1e8;
int n, m, k, np = 0, cur = 0, f[maxn][maxk];
vector<pii > pending[maxpending];
vector<pii > e[maxn];
queue<pii > que;
inline void dump(int d) {
    for (auto x : pending[d]) {
        int v = x.first, t = x.second;
        if (f[v][t] == inf) {
            f[v][t] = d;
            que.push({v, t});
        }
    }
    pending[d].clear();
    --np;
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v, a; scanf("%d%d%d", &u, &v, &a);
        e[u].push_back({v, a});
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            f[i][j] = inf;
    f[1][0] = 0;
    que.push({1, 0});
    while (1) {
        while (que.size()) {
            int u = que.front().first, j = que.front().second, d = f[u][j]; que.pop();
            if (pending[d + 1].size()) dump(d + 1);
            for (auto x : e[u]) {
                int v = x.first, a = x.second;
                if (d >= a) {
                    if (f[v][(j + 1) % k] == inf) {
                        f[v][(j + 1) % k] = d + 1;
                        que.push({v, (j + 1) % k});
                    }
                } else {
                    int val = d + 1 + (a - d + k - 1) / k * k;
                    if (pending[val].empty()) ++np;
                    pending[val].push_back({v, (j + 1) % k});
                }
            }
        }
        if (np == 0) break;
        while (pending[cur].empty()) ++cur;
        dump(cur);
    }
    if (f[n][0] == inf) printf("-1\n");
    else printf("%d\n", f[n][0]);
    return 0;
}
