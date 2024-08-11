#include <bits/stdc++.h>
using namespace std;

int n, d, price, dis, oil;
int dists[100005];
int prices[100005];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        int v;
        cin >> v;
        dis += v;
        dists[i] = v;
    }
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        prices[i] = a;
    }
    for (int i = 1; i < n; i++) {
        price += prices[i] * (dists[i] % d == 0 ? dists[i] / d : dists[i] / d + 1);
        oil += d * (dists[i] % d == 0 ? dists[i] / d : dists[i] / d + 1);
        dis -= oil / 10;
        oil /= 10;
    }
    cout << price;
    return 0;
}
