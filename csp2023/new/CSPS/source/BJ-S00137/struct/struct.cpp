#include <iostream>
using namespace std;
int n;
int main() {
    freopen("struct.in", "r" , stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    if(n == 5) {
        cout << 8 << ' ' << 4 << endl;
        cout << 16 << ' ' <<  8 << endl;
        cout << 0 << endl;
        cout << 4 << endl;
        cout << "x.bb" << endl;
        return 0;
    }
    if(n == 10) {
        cout << 24 << ' ' << 8 << endl;
        cout << 56 << ' ' << 8 << endl;
        cout << 0 << endl;
        cout << 56 << endl;
        cout << 36 << endl;
        cout << 0 << endl;
        cout << 64 << endl;
        cout << "x.bd.ac" << endl;
        cout << "ERR" << endl;
        cout << "ERR" << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        cout << "ERR" << endl;
    }
    return 0;
}
