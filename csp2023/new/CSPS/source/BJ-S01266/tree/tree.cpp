#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N], c[N];
vector<int> e[N];
int f[1 << 20], can[N];
inline int calc(int ind, int sta) {
    // b[ind] + sta * c[ind]
    int l = 0, r = 1000000000;
    if (c[ind] < 0) {
        if (can[ind] >= sta) {
            int res = (can[ind] - sta + 1) * (b[ind] + sta * c[ind] + b[ind] + can[ind] * c[ind]) / 2;
            if (res < a[ind]) {
                return can[ind] - sta + a[ind] - res;
            } else {
                r = can[ind] - sta;
            }
        } else {
            return a[ind] - 1;
        }
    }
    // printf("dee:%lld %lld %lld\n", ind, sta, can[ind]);
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = (mid + 1) * (b[ind] + sta * c[ind] + b[ind] + (sta + mid) * c[ind]) / 2;
        // printf("de:%lld %lld %lld\n", sta, sta + mid, res);
        if (res < a[ind]) l = mid + 1;
        else r = mid;
    }
    return l;
}
signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%lld", &n);
    rep(i, 1, n) {
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
        if (c[i] < 0) can[i] = (b[i] - 1) / (-c[i]);
        else can[i] = -1;
    }
    bool flg = 1;
    rep(i, 2, n) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        if (v != u + 1) flg = 0;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    if (n <= 20) {
        memset(f, 0x3f, sizeof(f));
        f[1] = calc(1, 1);
        int SS = (1 << n) - 1;
        rep(S, 1, SS) if (S & 1) {
            int now = __builtin_popcount(S);
            rep(i, 2, n) if (S >> (i - 1) & 1) {
                int cnt = 0;
                for (auto &v: e[i]) if (S >> (v - 1) & 1) ++cnt;
                if (cnt == 1) f[S] = min(f[S], max(f[S ^ (1 << (i - 1))], now + calc(i, now)));
            }
        }
        printf("%lld\n", f[SS]);
    } else if (flg) {
        int ans = 0;
        rep(i, 1, n) ans = max(ans, i + calc(i, i));
        printf("%lld\n", ans);
    } else {
        ;
    }
    return 0;
}