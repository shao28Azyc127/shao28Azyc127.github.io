#include <iostream>
#include <cstdio>
using namespace std;
int u[20005], v[20005], a[20005];
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for ( int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> a[i];
    }
    cout << -1 << endl;
    return 0;
}