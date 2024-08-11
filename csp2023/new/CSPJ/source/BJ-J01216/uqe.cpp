#include <bits/stdc++.h>
using namespace std;
int a,b,c,T,M;
int gcd(int x,int y) {
    x = x % y;
    if (x == 0) {
        return abs(y);
    } else {
        return gcd(y,x);
    }
}
void r () {
cin >> a >> b >> c;
    int dt = b * b - 4 * a * c;
    a *= 2;
    if (dt < 0) {
        cout << "NO";
        return;
    }
    if (int(sqrt(dt)) * int(sqrt(dt)) == dt) {
        int ans = -b + sqrt(dt);
        if (a < 0) {
            a *= -1;
            ans *= -1;
        }
        int g = gcd(ans,a);
        a /= g;
        ans /= g;
        cout << ans;
        if (a != 1) {
            cout << '/' << a;
        }
        return;
    }
    if (b == 0) {
        int C = 1,D = a;
        for (int i = 2;i * i <= dt;i++) {
            while (dt % (i * i) == 0) {
                dt /= i * i;
                C *= i;
            }
        }
        int g = gcd(C,D);
        C /= g;
        D /= g;
        if (C != 1) {
            cout << C << '*';
        }
        cout << "sqrt(" << dt << ')';
        if (abs(D) != 1) {
            cout << '/' << D;
        }
        return;
    }
    if (a < 0) {
        b *= -1;
    }
    int g = gcd(-b,a);
    cout << -b / g;
    if (abs(a / g) != 1) {
        cout << '/' << abs(a) / g;
    }
    cout << '+';
    int C = 1,D = a;
    for (int i = 2;i * i <= dt;i++) {
        while (dt % (i * i) == 0) {
            dt /= i * i;
            C *= i;
        }
    }
    g = gcd(C,D);
    C /= g,D /= g;
    if (C != 1) {
        cout << C << '*';
    }
    cout << "sqrt(" << dt << ')';
    if (abs(D) != 1) {
        cout << '/' << D;
    }
    return;
}
int main () {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> T >> M;
    while (T--) {
        r();
        cout << endl;
    }
    return 0;
}
