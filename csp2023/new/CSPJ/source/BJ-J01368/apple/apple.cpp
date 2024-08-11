#include <bits/stdc++.h>
using namespace std;
int n = 0, ans = 0, cnt = 0;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    int n1 = n;
    while (n1)
        if (n1 % 3 == 1 && !ans) ans = cnt + 1;
        else n1 -= ceil(1.0 * n1 / 3), ++cnt;
    cout << cnt << " " << ans << endl;
    return 0;
}