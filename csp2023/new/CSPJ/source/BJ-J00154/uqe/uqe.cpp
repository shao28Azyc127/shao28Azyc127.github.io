#include <bits/stdc++.h>
using namespace std;
int T, m, a, b, c;
inline int Calc(int x) {
    for (int i = 3000; i >= 1; i--)
        if (x % (i * i) == 0)
            return i;
}
int mygcd(int x, int y) {
    if (y == 0) return x;
    return mygcd(y, x % y);
}
inline int outp(int x, int y) {
    return x / mygcd(abs(x), abs(y));
}
inline void output(int x, int y) {
    int p = outp(x, y), q = outp(y, x);
    if (q < 0) p = -p, q = -q;
    if (p == 0) cout << '0';
    else if (q == 1) cout << p;
    else cout << p << '/' << q;
}
int main(void) {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    cin >> T >> m;
    while (T--) {
        cin >> a >> b >> c;
        int delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "NO" << endl;
            continue;
        }
        int t = Calc(delta);
        delta /= (t * t);
        if (delta == 1) {
            if (a > 0)
                output(t - b, 2 * a);
            else
                output(t + b, -2 * a);
            cout << endl;
            continue;
        }

        if (delta == 0) {
            output(-b, 2 * a);
            cout << endl;
            continue;
        }
        if (b != 0) {
            output(-b, 2 * a);
            cout << '+';
        }


        if (t == abs(2 * a))
            cout << "sqrt(" << delta << ")" << endl;
        else if (t % (2 * a) == 0)
            cout << abs(t / a / 2) << "*sqrt(" << delta << ")" << endl;
        else if ((2 * a) % t == 0)
            cout << "sqrt(" << delta << ")/" << abs(2 * a / t) << endl;
        else
            cout << outp(t, abs(a * 2)) << "*sqrt(" << delta << ")/" << outp(abs(a * 2), t) << endl;
    }
    return 0;
}
