

#include <iostream>
#include <vector>

using namespace std;

int _n, _a[9][9], _r[9], _res;
int _l1, _l2, _lst;

void Search (int x) {
    if (x == 6) {
        for (int i = 1; i <= _n; i++) {
            _lst = 0;

            for (int j = 1; j <= 5; j++) {
                if (_a[i][j] != _r[j]) {
                    if (_lst == 0) {
                        _l1 = _a[i][j];
                        _l2 = _r[j];
                        _lst = j;
                    }

                    else if (_lst == -1) {
                        return ;
                    }

                    else {
                        if (_lst == j - 1) {
                            if (_a[i][j] - _l1 == _r[j] - _l2 || _a[i][j] - _l1 + 10 == _r[j] - _l2 || _a[i][j] - _l1 - 10 == _r[j] - _l2) {
                                _lst = -1;
                            }

                            else {
                                return ;
                            }
                        }

                        else {
                            return ;
                        }
                    }
                }
            }

            if (!_lst) {
                return ;
            }
        }

        _res++;

        /*

        for (int i = 1; i <= 5; i++) {
            cerr << _r[i] << ' ';
        }

        cerr << endl;

        */

        return ;
    }

    for (int i = 0; i <= 9; i++) {
        _r[x] = i;
        Search(x + 1);
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> _n;

    for (int i = 1; i <= _n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> _a[i][j];
        }
    }

    Search(1);

    cout << _res << endl;

    return 0;
}
