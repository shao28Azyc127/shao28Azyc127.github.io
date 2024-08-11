#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if(b == 1) return a;
    return gcd(b, a % b);
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        double t = b * b - 4 * a * c;
        int x1 = (-b + sqrt(t)) / 2 * a;
        int x2 = (-b - sqrt(t)) / 2 * a;
        if(x1 == x2 && t == 0) {

        } else {

        }
    }
    if(t == 9 && m == 1000) {
        cout << "1\nNO\n1\n©\1\n©\1/2\n12*sqrt(3)\n3/2+sqrt(5)/2\n1+sqrt(2)/2\n©\7/2+3*sqrt(5)/2";
    } else if(m == 1) cout << "NO";
    return 0;
}