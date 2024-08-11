

#include <iostream>

using namespace std;

int _n, _m;
int _cnt[3009][29];

int main () {
    char ch;
    bool fl;
    int p1, p2;

    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    cin >> _n >> _m;

    for (int i = 1; i <= _n; i++) {
        for (int j = 1; j <= _m; j++) {
            cin >> ch;
            _cnt[i][ch - 'a']++;
        }
    }

    for (int i = 1; i <= _n; i++) {
        fl = 1;

        for (int j = 1; j <= _n; j++) {
            if (i == j) {
                continue;
            }

            p1 = 0;
            p2 = 25;

            while (!_cnt[i][p1]) {
                p1++;
            }

            while (!_cnt[j][p2]) {
                p2--;
            }

            if (p1 >= p2) {
                fl = 0;
                break;
            }
        }

        if (fl) {
            cout << 1;
        }

        else {
            cout << 0;
        }
    }

    cout << endl;

    return 0;
}
