#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int k[10][5];
    int n;
    cin >> n;
    if (n == 1) {
        cout << 81 << endl;
        return 0;
    }
    int dif = 0;
    int last = -2;
    bool connect = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++)
            cin >> k[i][j];
    }
    for (int i = 0; i < 5; i++) {
        int now = k[1][i];
        for (int j = 2; j <= n; j++) {
            if (k[j][i] != now) {
                if (i - last == 1) connect = true;
                dif++;
                last = i;
                break;
            }
        }
    }
    if (dif > 2) {
        cout << 1 << endl;
        return 0;
    }
    if (dif == 1) {
        cout << 10 << endl;
        return 0;
    }
    if (connect) {
        cout << 10 << endl;
    } else cout << 2 << endl;
    return 0;
}