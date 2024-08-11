#include <bits/stdc++.h>
using namespace std;
int n, ans, ans1;
bool f;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    f = false;
    while (n != 0) {
        ans++;
        if (n % 3 == 1 && f == false) {
            ans1 = ans;
            f = true;
        }
        if (n % 3 == 0) n -= n / 3;
        else n -= n / 3 + 1;
    }
    cout << ans << " " << ans1;
    return 0;
}
