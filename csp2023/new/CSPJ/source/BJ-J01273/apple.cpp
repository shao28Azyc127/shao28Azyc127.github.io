#include <bits/stdc++.h>
using namespace std;
long long n, cnt, timn;
int main () {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n > 0) {
        if (n % 3 == 1 && !timn) timn = cnt + 1;
        n = n - ((n - 1) / 3 + 1);
        cnt++;
    }
    cout << cnt << " " << timn << endl;
    return 0;
}
