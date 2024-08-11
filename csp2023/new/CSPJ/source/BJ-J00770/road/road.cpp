#include <bits/stdc++.h>
using namespace std;
int a[100005], v[100005];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1;i < n;i++) {
        cin >> v[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 0, miles = 0, mills = 0;
    for (int i = 1;i < n;i++) {
        if (a[i] >= a[i + 1]) {
            int temp = (v[i] - miles) / m;
            if (temp * m != v[i] - miles) temp++;
            ans += temp * a[i];
            miles += temp - v[i];
        } else if (a[i] < a[i + 1]) {
            int t = i + 2;
            while (a[t - 1] < a[t]) {
                t++;
            }
            mills = 0;
            int x;
            for (x = i;x <= t;x++) {
                mills += v[x];
            }
            int temp = (mills - miles) / m;
            if (temp * m != mills - miles) temp++;
            ans += temp * a[i];
            i = x;
            miles += temp - v[i];
        }
        //cout << ans << endl;
        //cout << mills << " " << miles << " " << endl;
    }
    cout << ans << endl;
}
