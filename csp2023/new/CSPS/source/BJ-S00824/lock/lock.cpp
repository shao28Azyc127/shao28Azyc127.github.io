#include <bits/stdc++.h>
using namespace std;
int n, a[10], b[10], c[10], d[10], e[10];
bool one_time(int a1, int a2, int a3, int a4, int a5, int k) {
    int b1 = a1 - a[k], b2 = a2 - b[k], b3 = a3 - c[k], b4 = a4 - d[k], b5 = a5 - e[k];
    if (b1 < 0) b1 += 10;
    if (b2 < 0) b2 += 10;
    if (b3 < 0) b3 += 10;
    if (b4 < 0) b4 += 10;
    if (b5 < 0) b5 += 10;

    if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0) return false;

    if (b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0) return true;
    if (b1 == 0 && b3 == 0 && b4 == 0 && b5 == 0) return true;
    if (b1 == 0 && b2 == 0 && b4 == 0 && b5 == 0) return true;
    if (b1 == 0 && b2 == 0 && b3 == 0 && b5 == 0) return true;
    if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0) return true;

    if (b3 == 0 && b4 == 0 && b5 == 0 && b1 == b2) return true;
    if (b1 == 0 && b4 == 0 && b5 == 0 && b2 == b3) return true;
    if (b1 == 0 && b2 == 0 && b5 == 0 && b3 == b4) return true;
    if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == b5) return true;
    return false;
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    }
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                for (int l = 0; l < 10; l++) {
                    for (int m = 0; m < 10; m++) {
                        bool tf = true;
                        for (int t = 1; t <= n; t++) {
                            if (!one_time(i, j, k, l, m, t)) tf = false;
                        }
                        if (tf == true) cnt++;
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
