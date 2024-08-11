#include <bits/stdc++.h>
using namespace std;
int n = 0, d = 0, mm = 100001, dis = 0, ans = 0, v[100000], a[100001];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) mm = min(mm, a[i]), ans += ceil(1.0 * (v[i] - dis) / d) * mm, dis += ceil(1.0 * (v[i] - dis) / d) * d - v[i];
    cout << ans << endl;
    return 0;
}