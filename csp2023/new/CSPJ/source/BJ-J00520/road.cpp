#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;
//road
ll n, d;
ll dist[MAXN], price[MAXN];
double tank = 0;
ll ans;
int main() {
    dist[1] = 0;
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for (ll i = 2; i <= n; i++) {
        scanf("%lld", &dist[i]);
    }
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &price[i]);
    }
    for (ll i = 1; i < n; ) {
        ll ind = n;
        ll godist = 0;
        for (ll j = i + 1; j <= n; j++) {
            godist += dist[j];
            if (price[j] < price[i]) {
                ind = j;
                break;
            }
        }
        ans += ceil(1.0 * godist / d - tank) * price[i];
        tank = ceil(1.0 * godist / d - tank) + tank - 1.0 * godist / d;
        i = ind;
    }
    printf("%lld", ans);
    return 0;
}

