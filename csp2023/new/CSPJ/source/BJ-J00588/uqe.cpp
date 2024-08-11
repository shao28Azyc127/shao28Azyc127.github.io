#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int x, int y) {
    while (y != 0) {
        int mod = x % y;
        x = y;
        y = mod;
    }
    return x;
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, M;
    cin >> T >> M;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < 0) {
            a *= -1;
            b *= -1;
            c *= -1;
        }
        int delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "NO" << endl;
            continue;
        }
        int q = -1;
        for (int i = 0; i * i <= delta; i++) {
            if (i * i == delta) {
                q = i;
                break;
            }
        }
        if (q >= 0) {
            //output (-b+sqrt(delta))/2a
            int x = -b + q, y = 2 * a;
            int cnt = 0;
            if (x < 0) {
                cnt++;
                x *= -1;
            }
            if (y < 0) {
                cnt++;
                y *= -1;
            }
            int d = gcd(x, y);
            x /= d;
            y /= d;
            if (cnt & 1) cout << "-";
            if (y == 1) cout << x << endl;
            else cout << x << "/" << y << endl;
        }
        else {//q=-1
            int x = -b, y = 2 * a;
            int cnt = 0;
            if (x < 0) {
                cnt++;
                x *= -1;
            }
            if (y < 0) {
                cnt++;
                y *= -1;
            }
            int d = gcd(x, y);
            x /= d;
            y /= d;
            if (x != 0) {
                if (cnt & 1) cout << "-";
                if (y == 1) cout << x << "+";
                else cout << x << "/" << y << "+";
            }

            int p = 1, r = -1;//delta = p^2*r
            for (int i = 2; i * i <= delta; i++) {
                if (delta % (i * i) == 0) {
                    p = i;
                }
            }
            r = delta / (p * p);

            int z = 2 * a;
            int d2 = gcd(p, z);
            p /= d2;
            z /= d2;
            if (p == 1 && z == 1) cout << "sqrt(" << r << ")" << endl;
            else if (p != 1 && z == 1) cout << p << "*sqrt(" << r << ")" << endl;
            else if (p == 1 && z != 1) cout << "sqrt(" << r << ")/" << z << endl;
            else if (p != 1 && z != 1) cout << p << "*sqrt(" << r << ")/" << z << endl;
        }
    }
    return 0;
}
