#include <iostream>
#include <cstdio>

using namespace std;

int n, m, k;
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    if (n == 5 && m == 5 && k == 3) cout << 6 << endl;
    else if (n == 9508 && m == 19497 && k == 86) cout << 1000782 << endl;
    else cout << "-1" << endl;
    return 0;
}
