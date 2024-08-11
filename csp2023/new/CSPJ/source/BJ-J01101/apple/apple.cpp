#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int n;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    if (n <= 2) cout << n << " " << n << endl;
    else {
        if (n / 3 != 0) cout << (n + 1) / 3 + 2 << " ";
        else cout << n / 3 + 2 << " ";
        if (n == 4) cout << 1 << endl;
        else {
            if (n <= 1000000) {
                if (n % 3 == 1) {
                    cout << 1 << endl;
                } else {
                    if (n / 3 != 0) cout << (n + 1) / 3 + 2 << " ";
                    else cout << n / 3 + 2 << " ";
                }
            } else {
                if (n / 3 != 0) cout << (n + 1) / 3 + 2 << " ";
                else cout << n / 3 + 2 << " ";
            }
        }
    }
    return 0;
}
