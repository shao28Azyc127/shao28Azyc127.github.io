#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, ans1 = 0, ans2 = 0;
    cin >> n;
    int temp = n;
    for (int i = 1; i <= n; i++) {
        if (temp == 0) {
            break;
        }
        if (temp % 3 == 0) {
            ans1++;
            temp -= (temp / 3);
        } else {
            ans1++;
            temp -= (temp / 3 + 1);
        }
    }
    temp = n;
    for (int i = 1; i <= ans1; i++) {
        ans2++;
        if (temp % 3 == 1) {
            break;
        } else if (temp % 3 == 0) {
            temp -= (temp / 3);
        } else {
            temp -= (temp / 3 + 1);
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}
