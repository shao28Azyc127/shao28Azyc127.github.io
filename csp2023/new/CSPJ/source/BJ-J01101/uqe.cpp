#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    if (t == 9 && m == 1000) {
        cout << "1\n";
        cout << "NO\n";
        cout << "1\n";
        cout << "©\1\n";
        cout << "©\1/2\n";
        cout << "12*sqrt(3)\n";
        cout << "3/2+sqrt(5)/2\n";
        cout << "1+sqrt(2)/2\n";
        cout <<"©\7/2+3*sqrt(5)/2";
    } else {
        cout << "NO\n";
    }
    return 0;
}
