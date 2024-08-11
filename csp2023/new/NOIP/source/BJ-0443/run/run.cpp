#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXM = 1e5 + 5;

typedef long long ll;

namespace Sub1 {
    ll f[1005][1005];
    int n, m, k, d;
    vector<pair<int, int> > cs[1005];
    void solve() {
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for (int i = 1; i <= n; ++i) cs[i].clear();
        for (int i = 1; i <= m; ++i) {
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            cs[x].push_back({ y, v });
        }
        memset(f, ~0x3f, sizeof(f));
        for (int i = 0; i <= n; ++i) f[i][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) f[i][0] = max(f[i][0], f[i - 1][j]);
            for (int j = 1; j <= k; ++j) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] - d);
                for (auto t : cs[i]) {
                    int y = t.first, v = t.second;
                    if (j >= y) f[i][j] += v;
                }
            }
        }
        /*for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                printf("%lld ", f[i][j]);
            }
            printf("\n");
        }*/
        ll ans = 0;
        for (int i = 0; i <= k; ++i) ans = max(ans, f[n][i]);
        printf("%lld\n", ans);
    }
}

namespace Normal {
    void solve() {
        printf("0\n");
    }
}

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while (t--) {
        if (c >= 1 && c <= 9) Sub1::solve();
        else Normal::solve();
    }
    return 0;
}