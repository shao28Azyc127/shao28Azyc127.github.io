#include <iostream>
#include <cmath>
using namespace std;

int v[100001], a[100001];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    long long sum = 0;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long l = 1ll * ceil(1.0 * sum / d);
    cout << a[1] * l << endl;
    return 0;
}
