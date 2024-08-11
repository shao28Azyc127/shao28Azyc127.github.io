#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

signed main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 0, x = 0;
    bool flag = false;
    while (n > 0) {
        ++cnt;
        if (n % 3 == 1 && !flag) {
            x = cnt;
            flag = true;
        }
        if (n % 3 == 0) n -= n / 3;
        else n -= (n / 3 + 1);
    }
    cout << cnt << ' ' << x;
    return 0;
}
