#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n, d, v[100001], a[100001], f[100001][2], z[100001];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    f[1][0] = 0, f[1][1] = 0;
    v[1] = 0;
    for (int i = 1;i < n;i++) {
        cin >> v[i + 1];
        v[i + 1] += v[i];
    }

    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (i == 1)
            z[1] = 1;
        else {
            if (a[z[i - 1]] < a[i])
                z[i] = z[i - 1];
            else
                z[i] = i;
        }
    }

    for (int i = 2;i <= n;i++) {
        int y = ceil( (v[i] - v[z[i - 1]]) * 1.0 / d );
        int t = ceil( (v[i] - v[z[i - 1]] - f[z[i - 1]][1]) * 1.0 / d );
        f[i][0] = f[z[i - 1]][0] +  t * a[z[i - 1]];
        f[i][1] = f[z[i - 1]][1] - (y - t) * d  +  y * d - (v[i] - v[z[i - 1]]);
    }

    cout << f[n][0];
    return 0;
}