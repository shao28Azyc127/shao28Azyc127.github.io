#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 1e5+5;
int v[N], c[N];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n; cin >> n;
    int d; cin >> d;
    for (int i = 1; i < n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    long long oil = 0, cost = 0;
    for (int i = 1; i < n; i++) {
        oil -= v[i-1];
        if (oil >= v[i])
            continue;
        int nh = n;
        for (int j = n-1; j >= i+1; j--)
            if (c[j] < c[i])
                nh = j;
        long long l = 0;
        for (int j = i; j < nh; j++)
            l += v[j];
        long long thisoil = ceil(1.0*(l-oil)/d);
        cost += thisoil*c[i];
        oil += thisoil*d;
        // cout << cost << " " << thisoil << "\n";
    }
    cout << cost;
    return 0;
}