#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int dis[N], pr[N];

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i < n; ++i) cin >> dis[i];
    for (int i = 1; i <= n; ++i) cin >> pr[i];
    int dist = dis[1] / d * d, ans = 0, pik = 1;
    if (dist < dis[1]) dist += d;
    ans += dist / d * pr[1];
    for (int i = 2; i < n; ++i) {
        dist -= dis[i - 1];
        if (pr[pik] > pr[i]) pik = i;
        if (dist < dis[i]) {
            int t = dist;
            dist += (dis[i] - dist) / d * d;
            if (dist < dis[i]) dist += d;
            ans += (dist - t) / d * pr[pik];
        }
    }
    cout << ans;
    return 0;
}
