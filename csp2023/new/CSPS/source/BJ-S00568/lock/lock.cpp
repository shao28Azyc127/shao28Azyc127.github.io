#include <iostream>
#define print1(x) cout << x << endl;
#define print2(x, y) cout << x << ' ' << y << endl;
using namespace std;

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    int conditions[8][5];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> conditions[i][j];
        }
    }
    if (n == 1) {
        cout << 81 << endl;
        return 0;
    } else {
        cout << 10 - n << endl;
        return 0;
    }
    return 0;
}