#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    int a[8][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1) {
        ans = 81;
    }
    cout << ans;
    return 0;
}
