#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
ll n, d, mn = 1e9, now;
ll dis[N], v[N];
ll ans = 0;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for (int i = 1; i < n; i++) scanf("%lld", &dis[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
    for (int i = 1; i < n; i++) {
        mn = min(mn, v[i]); dis[i] -= now;
        ll num = (dis[i] - 1) / d + 1;
        ans += num * mn; now = num * d - dis[i];
    }
    printf("%lld\n", ans);
    return 0;
}
