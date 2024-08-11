#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long T, M, a, b, c;
long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
long long max(long long x, long long y) {return x > y ? x : y;}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    while (T--) {
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0) {cout << "NO\n"; continue;}
        long long delta = b * b - 4 * a * c;
        if (delta == 0 || (long long)(sqrt(delta)) * (long long)(sqrt(delta)) == delta) {
            long long xa = sqrt(delta) - b, xb = 2 * a;
            long long xgcd = gcd(abs(xa), abs(xb)); xa /= xgcd; xb /= xgcd;
            if (xb != 1) cout << xa << '/' << xb << endl;
            else cout << xa << endl;
            continue;
        }
        long long q1a = -b, q1b = 2 * a, q2a = 1, q2b = 2 * a;
        long long q1gcd = gcd(abs(q1a), abs(q1b)); q1a /= q1gcd; q1b /= q1gcd;
        for (long long i = 2; i * i <= delta; ++i)
            if (delta % (i * i) == 0)
                delta /= i * i, q2a *= i;
        // cout << delta << endl;
        long long q2gcd = gcd(abs(q2a), abs(q2b)); q2a /= q2gcd; q2b /= q2gcd;
        if (q1a != 0) {
            if (q1b > 1) cout << q1a << '/' << q1b << '+';
            else cout << q1a << '+';
        }
        if (q2a == 1 && q2b == 1) cout << "sqrt(" << delta << ")\n";
        else if (q2b == 1) cout << q2a << "*sqrt(" << delta << ")\n";
        else if (q2a == 1) cout << "sqrt(" << delta << ")/" << q2b << endl;
        else cout << q2a << "*sqrt(" << delta << ")/" << q2b << endl;
        // sqrt(delta) * q2 + b * 1/2 * 1/a
    }
    return 0;
}
