#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, a[MAXN], b[MAXN], c[MAXN];
vector<int> g[MAXN];

typedef long long ll;
const ll INF = numeric_limits<ll>::max() / 2;

namespace Subtask1 {
    int tim[MAXN], pl[MAXN], ct[25][25];
    ll ans;
    vector<int> vis;

    void dfs(int cur) {
        if (cur == n + 1) {
            ll res = 0;
            for (int i = 1; i <= n; i++) {
                ll j = tim[i], r = 0;
                while (r < a[i] && b[i] + j * c[i] > 1) {
                    r += b[i] + j * c[i];
                    j++;
                }
                j--;
                if (r < a[i]) j += a[i] - r;
                res = max(res, j);
            }
            if (res < ans) {
                ans = res;
                memcpy(pl, tim, sizeof(pl));
            }
            return;
        }
        for (int u: vis) {
            for (int v: g[u]) {
                if (tim[v]) continue;
                tim[v] = cur;
                vis.push_back(v);
                dfs(cur + 1);
                tim[v] = 0;
                vis.pop_back();
            }
        }
    }
    inline void solve() {
        for (int i = 1; i <= n; i++) {
            for (int j: g[i])
                ct[i][j] = ct[j][i] = 1;
        }
        tim[1] = 1, ans = INF;
        vis.push_back(1);
        dfs(2);
        printf("%lld\n", ans);
    }
}

namespace Subtask2 {
    inline void solve() {
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ll j = i, r = 0;
            while (r < a[i] && b[i] + j * c[i] > 1) {
                r += b[i] + j * c[i];
                j++;
            }
            j--;
            if (r < a[i]) j += a[i] - r;
            ans = max(ans, j);
        }
        printf("%lld\n", ans);
    }
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    bool chain = 1;
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        chain &= (v == u + 1);
    }
    if (n <= 20) {
        Subtask1::solve();
        return 0;
    }
    if (chain) {
        Subtask2::solve();
        return 0;
    }
}

// g++ tree.cpp -o tree && ./tree
// expected 30pts

// Good Luck.