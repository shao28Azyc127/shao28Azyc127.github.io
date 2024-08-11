#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d, k, sum = 0, min, now = 0;
    int S[100005];
    int P[100005];
    cin >> n >> d;
    for (int i = 0; i < n - 1; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < n - 1; i++) {
        sum += S[i];
    }
    if (sum % d == 0) {
        k = sum / d;
    } else {
        k = sum / d + 1;
    }
    min = P[0];
    for (int i = 1; i < n; i++) {
        if (P[i] < min) {
            min = P[i];
        }
    }
    if (min == P[0]) {
        cout << k * P[0];
        return 0;
    }
    return 0;
}
