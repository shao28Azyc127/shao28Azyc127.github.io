#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n, ansz = 0, ansd = -1;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while (n > 0) {
        ansz++;
        if (n % 3 == 1 && ansd == -1) ansd = ansz;
        n -= ceil(n * 1.0 / 3);
    }
    cout << ansz << " " << ansd;
    return 0;
}
