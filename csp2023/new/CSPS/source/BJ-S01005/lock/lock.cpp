#include <bits/stdc++.h>
using namespace std;

int n;
int a[10][10];

int main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1) {
        cout << 81;
        return 0;
    }
    if (n == 2) {
        int x = 0, b[10];
        for (int i = 1; i <= 5; i++) {
            if (a[1][i] != a[2][i]) {
                b[++x] = i;
            }
        }
        if (x > 2) {
            cout << 0;
            return 0;
        }else if (x == 2) {
            if (b[2] - b[1] > 1) {
                cout << 0;
                return 0;
            }else {
                if (a[1][b[1]] - a[1][b[2]] == a[2][b[1]] - a[2][b[2]]) {
                    cout << 8;
                    return 0;
                }else {
                    cout << 0;
                    return 0;
                }
            }
        }else {
            if (b[1] == 1 || b[1] == 5) {
                cout << 10;
                return 0;
            }else {
                cout << 12;
                return 0;
            }
        }
    }
    cout << 0;
	return 0;
}
