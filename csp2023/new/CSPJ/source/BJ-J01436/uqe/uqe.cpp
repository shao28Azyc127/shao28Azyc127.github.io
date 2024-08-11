#include <bits/stdc++.h>
using namespace std;

int t, m, a, b, c, x, y, z;

int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}

int main() {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    while (t--) {
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0) {
            cout << "NO" << endl;
            continue;
        }
        if (c == 0) {
            if (b > 0) {
                cout << "-";
            }else {
                b = -b;
            }
            if (b % a == 0) {
                cout << b / a << endl;
            }else {
                cout << b << "/" << a << endl;
            }
        }else if (b == 0) {
            if (a > 0) {
                c = -c;
            }else {
                a = -a;
            }
            if (sqrt(a * c) != int(sqrt(a * c))) {
                x = a * c, y = 1;
                for (int i = 2; i * i < x; i++) {
                    if (x % (i * i) == 0) {
                        x /= i * i;
                        y *= i;
                        i--;
                    }
                }
                if (y % a == 0) {
                    y = y / a;
                    if (y == 1) {
                        cout << "sqrt(" << x << ")" << endl;
                    }else {
                        cout << y << "*sqrt(" << x << ")" << endl;
                    }
                }else if (a % y == 0) {
                    cout << "sqrt(" << x << ")/" << a / y << endl;
                }else {
                    z = gcd(y, a);
                    cout << y / z << "*sqrt(" << x / z << ")" << endl;
                }
            }else {
                x = sqrt(a * c);
                if (x == a) {
                    cout << 1 << endl;
                }else if (x % a == 0) {
                    cout << x / a << endl;
                }else {
                    z = gcd(a, x);
                    cout << x / z << "/" << a / z << endl;
                }
            }
        }else {
            cout << int(-b + sqrt(b * b - 4 * a * c)) / 2 / a << endl;
        }
    }
    return 0;
}
