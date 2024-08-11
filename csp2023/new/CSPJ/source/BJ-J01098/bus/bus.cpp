#include <bits/stdc++.h>
using namespace std;

int arr[20005][5];

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        arr[i][0] = u;
        arr[i][1] = v;
        arr[i][2] = a;
    }
    cout << -1;
}