#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    int m = n, c = 0, d = 0;
    while(m > 0) {
        int t;
        if (m % 3 != 0) {
            t = m / 3 + 1;
            if (m % 3 == 1 && d == 0) d = c + 1;
        } else {
            t = m / 3;
        }
        m = m - t;
        c++;
    }

    cout << c << " " << d;
    return 0;
}
