#include <bits/stdc++.h>
using namespace std;
int n, ans1, ans2;
bool flag = 1;
int main(void) {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    while (n != 0) {
        ans1++, ans2 += flag;
        if (n % 3 == 1) flag = 0;
        n = n * 2 / 3;
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}
