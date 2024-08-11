#include<bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
    return (x == 0? y : x%y);
}
int main () {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    while(t--) {
        double a, b, c;
        cin >> a >> b >> c;
        double d = b * b - 4 * a * c;
        if (d < 0) {
            cout << "NO";
            continue;
        }
        double x1 = ((0-b) + sqrt(d)) / (2*a);
        double x2 = ((0-b) - sqrt(d)) / (2*a);
        cout << max(x1, x2) << endl;
    }
    return 0;
}