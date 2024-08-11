#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int u[N], a[N];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> u[i];
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i];
    }
    if (sum % d == 0) {
        sum /= d;
        cout << u[0] * sum;
    }
    else {
        sum = sum / d + 1;
        cout << u[0] * sum;
    }
    return 0;
}