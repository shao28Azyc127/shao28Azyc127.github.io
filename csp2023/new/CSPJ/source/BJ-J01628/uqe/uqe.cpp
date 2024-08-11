#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int x, int y) {
    if (x == 0)
        return y;
    return gcd(x%y, y);
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    while (t--) {
        double a, b, c;
        cin >> a >> b >> c;
        double delta = b*b-4*a*c;
        if (delta < 0)
            cout << "NO\n";
        else if (delta == 0) {
            cout << -(b/2*a) << '\n';
        }
        else if (delta > 0) {
            int x1 = (-b+sqrt(delta))/(2*a);
            int x2 = (-b-sqrt(delta))/(2*a);
            cout << max(x1, x2) << '\n';
        }
    }
    return 0;
}