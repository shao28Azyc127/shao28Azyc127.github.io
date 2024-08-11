#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
const int N = 500010;
int c, n, m, q;
int x[N], y[N];
int stx[N][20], sty[N][20];

void build() {
    for (int i = 1; i <= n; i++) {
        stx[i][0] = x[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            stx[i][j] = max(stx[i][j - 1], stx[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        sty[i][0] = y[i];
    }
    for (int j = 1; (1 << j) <= m; j++) {
        for (int i = 1; i + (1 << j) - 1 <= m; i++) {
            sty[i][j] = max(sty[i][j - 1], sty[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int queryx(int l, int r) {
    int d = log2(l - r + 1);
    return max(stx[l][d], stx[r - (1 << d) + 1][d]);
}
int queryy(int l, int r) {
    int d = log2(l - r + 1);
    return max(sty[l][d], sty[r - (1 << d) + 1][d]);
}
bool check() {
    if (x[1] < y[1] && x[n] > y[n]) return false;
    if (x[1] > y[1] && x[n] < y[n]) return false;
    return true;
}
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> y[i];
    }
    build();
    cout << check();
    while (q--) {
        int kx, ky;
        cin >> kx >> ky;
        for (int i = 1; i <= kx; i++) {
            int p,v;
            cin >> p >> v; p++;
            x[p] = v;
        }
        for (int i = 1; i <= ky; i++) {
            int p,v;
            cin >> p >> v; p++;
            y[p] = v;
        }
        cout << check();
    }
    cout << endl;
    return 0;
}
