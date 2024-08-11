#include <bits/stdc++.h>
using namespace std;

long long n, b, a;

int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    for (long long i = 1; n > 0; i++) {
        if (n % 3 == 1 && a == 0) {
            a = i;
        }
        b = i;
        n -= (n + 2) / 3;
    }
    cout << b << " " << a;
    return 0;
}
