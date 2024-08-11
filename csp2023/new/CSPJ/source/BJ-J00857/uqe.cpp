#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int T, M, a, b, c;

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    while (T--) {
        cin >> a >> b >> c;
        int der = b * b - 4 * a * c;
        if (der < 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (b == 0)
            cout << int(sqrt(-c / a)) << endl;
        else if (c == 0)
            cout << 0 << endl;
    }
    return 0;
}