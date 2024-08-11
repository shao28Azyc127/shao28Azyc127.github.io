#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

bool f[N][N];
int csq, n, q, m, a[N], b[N];

int c[N], d[N];

bool solve() {
    if (a[n] == b[n]) {
        return false;
    }
    bool fl = false;
    if (a[n] > b[m]) {
        for (int i = 1; i <= n; i ++ ) {
            c[i] = a[i];
        }
        for (int i = 1; i <= m; i ++ ) {
            d[i] = b[i];
        }
    } else {
        for (int i = 1; i <= n; i ++ ) {
            d[i] = a[i];
        }
        for (int i = 1; i <= m; i ++ ) {
            c[i] = b[i];
        }
        swap(n, m);
        fl = true;
    }

    if (csq >= 10) {
        bool fl = false;
        for (int i = 1; i <= n; i ++ ) {
            if (c[n] < d[i]) {
                return false;
            }
        }
        return true;
    }

    memset(f, 0, sizeof f);
    f[0][0] = 1;
    int law = 0, lan = 0;
    for (int i = 1; i <= n; i ++ ) {
        law = 0, lan = f[i - 1][0];
        for (int j = 1; j <= m; j ++ ) {
            if (c[i] <= d[j]) {
                law = j;
                lan = f[i - 1][law];
                continue;
            }
            lan |= f[i - 1][j];
            f[i][j] = lan;
        }
    }
    int res = f[n][m];
    if (fl) {
        swap(n, m);
    }
    return res;
}

vector<pair<int, int> > ops;


namespace TD {
    const int N = 5e5 + 5;
    void solve() {

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> csq >> n >> m >> q;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i ++ ) {
        cin >> b[i];
    }
    cout << solve();
    for (int i = 1; i <= q; i ++ ) {
        int kx, ky;
        cin >> kx >> ky;
        int op, x;
        ops.clear();
        for (int i = 1; i <= kx; i ++ ) {
            cin >> op >> x;
            ops.push_back({op, a[op]});
            a[op] = x;
        }
        for (int i = 1; i <= ky; i ++ ) {
            cin >> op >> x;
            ops.push_back({op, b[op]});
            b[op] = x;
        }
        cout << solve();
        for (int i = 1; i <= kx; i ++ ) {
            auto t = ops[i - 1];
            a[t.first] = t.second;
        }
        for (int i = 1; i <= ky; i ++ ) {
            auto t = ops[kx + i - 1];
            b[t.first] = t.second;
        }
    }
    return 0;
}