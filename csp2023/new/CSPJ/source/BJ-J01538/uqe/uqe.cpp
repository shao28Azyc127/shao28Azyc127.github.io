#include <bits/stdc++.h>
using namespace std;
int checkGcd(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            return x / i;
        }
    }
    return 0;
}
int gcd(int a, int b) {
    int res = 1;
    for(int i = 2; i * 2 <= min(a, b); i++) {
        if(a % i == 0 && b % i == 0) {
            res = i;
        }
    }
    return res;
}
int check(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(i * i == x) {
            return i;
        }
    }
    return 1;
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int a, b, c;
    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        int der = b * b - 4 * a * c;
        if(der < 0) {
            cout << "NO" << endl;
            continue;
        }else if(der = 0) {
            if(-b % (2 * a) != 0) {
                int g = gcd(-b, 2 * a);
                b = -b / g;
                a = 2 * a / g;
                cout << b << "/" << a << endl;
            }else{
                cout << -b / (2 * a) << endl;
            }
        }else{
            int x = 0, y = 0, k = 0, s = 0;
            int g1 = 0;
            if(-b % (2 * a) != 0) {
                g1 = gcd(-b, 2 * a);
                x = -b / g1;
                y = 2 * a / g1;
            }else{
                x = -b / (2 * a);
            }
            if(check(der) != 1) {
                if(check(der) % (2 * a) == 0) {
                    k = check(der) / (2 * a);
                }
                else{
                    g1 = gcd(check(der), 2 * a);
                    k = check(der) / g1;
                    s = 2 * a / g1;
                }
            }else{
                if(checkGcd(der) % 2 * a == 0) {
                    k = checkGcd(der) / (2 * a);
                }else{
                    g1 = gcd(checkGcd(der), 2 * a);
                    k = checkGcd(der) / g1;
                    s = 2 * a / g1;
                }
                int der1 = der / checkGcd(der);
            }
            if(y == 0) {
                if(s == 0) {
                    if(check(der) != 1) {
                        cout << x << "+" << k << endl;
                    }else{
                        cout << x << "+" << k << "*" << "sqrt(" << der1 << ")" << endl;
                    }
                }else{
                    if(check(der) != 1) {
                        cout << x << "+" << k << "/" << s << endl;
                    }else{
                        cout << x << "+" << k << "*" << "sqrt(" << der1 << ")" << "/" << s << endl;
                    }
                }
            }else{
                if(s == 0) {
                    if(check(der) != 1) {
                        cout << x << "/" << y << "+" << k << endl;
                    }else{
                        cout << x << "/" << "+" << k << "*" << "sqrt(" << der1 << ")" << endl;
                    }
                }else{
                    if(check(der) != 1) {
                        cout << x << "/" << y << "+" << k << "/" << s << endl;
                    }else{
                        cout << x << "/" << y << "+" << k << "*" << "sqrt(" << der1 << ")" << "/" << s << endl;
                    }
                }
            }
        }
    }
    return 0

}
