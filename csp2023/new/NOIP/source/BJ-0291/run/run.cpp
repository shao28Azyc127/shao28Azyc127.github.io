

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int _n, _m, _k, _d;
long long _f[1009][1009], _res;
vector<pair<int, int> > _a[1009];

int main () {
    int C, T;
    int x, y, v;
    int p;
    long long cc;

    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    cin >> C >> T;

    while (T--) {
        cin >> _n >> _m >> _k >> _d;

        for (int i = 1; i <= _m; i++) {
            cin >> x >> y >> v;
            _a[x].push_back(make_pair(y, v));
        }

        for (int i = 0; i <= _n; i++) {
            for (int j = 0; j <= _n; j++) {
                _f[i][j] = -1000000000000000009;
            }
        }

        _f[0][0] = 0;

        for (int i = 1; i <= _n; i++) {
            sort(_a[i].begin(), _a[i].end());

            p = 0;

            for (int j = 0; j <= _k; j++) {
                _f[i][0] = max(_f[i][0], _f[i - 1][j]);
            }

            cc = 0;

            for (int j = 1; j <= min(_k, i); j++) {
                while (p < _a[i].size() && _a[i][p].first == j) {
                    cc += _a[i][p].second;
                    p++;
                }

                _f[i][j] = _f[i - 1][j - 1] - _d + cc;
            }
        }

        _res = -1000000000000000009;

        for (int i = 0; i <= _k; i++) {
            _res = max(_res, _f[_n][i]);
        }

        cout << _res << endl;

        for (int i = 1; i <= _n; i++) {
            _a[i].clear();
        }
    }

    return 0;
}
