#include <bits/stdc++.h>
using namespace std;
int n, d, a[100086], v[100086], sum;
int main () {
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << a[1] * (sum / d + (sum % d)) << endl;
    return 0;
}
