#include <bits/stdc++.h>

using namespace std;

int n, a[1000000], v[1000000], d, f[1000000];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[1] = 0;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + (v[i] / d * a[i]);
    }
    cout << f[n] << endl;

    return 0;
}
