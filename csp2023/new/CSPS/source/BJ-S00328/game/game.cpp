

#include <iostream>

using namespace std;

int _n, _f[809][809], _res;
char _s[809];

int main () {
    int r;

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> _n >> (_s + 1);

    for (int i = 1; i < _n; i++) {
        if (_s[i] == _s[i + 1]) {
            _f[i][i + 1] = 1;
        }
    }

    for (int len = 4; len <= _n; len++) {
        for (int l = 1; l + len - 1 <= _n; l++) {
            r = l + len - 1;

            if (_s[l] != _s[r]) {
                continue;
            }

            _f[l][r] = _f[l + 1][r - 1];

            for (int k = l + 2; k < r - 1; k++) {
                _f[l][r] += _f[l + 1][k] * _f[k + 1][r - 1];
            }
        }
    }

    for (int i = 1; i <= _n; i++) {
        for (int j = i + 1; j <= _n; j++) {
            if (_f[i][j]) {
                _res++;
            }

            for (int k = i + 1; k < j; k++) {
                if (_f[i][k] && _f[k + 1][j]) {
                    _res++;
                    break;
                }
            }
        }
    }

    cout << _res << endl;

    return 0;
}
