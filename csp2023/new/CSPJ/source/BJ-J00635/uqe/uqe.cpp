#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// BJ-J00635 uqe.cpp
// can not be changed now.
// The test 1,2 are WA, limit can not run.

int bc, cs;

int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0) return i;
    }
    return 1;
}

void fs(double d) {
    double d2 = abs(d);
    int cnt = 1;
    while (d2 != (int)d2) {
        cnt *= 10;
        d2 *= 10;
    }
    int gc = gcd((int)d2, cnt);
    bc = d2 / gc;
    cs = cnt / gc;
    return;
}

int main() {

    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    int t, m;
    cin >> t >> m;
    while (t--) {
        double a, b, c;
        cin >> a >> b >> c;
        double tr = (b * b) - (4 * a * c);
        if (tr < 0) {
            cout << "NO" << endl;
            continue;
        }
        double n1 = (-b + sqrt(tr)) / (2 * a), n2 = (-b - sqrt(tr)) / (2 * a);
        double x = max(n1, n2);
        if (x == (int)x) cout << x;
        else {
            if (x < 0) cout << '-';
            fs(x);
            cout << bc;
            if (cs != 1) cout << '/' << cs;
        }
        cout << endl;
    }
    return 0;
}
