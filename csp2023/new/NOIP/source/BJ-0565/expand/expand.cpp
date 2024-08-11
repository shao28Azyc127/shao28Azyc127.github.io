#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define print1(x) cout << x << endl;
#define print2(x, y) cout << x << ' ' << y << endl;
#define print3(x, y, z) cout << x << ' ' << y << ' ' << z << endl;
using namespace std;

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    int c, n, m, q;
    cin >> c >> n >> m >> q;
    vector<int> XR(n), YR(m);
    for (int i = 0; i < n; i++) cin >> XR[i];
    for (int i = 0; i < m; i++) cin >> YR[i];

    vector<int> X(XR), Y(YR);
    // for (int i: X) cout << i << ' ';
    // cout << endl;
    // for (int i: Y) cout << i << ' ';
    for (int _ = 0; _ < q + 1; _++) {
        X = XR;
        Y = YR;
        if (_ != 0) {
            int kx, ky;
            cin >> kx >> ky;
            for (int __ = 0; __ < kx; __++) {
                int p, v;
                cin >> p >> v;
                X[p - 1] = v;
            }
            for (int __ = 0; __ < ky; __++) {
                int p, v;
                cin >> p >> v;
                Y[p - 1] = v;
            }
        }
    //         for (int i: X) cout << i << ' ';
    // cout << endl;
    // for (int i: Y) cout << i << ' ';
    //   cout << endl;
        if ((X[0] - Y[0]) * (X[n - 1] - Y[m - 1]) <= 0) {
            cout << 0;
            continue;
        }
        cout << 1;
    }

    return 0;
}