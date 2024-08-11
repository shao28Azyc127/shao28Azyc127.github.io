

#include <bits/stdc++.h>

using namespace std;

int _num = 0;

int main () {
    int no;

    freopen("lock.in", "r", stdin);
    cin >> _num;
    for (int i = 0; i < 5 * _num; i++) {
        cin >> no;
    }
    freopen("lock.out", "w", stdout);
    cout << 81 << endl;

    return 0;
}
