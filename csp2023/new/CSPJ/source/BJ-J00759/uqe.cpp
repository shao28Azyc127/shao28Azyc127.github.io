#include <iostream>
#include <cmath>
using namespace std;
int T; double M;
int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}
void print(int p, int q) {
    bool fu = false;
    if (p < 0) {
        p = 0 - p;
        fu = !fu;
    }
    if (q < 0) {
        q = 0 - q;
        fu = !fu;
    }
    int x = gcd(p, q);
    p /= x, q /= x;
    if (fu) cout << '-';
    if (q == 1) cout << p;
    else cout << p << '/' << q;
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    while (T--) {
        double a, b, c;
        cin >> a >> b >> c;
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "NO\n";
            continue;
        }
        double xu = max(0 - b + sqrt(delta), 0 - b - sqrt(delta));
        double xd = 2 * a;
        if (sqrt(delta) == (double)((int)sqrt(delta))) {
            print((int)xu, (int)xd);
            cout << '\n';
            continue;
        }
        cout << "...\n";
    }
    return 0;
}
