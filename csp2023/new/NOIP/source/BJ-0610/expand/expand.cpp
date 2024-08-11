#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;

#define int long long

const int maxn = 5e5 + 10;
int c, n, m, q;
int kx, ky;
int x[maxn];
int y[maxn];

bool check() {
    if (n == m && n == 1) {
        if (x[1] != y[1]) {
            return 1;
        }
    }
    bool flag = true;
    for (int i = 1;i <= max(n, m);i++) {
        if (x[i] >= y[i]) {
            flag = false;
        }
    }
    if (flag) return 1;
    int xmax = INT_MIN, ymin = INT_MAX;
    int xmin = x[n], ymax = y[m];
    for (int i = 1;i <= max(n, m);i++) {
        if (i <= n) xmax = max(xmax, x[i]);
        if (xmax > ymax) return 0;
    }
    return 1;
}

signed main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> c >> n >> m >> q;
    for (int i = 1;i <= n;i++) {
        cin >> x[i];
    }
    for (int i = 1;i <= m;i++) {
        cin >> y[i];
    }
    cout << check();
    while (q--) {
        cin >> kx >> ky;
        for (int i = 1;i <= kx;i++) {
            int id, v;
            cin >> id >> v;
            x[id] = v;
        }
        for (int i = 1;i <= ky;i++) {
            int id, v;
            cin >> id >> v;
            y[id] = v;
        }
        cout << check();
    }
    return 0;
}
