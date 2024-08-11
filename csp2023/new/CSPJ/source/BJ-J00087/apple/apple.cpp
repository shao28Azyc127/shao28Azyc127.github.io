#include <bits/stdc++.h>

using namespace std;

long long n, t = 1, s1, s2;

int main () {

    freopen ("apple.in", "r", stdin);
    freopen ("apple.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while (n > 0) {
        s1++;
        if (s2 == 0 && (n - 1) % 3 == 0)
            s2 = s1;
        if (n % 3 == 1) {
            n += 2;
            n -= n / 3;
            n -= 2;
        }
        else if (n % 3 == 2) {
            n += 1;
            n -= n / 3;
            n -= 1;
        }
        else n -= n / 3;
    }

    cout << s1 << " " << s2;

    return 0;
}
