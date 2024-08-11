#include <bits/stdc++.h>
using namespace std;
long long n, m, v[100005], a[100005], s[100005], V;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i < n; i ++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i ++) {
        s[i] = s[i - 1] + v[i - 1];
        // cout << s[i] << "\n1\n";
    }
    // cout << "1";
    a[n] = 0;
    // cout << 1;
    long long ans = 0;
    for (int i = 1; i <= n;) {
        if (i == n) break;
        int minn = n;
        for (int j = i + 1; j <= n; j ++) {
            if (a[j] <= a[i]) {
                minn = j;
                break;
            }
        }
        if (V < 0) V = 0;
        int x = (s[minn] - s[i] + m - 1 - V) / m;
        ans += x * a[i];
        
        // cout << minn << " " << i << " " << x * a[i] << " " << V << "\n";
        V = x * m - ((s[minn] - s[i] - V));
        i = minn;
        // cout << s[minn] - s[i - 1] << " " << minn << " " << i << "\n";
    }
    cout << ans;
    return 0;
}