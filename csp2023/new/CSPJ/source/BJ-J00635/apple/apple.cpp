#include <iostream>
#include <cstdio>
using namespace std;

// BJ-J00635 apple.cpp
// can not be changed now.
// The tests 1,2 are AC, limit can run.

bool chk(int lst) {
    return (lst - 1) % 3 != 0;
}

int main() {

    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int n;
    cin >> n;
    int ans = 0, lst = n, an2 = -1, t = 0;
    bool fnd = false;
    while (lst >= 1) {
        t++;
        if (!fnd && !chk(lst)) {
            fnd = true;
            an2 = t;
        }
        int x = (lst - 1) / 3 + 1;
        ans += x;
        lst -= x;
    }
    cout << t << " " << an2 << endl;
    return 0;
}
