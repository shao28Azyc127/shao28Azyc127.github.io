#include <iostream>
#include <cmath>
using namespace std;
int t, m, a, b, c;
int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
void solve(int &a, int &b) {
    int g = gcd(a, b);
    a /= g; b /= g;
    if (b < 0) a = -a, b = -b;
}
int main() {
    ios::sync_with_stdio(false);
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while (t--) {
        cin >> a >> b >> c; int d = b * b - 4 * a * c;
        if (d < 0) {cout << "NO\n"; continue;}
        int sq = sqrtl(d) + 3;
        while (sq * sq > d) --sq;
        if (sq * sq == d) {
            int p1 = -b - sq, p2 = -b + sq, q = 2 * a;
            int p = (long double)p1 / q > (long double)p2 / q ? p1 : p2;
            solve(p, q);
            if (q == 1) cout << p << '\n';
            else cout << p << '/' << q << '\n';
        } else {
            int mul = 1;
            for (int i = sq; i > 1; i--) 
                if (d % (i * i) == 0) {mul = i; d /= i * i; break;}
            int p1 = -b, p2 = mul, q1 = 2 * a, q2 = 2 * a;
            if (p1 != 0) {
                solve(p1, q1);
                if (q1 == 1) cout << p1 << '+';
                else cout << p1 << '/' << q1 << '+';
            }
            solve(p2, q2);
            if (p2 != 1 && p2 != -1) cout << max(p2, -p2) << '*';
            cout << "sqrt(" << d << ")";
            if (q2 != 1) cout << '/' << q2;
            cout << '\n';
        } 
    }
    return 0;
}