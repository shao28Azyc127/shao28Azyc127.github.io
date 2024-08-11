#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ll n, d, now = 0, ans = 0;
    ll v[100005], dis[100005], pri[100005];
    scanf("%lld%lld", &n, &d);
    dis[1] = 0;
    for (ll i = 1; i < n; i++) {
        scanf("%lld", &v[i]);
        dis[i + 1] = dis[i] + v[i];
    }
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &pri[i]);
    }
    pri[n + 1] = 0;
    ll i;
    for (i = 1; i < n; ) {
        for (ll j = i; j <= n + 1; j++) {
            if (pri[i] > pri[j]) {
                if (j == n + 1) j--;
                ll disc = dis[j] - dis[i];
                ll needc = disc - now;
                now += needc / d * d;
                ans += needc / d * pri[i];
                if (now < disc) {
                    now += d;
                    ans += pri[i];
                }
                i = j;
                now -= disc;
                break;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}
