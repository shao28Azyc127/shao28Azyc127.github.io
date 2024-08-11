#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long v[100100];
long long a[100100];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long d;
    cin >> n >> d;
    for (int i = 0; i < n - 1; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    long long last = 0;
    long long now = 0;
    long long dis = 0;
    long long lowest = a[0];
    for (int i = 1; i < n; ++i) {
        dis += v[i - 1];
        now = (dis + d - 1) / d * d;
        ans += (now - last) / d * lowest;
        last = now;
        lowest = std::min(a[i], lowest);
    }
    cout << ans << endl;
    return 0;
}
