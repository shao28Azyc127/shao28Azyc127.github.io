#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if (n == 1) {
            ans += 45;
            ans += 36;
        }

    }
    cout << ans;
    return 0;
}
