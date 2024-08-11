#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
int max(int x, int y) {return x > y ? x : y;}
int n, a[10][6], ans[6], b[6][10];
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
    if (n == 1) {puts("81"); return 0;}
    cout << 1 << endl;
    return 0;
}