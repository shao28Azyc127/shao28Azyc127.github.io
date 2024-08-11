

#include <iostream>

using namespace std;

int _c, _n, _m, _q;
int _x[2009], _y[2009], _xx[2009], _yy[2009];
int _f[2009][2009];

int main () {
    int kx, ky, p, q;

    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    cin >> _c >> _n >> _m >> _q;

    for (int i = 1; i <= _n; i++) {
        cin >> _x[i];
    }

    for (int i = 1; i <= _m; i++) {
        cin >> _y[i];
    }

    _f[0][0] = 1;

    if (_x[1] < _y[1]) {
        for (int i = 1; i <= _n; i++) {
            for (int j = 1; j <= _m; j++) {
                _f[i][j] = (_x[i] < _y[j]) && (_f[i - 1][j - 1] || _f[i][j - 1] || _f[i - 1][j]);
            }
        }

        if (_f[_n][_m]) {
            cout << 1;
        }

        else {
            cout << 0;
        }
    }

    else if (_x[1] > _y[1]) {
        for (int i = 1; i <= _n; i++) {
            for (int j = 1; j <= _m; j++) {
                _f[i][j] = (_x[i] > _y[j]) && (_f[i - 1][j - 1] || _f[i][j - 1] || _f[i - 1][j]);
            }
        }

        if (_f[_n][_m]) {
            cout << 1;
        }

        else {
            cout << 0;
        }
    }

    else {
        cout << 0;
    }

    for (int i = 1; i <= _q; i++) {
        for (int j = 1; j <= _n; j++) {
            _xx[j] = _x[j];
        }

        for (int j = 1; j <= _m; j++) {
            _yy[j] = _y[j];
        }

        cin >> kx >> ky;

        for (int j = 1; j <= kx; j++) {
            cin >> p >> q;
            _xx[p] = q;
        }

        for (int j = 1; j <= ky; j++) {
            cin >> p >> q;
            _yy[p] = q;
        }

        if (_xx[1] < _yy[1]) {
            for (int j = 1; j <= _n; j++) {
                for (int k = 1; k <= _m; k++) {
                    _f[j][k] = (_xx[j] < _yy[k]) && (_f[j - 1][k - 1] || _f[j][k - 1] || _f[j - 1][k]);
                }
            }

            if (_f[_n][_m]) {
                cout << 1;
            }

            else {
                cout << 0;
            }
        }

        else if (_xx[1] > _yy[1]) {
            for (int j = 1; j <= _n; j++) {
                for (int k = 1; k <= _m; k++) {
                    _f[j][k] = (_xx[j] > _yy[k]) && (_f[j - 1][k - 1] || _f[j][k - 1] || _f[j - 1][k]);
                }
            }

            if (_f[_n][_m]) {
                cout << 1;
            }

            else {
                cout << 0;
            }
        }

        else {
            cout << 0;
        }
    }

    cout << endl;

    return 0;
}
