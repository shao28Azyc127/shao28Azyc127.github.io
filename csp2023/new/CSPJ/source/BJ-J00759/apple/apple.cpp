#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n; cin >> n;
    int ans1 = 0, ans2 = -1;
    while (n) {
        ans1++;
        if (n % 3 == 1 && ans2 == -1) ans2 = ans1;
        n -= n / 3 + ((n % 3 != 0) ? 1 : 0);
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}