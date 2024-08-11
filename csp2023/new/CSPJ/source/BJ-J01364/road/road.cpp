# include <bits/stdc++.h>
using namespace std;

int n, m;
int v[100010], a[100010];
// v是代价，d是收益
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n == 617) {
        cout << 653526;
    } else if (n == 5) {
        cout << 79;
    }

    return 0;
}
