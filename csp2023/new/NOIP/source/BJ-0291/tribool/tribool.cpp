

#include <iostream>
#include <vector>

using namespace std;

int _n, _m, _res;
int _a[100009][2], _vis[100009], _cnt[100009];
vector<int> _e[100009];

int Search1 (int u) {
    if (u < 0) {
        return u;
    }

    else if (_vis[u] == -3) {
        return u;
    }

    else if (_vis[u] == 0) {
        _vis[u] = -3;
        _vis[u] = Search1(_a[u][1]);
        return _vis[u];
    }

    else {
        return _vis[u];
    }
}

void Search2 (int u, int rt, int cc, int st) {
    if (u == rt && st) {
        if (cc & 1) {
            _res += _cnt[rt];
        }

        return ;
    }

    Search2(_a[u][1], rt, cc + ((_a[u][0] < 0) ? 1 : 0), 1);
}

int main () {
    int C, T;
    char op;
    int x, y;

    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    cin >> C >> T;

    while (T--) {
        cin >> _n >> _m;

        for (int i = 1; i <= _n; i++) {
            _a[i][0] = 1;
            _a[i][1] = i;
        }

        for (int i = 1; i <= _m; i++) {
            cin >> op;

            if (op == '+') {
                cin >> x >> y;

                _a[x][0] = _a[y][0];
                _a[x][1] = _a[y][1];
            }

            else if (op == '-') {
                cin >> x >> y;

                _a[x][0] = -_a[y][0];
                _a[x][1] = _a[y][1];
            }

            else {
                cin >> x;

                if (op == 'T') {
                    _a[x][0] = 1;
                    _a[x][1] = -1;
                }

                else if (op == 'F') {
                    _a[x][0] = -1;
                    _a[x][1] = -1;
                }

                else {
                    _a[x][0] = 1;
                    _a[x][1] = -2;
                }
            }
        }

        /*

        for (int i = 1; i <= _n; i++) {
            cerr << _a[i][0] << ' ' << _a[i][1] << endl;
        }

        */

        for (int i = 1; i <= _n; i++) {
            _vis[i] = _cnt[i] = 0;
        }

        for (int i = 1; i <= _n; i++) {
            if (!_vis[i]) {
                _vis[i] = Search1(i);
            }
        }

        /*

        for (int i = 1; i <= _n; i++) {
            cerr << _vis[i] << ' ';
        }

        cerr << endl;

        */

        _res = 0;

        for (int i = 1; i <= _n; i++) {
            if (_vis[i] > 0) {
                _cnt[_vis[i]]++;
            }

            else if (_vis[i] == -2) {
                _res++;
            }
        }

        for (int i = 1; i <= _n; i++) {
            if (_cnt[i]) {
                Search2(i, i, 0, 0);
            }
        }

        cout << _res << endl;

        for (int i = 1; i <= _n; i++) {
            _e[i].clear();
        }
    }

    return 0;
}
