#include <bits/stdc++.h>
using namespace std;
int n, ans;
int i;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    for (i = 1; n; i++) {
        if ((n - 1) % 3 == 0 && ans == 0) {
            ans = i;
        }
        n -= 1 + (n - 1) / 3;
    }
    cout << i - 1 << " " << ans;
    return 0;
}