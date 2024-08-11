#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x & -x)
using namespace std;

const int N = 1010;
int tid, T, n, m, k, d, f[N], t[N];
struct node{int l, w; };
vector<node> g[N];
void Max(int &x, int y) {if (x < y) x = y; }

void add(int x, int k) {
    for (; x<=n; x+=lowbit(x)) t[x] += k;
}
void add(int l, int r, int k) {
    add(l, k), add(r + 1, -k);
}
int query(int x) {
    int ret = 0;
    for (; x; x-=lowbit(x)) ret += t[x];
    return ret;
}

signed main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tid >> T;
    while (T--) {
        cin >> n >> m >> k >> d;
        for (int i=1; i<=n; ++i) g[i].clear();
        for (int i=1; i<=m; ++i) {
            int l, r, w; cin >> r >> l >> w;
            l = r - l + 1;
            g[r].push_back((node) {l, w});
        }
        f[0] = 0;
        int ans = 0;
        memset(t, 0, sizeof(t));
        for (int i=1; i<=n; ++i) {
            for (auto j : g[i]) add(1, j.l, j.w);
            f[i] = 0;
            add(1, i, -d);
            int mx = 0;
            for (int j=i; j; --j) {
                if (i - j + 1 <= k)
                    Max(mx, query(j));
                if (j > 2) Max(f[i], f[j - 2] + mx);
                Max(f[i], mx);
            }
            Max(ans, f[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
