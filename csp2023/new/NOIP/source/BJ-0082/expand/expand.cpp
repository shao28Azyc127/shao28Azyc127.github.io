#include <iostream>
#include <cstring>

using namespace std;

constexpr int N = 2005;

int x[N], y[N], x1[N], y1[N];
bool f[N][N], g[N][N];

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c, lx, ly, q;
    cin >> c >> lx >> ly >> q;
    do {
        for (int i = 1; i <= lx; i++)   cin >> x[i];
        for (int i = 1; i <= ly; i++)   cin >> y[i];
        if (x[1] == y[1]) {
            cout << '0';
            break;
        }
        f[1][1] = g[1][1] = false;
        if (x[1] > y[1])    f[1][1] = true;
        else                g[1][1] = true;
        for (int i = 1; i <= lx; i++) {
            for (int j = 1; j <= ly; j++) {
                if (i != 1 || j != 1)
                    f[i][j] = g[i][j] = false;
                if (x[i] > y[j])
                    f[i][j] |= f[i - 1][j - 1] || f[i - 1][j] || f[i][j - 1];
                else if (x[i] != y[j])
                    g[i][j] |= g[i - 1][j - 1] || g[i - 1][j] || g[i][j - 1];
                //f[i][j] &= (x[i] > y[j]);
                //g[i][j] &= (x[i] < y[j]);
                //cout << endl << i << ' ' << j << ' ' << f[i][j] << ' ' << g[i][j] << endl;
            }
        }
        if (f[lx][ly] || g[lx][ly])
            cout << '1';
        else
            cout << '0';
    } while (false);
    memcpy(x1, x, sizeof x);
    memcpy(y1, y, sizeof y);
    while (q--) {
        memcpy(x, x1, sizeof x);
        memcpy(y, y1, sizeof y);
        int kx, ky;
        cin >> kx >> ky;
        while (kx--) {
            int p, v;
            cin >> p >> v;
            x[p] = v;
        }
        while (ky--) {
            int p, v;
            cin >> p >> v;
            y[p] = v;
        }
        if (x[1] == y[1]) {
            cout << '0';
            continue;
        }
        f[1][1] = g[1][1] = false;
        if (x[1] > y[1])    f[1][1] = true;
        else                g[1][1] = true;
        for (int i = 1; i <= lx; i++) {
            for (int j = 1; j <= ly; j++) {
                if (i != 1 || j != 1)
                    f[i][j] = g[i][j] = false;
                if (x[i] > y[j])
                    f[i][j] |= f[i - 1][j - 1] || f[i - 1][j] || f[i][j - 1];
                else if (x[i] != y[j])
                    g[i][j] |= g[i - 1][j - 1] || g[i - 1][j] || g[i][j - 1];
                //f[i][j] &= (x[i] > y[j]);
                //g[i][j] &= (x[i] < y[j]);
                //cout << endl << i << ' ' << j << ' ' << f[i][j] << ' ' << g[i][j] << endl;
            }
        }
        if (f[lx][ly] || g[lx][ly])
            cout << '1';
        else
            cout << '0';
    }
    cout << '\n';
    return 0;
}
