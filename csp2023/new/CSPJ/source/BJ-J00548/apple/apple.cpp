// Wish my son recovering soon!

#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, tot = 0, day = 0;
    cin >> n;
    while (n) {
        ++tot;
        if (day == 0 && n % 3 == 1) day = tot;
        n -= (n + 2) / 3;
    }
    cout << tot << ' ' << day << '\n';
    return 0;
}
