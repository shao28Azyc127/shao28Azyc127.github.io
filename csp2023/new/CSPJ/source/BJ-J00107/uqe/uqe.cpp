#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int t, m;
int a, b, c;
int dt = 0;
int p, q, p2, q2;
int tmp = 0;
int cnt = 0;
int tt;
int abs(int x) {
    if ( x < 0) {
        return -x;
    }
    else {
        return x;
    }
}
int gcd(int x, int y) {
    if ( x == 1 || y == 1) {
        return 1;
    }
    if ( x == y) {
        return x;
    }
    return gcd(max(x, y) - min(x, y), min(x, y));
}
void V(int x, int y) {
    cnt = 0;
    p = abs(y);
    q = abs(2 * x);
    if ( y >= 0) cnt++;
    if ( x >= 0) cnt++;
    tmp = gcd(p, q);
    p /= tmp;
    q /= tmp;
    if ( cnt % 2 == 0) {
        cout << "-";
    }
    cout << p;
    if ( q != 1) {
        cout << "/" << q;
    }
    return;
}
void V2(int x, int y, int z) {
    cnt = 0;
    if ( x >= 0) {
        p = abs(z - y);
        if ( z - y >= 0) cnt++;
    }
    else if ( x < 0) {
        p = abs(z + y);
        if ( 0 - z - y >= 0) cnt++;
    }
    q = abs(2 * x);
    tmp = gcd(p, q);
    p /= tmp;
    q /= tmp;
    
    if ( x >= 0) cnt++;
    if ( cnt % 2 == 1) {
        cout << "-";
    }
    cout << p;
    if ( q != 1) {
        cout << "/" << q;
    }
    return;
}
int sqr(int x) {
    int ans = 1;
    for ( int i = 1; i * i <= x; i++) {
        if ( x % ( i * i) == 0) {
            ans = i;
        }
    }
    return ans;
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while ( t--) {
        cin >> a >> b >> c;
        dt = b * b - ( 4 * a * c);
        if ( dt < 0) {
            cout << "NO" << endl;
            continue;
        }
        else if ( dt == 0) {
            if ( b == 0) {
                cout << 0;
            }
            else if ( b != 0) {
                V(a, b);
            }
            cout << endl;
        }
        else if ( dt > 0) {
            tt = sqr(dt);
            if ( tt * tt < dt) {
                if ( b != 0) {
                    V(a, b);
                    cout << "+";
                }
                p = tt;
                q = abs(2 * a);
                tmp = gcd(p, q);
                p /= tmp;
                q /= tmp;
                if ( p != 1) cout << p << "*";
                cout << "sqrt(" << dt / (tt * tt) << ")";
                if ( q != 1) cout << "/" << q;
            }
            else if ( tt * tt == dt) {
                if ( a > 0 && tt - b == 0)  {
                    cout << 0;
                }
                else if ( a < 0 && tt + b == 0) {
                    cout << 0;
                }
                else {
                    V2(a, b, tt);
                }
            }
            cout << endl;
        }
    }
    return 0;
}