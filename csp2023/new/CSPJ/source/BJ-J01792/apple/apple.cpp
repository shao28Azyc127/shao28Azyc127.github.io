#include <iostream>
using namespace std;
int n, r1, r2;
int main() {
    ios::sync_with_stdio(false);
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    for (; n; n -= (n + 2) / 3) {
        ++r1;
        if (!r2 && n % 3 == 1) r2 = r1;
    }
    cout << r1 << ' ' << r2 << '\n';
    return 0;
}