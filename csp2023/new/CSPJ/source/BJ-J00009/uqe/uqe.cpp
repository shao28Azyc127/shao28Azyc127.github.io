#include <bits/stdc++.h>

using namespace std;

int T;
int M;

int gcd(int x, int y) {
    return (x % y == 0 ? y : gcd(y, x % y));
}

void print(int x, int y) {
    if (gcd(x, y) == y) {
        cout << x / y ;
    } else {
        if (y / gcd(x, y) > 0) {
            cout << x / gcd(x, y) << '/' << y / gcd(x, y) ;
        } else {
            cout << -x / gcd(x, y) << '/' << -y / gcd(x, y) ;
        }
    }
}

void work() {
    double a, b, c;

    cin >> a >> b >> c ;

    int t = b * b - 4 * a * c;

    if (t < 0) {
        cout << "NO" ;
        cout << '\n' ;

        return ;
    }

    if (t == 0) {
        print(-b, 2 * a);
        cout << '\n' ;

        return ;
    }

    if (sqrt(t) == int(sqrt(t))) {
        if (a > 0) {
            print(max(-b + sqrt(t), -b - sqrt(t)), 2 * a);
        } else {
            print(min(-b + sqrt(t), -b - sqrt(t)), 2 * a);
        }

        cout << '\n' ;

        return ;
    }

    if (b != 0) {
        print(-b, 2 * a);
        cout << '+' ;
    }

    if (a < 0) {
        a = -a;
    }
    int q2 = 1;
    int t2 = sqrt(t);
    for (int i = 2; i <= t2; i++) {
        while (int(1.0 * t / i / i) == 1.0 * t / i / i) {
            q2 *= i;
            t /= i * i;
        }
    }
    if (gcd(q2, 2 * a) != 1) {
        int t3 = gcd(q2, 2 * a);
        q2 /= t3;
        a /= t3;
    }
    if (q2 != 1) {
        cout << q2 << '*' ;
    }
    if (t != 1) {
        cout << "sqrt(" << t << ")" ;
    }
    if (2 * a != 1) {
        cout << '/' << 2 * a ;
    }
    cout << '\n' ;
    return ;
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    cin >> T >> M ;

    while (T--) {
        work();
    }

    return 0;
}
