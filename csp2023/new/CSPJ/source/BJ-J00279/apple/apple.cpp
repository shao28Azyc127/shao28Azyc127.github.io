#include <bits/stdc++.h>
using namespace std;
int n, ans1, ans2 = 2147483647, cnt, b[1000086];
int main () {
    freopen ("apple.in", "r", stdin);
    freopen ("apple.out", "w", stdout);
    cin >> n;
    cnt = n;
    while (cnt > 0) {
        ans1++;
        int a = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i]) continue ;
            if (a % 3 == 0) b[i] = 1, cnt--;
            a++;
        }
        if (b[n]) {
            ans2 = min (ans2, ans1);
            //cout << ans1 << endl;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
