#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, M;
    cin >> T >> M;
    ll a, b, c;
    while (T--) {
        cin >> a >> b >> c;
        ll delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "NO\n";
        } else if (delta == 0) {
            ll x = (-b) / (2 * a);
            cout << x << '\n';
        } else {
            ll xa = (-b + sqrt(delta)) / (2 * a), xb = (-b - sqrt(delta)) / (2 * a);
            cout << max(xa, xb) << '\n';
        }
    }
    return 0;
}
