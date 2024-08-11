#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N], u[N];
int n, d, sum, x = 1;
int mini (int begin_) {
    int m = N, mi = 0;
    for (int i = begin_; i <= n; i++) {
        if (a[i] < m) {
            mi = i;
            m = a[i];
        }
    }
    return mi;
}
int ceju (int x, int y) {
    int ans = 0;
    for (int i = x; i < y; i++) {
        ans += u[i];
    }
    return ans;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        cin >> u[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (x != n) {
        int gi = mini(x + 1);
        int juli = ceju(x, gi);
        int money = (d * juli) * a[gi];
        sum += money;
        x = gi;
    }
    cout << sum;
    return 0;
}
