#include<bits/stdc++.h>

using namespace std;

int c, n, m, q;
long long xmin = 0x3f;
long long xmax = -1;
long long x[500010], y[500010], z[500010];
int kx[65], ky[65];
int px[65][500010], py[65][500010];
long long vx[65][500010], vy[65][500010];

void sin() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    sin();
    cin >> c >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        z[i] = x[i];
    }
    sort(z, z + n + 1);
    xmax = z[n];
    xmin = z[1];
    for(int i = 1; i <= m; i++) {
        cin >> y[i];
    }
    for(int i = 1; i <= q; i++) {
        cin >> kx[i] >> ky[i];
        for(int j = 1; j <= kx[i]; j++) {
            cin >> px[q][j] >> vx[q][j];
        }
        for(int j = 1; j <= ky[i]; j++) {
            cin >> py[q][j] >> vy[q][j];
        }
    }

    if(c == 1) {
        if(x[1] == y[1]) cout << "0";
        if(x[1] != y[1]) cout << "1";
        for(int i = 1; i <= q; i++) {
            for(int j = 1; j <= kx[i]; j++) {
                x[1] = vx[i][j];
            }
            for(int j = 1; j <= ky[i]; j++) {
                y[1] = vy[i][j];
            }
            if(x[1] == y[1]) cout << "0";
            if(x[1] != y[1]) cout << "1";
        }
    }

    if(c > 1 && c <= 4) {
        if(xmin > y[1] || xmax < y[1]) cout << "1";
        else cout << "0";
        for(int i = 1; i <= q; i++) {
            for(int j = 1; j <= kx[i]; j++) {
                if(x[px[i][j]] == xmax) {
                    x[px[i][j]] = vx[i][j];
                    z[n] = vx[i][j];
                    sort(z, z + n + 1);
                    xmax = z[n];
                }
                else if(x[px[i][j]] == xmin) {
                    x[px[i][j]] = vx[i][j];
                    z[1] = vx[i][j];
                    sort(z, z + n + 1);
                    xmin = z[1];
                }
                else {
                    x[px[i][j]] = vx[i][j];
                    for(int k = 1; k <= n; k++) {
                        z[k] = x[k];
                    }
                    sort(z, z + n + 1);
                    xmax = max(xmax, vx[i][j]);
                    xmin = min(xmin, vx[i][j]);
                }
            }
            for(int j = 1; j <= ky[i]; j++) {
                y[1] = vy[i][j];
            }
            if(xmin > y[1] || xmax < y[1]) cout << "1";
            else cout << "0";
        }
    }
    return 0;
}