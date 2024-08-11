#include <bits/stdc++.h>
using namespace std;
long long a[10005] = {1}, n, I, tt, II;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= 33; i ++) a[i] = a[i - 1] * 3;
    int nn = n;
    while (n) {
        long long t = (n + 2) / 3;
        n -= t;
        I ++;
        
    }
    while (nn) {
        long long t = (nn + 2) / 3;
        if (nn % 3 == 1) {
            tt = II;
            break;
        }
        nn -= t;
        II ++;
        // if (nn % 3 == 1) {
        //     tt = II;
        //     break;
        // }
    }
    cout << I << " " << tt + 1;
    return 0;
}