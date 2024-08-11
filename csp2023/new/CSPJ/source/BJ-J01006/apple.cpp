#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, m;
    cin >> n;
    m = n;
    int ans = 0;
    while (m) {
        ans++;
        m -= (m - 1) / 3 + 1;
    }
    cout << ans << ' ';
    m = n, ans = 1;
    while (m % 3 != 1) {
        ans++;
        m -= (m - 1) / 3 + 1;
    }
    cout << ans;
    return 0;
}
