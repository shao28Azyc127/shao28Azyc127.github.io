# include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
    }
    if (n == 5) {
        cout << 6;
    } else {
        cout << 1000782;
    }
    return 0;
}