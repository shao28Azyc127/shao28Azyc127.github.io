#include <bits/stdc++.h>
using namespace std;

const int N = 2010, M = 500010;
int tid, n, m, q, a[M], b[M], c[M], d[M];
vector<int> f[N];

int solve() {
    bool flag = false;
    if (c[1] < d[1]) {
        swap(c, d), swap(n, m);
        flag = true;
    }
    for (int i=0; i<=n; ++i)
        f[i].clear();
    f[0].push_back(0);
    for (int i=1; i<=n; ++i) {
        int r = 0;
        for (auto j : f[i - 1]) {
            if (j && c[i] > d[j] && r < j)
                r = j, f[i].push_back(j);
            for (int k=max(j+1,r+1); k<=m; ++k) {
                if (c[i] <= d[k]) break;
                f[i].push_back(k), r = k;
            }
        }
    }
    int ret;
    if (f[n][f[n].size() - 1] == m) ret = 1;
    else ret = 0;
    if (flag) {
        swap(c, d), swap(n, m);
    }
    return ret;
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tid >> n >> m >> q;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        c[i] = a[i];
    }
    for (int i=1; i<=m; ++i) {
        cin >> b[i];
        d[i] = b[i];
    }
    if (n > 2000 || m > 2000) {
        int mxc = -1, mnc = 2e9, mxd = -1, mnd = 2e9;
        for (int i=1; i<=n; ++i) {
            if (c[i] > mxc) mxc = c[i];
            if (c[i] < mnc) mnc = c[i];
        }
        for (int i=1; i<=m; ++i) {
            if (d[i] > mxd) mxd = d[i];
            if (d[i] < mnd) mnd = d[i];
        }
        if (c[1] < d[1] && c[n] < d[m] && mxc < mxd && mnc < mnd) {
            cout << '1';
        } else if (c[1] > d[1] && c[n] > d[m] && mxc > mxd && mnc > mnd) {
            cout << '1';
        } else cout << '0';
    }
    else cout << solve();
    while (q--) {
        for (int i=1; i<=n; ++i) c[i] = a[i];
        for (int i=1; i<=m; ++i) d[i] = b[i];
        int x, y; cin >> x >> y;
        for (int i=1; i<=x; ++i) {
            int u, v; cin >> u >> v;
            c[u] = v;
        }
        for (int i=1; i<=y; ++i) {
            int u, v; cin >> u >> v;
            d[u] = v;
        }
        if (n > 2000 || m > 2000) {
            int mxc = -1, mnc = 2e9, mxd = -1, mnd = 2e9;
            for (int i=1; i<=n; ++i) {
                if (c[i] > mxc) mxc = c[i];
                if (c[i] < mnc) mnc = c[i];
            }
            for (int i=1; i<=m; ++i) {
                if (d[i] > mxd) mxd = d[i];
                if (d[i] < mnd) mnd = d[i];
            }
            if (c[1] < d[1] && c[n] < d[m] && mxc < mxd && mnc < mnd) {
                cout << '1';
            } else if (c[1] > d[1] && c[n] > d[m] && mxc > mxd && mnc > mnd) {
                cout << '1';
            } else cout << '0';
        }
        else cout << solve();
    }
    cout << "\n";
    return 0;
}
