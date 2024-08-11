#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("apple1.in","r",stdin);
    freopen("apple1.ans","w",stdout);
    freopen("apple2.in","r",stdin);
    freopen("apple2.ans","w",stdout);
    int a[1000005] = {};
    long long n, day = 0, ans = 0;
    cin >> n;
    if ((n - 1) % 3 == 0) ans = 1;
    for (int i = 1; i <= n; i++) a[i] = i;
    while (n) {
        int t = 0;
        day++;
        for (int j = 1; j <= n; j += 3) {
            a[j] = 0;
            t++;
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (a[k-1] == 0) swap(a[k], a[k-1]);
            }
        }
        n -= t;
    }
    if (ans) cout << day << " " << ans;
    else cout << day << " " << day;
    return 0;
}