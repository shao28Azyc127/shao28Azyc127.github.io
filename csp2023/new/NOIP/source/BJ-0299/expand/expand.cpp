#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 10;
int C, n, m, q, x[N], y[N], a[N], b[N];

signed main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0);
    cin >> C >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> x[i], a[i] = x[i];
    for(int i = 1; i <= m; i++) cin >> y[i], b[i] = y[i];
    cout << ((x[1] - y[1]) * (x[n] - y[m]) > 0);
    while(q--) {
        int kx, ky; cin >> kx >> ky;
        while(kx--) {
            int p, v; cin >> p >> v;
            x[p] = v;
        }
        while(ky--) {
            int p, v; cin >> p >> v;
            y[p] = v;
        }
        // cout << "||||||\n";
        // for(int i = 1; i <= n; i++) cout << x[i] << ' '; cout << endl;
        // for(int i = 1; i <= m; i++) cout << y[i] << ' '; cout << endl;
        cout << ((x[1] - y[1]) * (x[n] - y[m]) > 0);
        for(int i = 1; i <= n; i++) x[i] = a[i];
        for(int i = 1; i <= m; i++) y[i] = b[i];
    }
    cout << '\n';
    return 0;
}