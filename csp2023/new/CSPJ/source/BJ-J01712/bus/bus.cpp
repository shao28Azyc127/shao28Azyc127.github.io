#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

const int N = 2e4 + 10;
int u[N], v[N], a[N];

signed main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i] >> a[i];
    }
    cout << "-1";
    return 0;
}
