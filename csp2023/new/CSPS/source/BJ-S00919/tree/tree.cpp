#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n, ans, a[N], b[N], c[N];
struct edge{int to, nxt; }e[N << 1];
int head[N], cnt;
void add(int u, int v) {
    e[++cnt] = (edge) {v, head[u]}, head[u] = cnt;
}

int calc(int x, int y) {
    if (y == 0) return 0;
    if (c[x] >= 0) {
        int s = b[x], t = b[x] + y * c[x];
        return (s + t) * y / 2;
    }
    int lim = (b[x] - 1) / (-c[x]);
    if (y <= lim) {
        int s = b[x], t = b[x] + y * c[x];
        return (s + t) * y / 2;
    }
    int s = b[x], t = b[x] + lim * c[x];
    return (s + t) * lim / 2 + y - lim;
}

signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> a[i] >> b[i] >> c[i];
    for (int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        add(u, v), add(v, u);
    }
    for (int i=1; i<=n; ++i) {
        int l = i, r = 1e9, res = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (calc(i, mid) - calc(i, i - 1) >= a[i]) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (ans < res) ans = res;
    }
    cout << ans << "\n";
    return 0;
}
