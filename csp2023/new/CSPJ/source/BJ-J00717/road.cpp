#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e5;
ll n;
ld d;
ld dis[MAXN + 5], pre[MAXN + 5];
ll st[MAXN + 5][25], lg[MAXN + 5];
inline ll query(ll l, ll r) {
    ll k = lg[r - l + 1] - 1;
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for (ll i = 1; i < n; i++) {
        scanf("%lld", &dis[i]);
        pre[i] = pre[i - 1] + dis[i];
    }
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &st[i][0]);
        lg[i] = lg[i - 1] + ((1 << lg[i - 1]) == i);
    }
    for (ll j = 1; j <= 20; j++) {
        for (ll i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
        }
    }
    ld oil = 0;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ll l = i + 1, r = n - 1, res = -1;
        while (l <= r) {
            ll mid = l + r >> 1;
            if (query(i + 1, mid) < st[i][0]) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (res == -1) {
            ld sumDis = pre[n - 1] - pre[i - 1];
            ld canDis = oil * d;
            if (canDis < sumDis) ans += (ll)ceil((sumDis - canDis) * 1.0 / d) * st[i][0];
            break;
        }
        ld sumDis = pre[res - 1] - pre[i - 1];
        ld canDis = oil * d;
        if (canDis < sumDis) {
            ll tmp = ceil((sumDis - canDis) * 1.0 / d);
            oil += tmp;
            oil -= sumDis / d;
            ans += tmp * st[i][0];
        } else {
            oil -= sumDis / d;
        }
        i = res - 1;
        // cout << i << " " << res << " " << ans << " " << oil << endl;
    }
    printf("%lld\n", ans);
    return 0;
}
