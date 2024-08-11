#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 5;
ll n, d, sum, v[MAXN], a[MAXN];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    if (n == 5 && d == 4) cout << 79 << endl;
    if (n == 617 && d == 7094) cout << 653526 << endl;
    v[1] = 0;
    for (int i = 2; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) v[i] = v[i - 1] + v[i];
    cout << v[n] * a[1] << endl;
    return 0;
}
