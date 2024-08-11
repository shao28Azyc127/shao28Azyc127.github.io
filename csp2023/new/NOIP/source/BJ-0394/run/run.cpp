#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll My_RP = 0x3f3f3f3f3f3f3f3fll;
ll n, m, K, D, tot, dp[1100][1100];
struct chl {
    ll r, s, v;
    bool operator < (chl xx) { return r == xx.r ? (s < xx.s) : (r < xx.r); }
} a[100100];
void work(void) {
    scanf("%lld%lld%lld%lld", &n, &m, &K, &D);
    for(ll i = 1; i <= m; i++)
        scanf("%lld%lld%lld", &a[i].r, &a[i].s, &a[i].v);
    sort(a + 1, a + m + 1);
    for(ll i = 0; i <= n; i++)
        for(ll j = 0; j <= n; j++)
            dp[i][j] = -My_RP;
    tot = dp[0][0] = 0;
    for(ll i = 1; i <= n; i++) {
        ll sum = 0;
        for(ll j = 1; j <= min(i, K); j++) {
            while(a[tot + 1].r <= i && a[tot + 1].s <= j && tot < m) sum += a[++tot].v;
            dp[i][j] = dp[i - 1][j - 1] - D + sum;
        }
        for(ll j = 0; j <= min(i - 1, K); j++)
            dp[i][0] = max(dp[i][0], dp[i - 1][j]);
    } ll ans = 0;
    for(ll i = 0; i <= max(n, K); i++) ans = max(ans, dp[n][i]);
    printf("%lld\n", ans);
}
int main() {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ll C, T; scanf("%lld%lld", &C, &T);
    while(T--) work();
    return 0;
}
