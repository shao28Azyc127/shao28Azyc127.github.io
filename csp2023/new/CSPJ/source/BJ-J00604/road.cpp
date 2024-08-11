#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d;
int a[100005], v[100005];
ll ans;
ll dp[100005], dis[100005];
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d", &v[i]);
        dis[i] = dis[i - 1] + v[i];
        //cout<<dis[i];
    }
    a[0] = 100005;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] = min(a[i], a[i - 1]);
    }
    ll pos = 0;
    for (int i = 1; i <= n - 1; i++) {
        int num = ((dis[i] - pos) / d);
        if ((dis[i] - pos) % d != 0) num++;
        ans += num * a[i];
        //cout<<ans<<" ";
        pos += d * num;
        //cout<<pos<<endl;
    }
    printf("%lld", ans);
    /*memset(dp, 1e10, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + )
    }*/
    return 0;
}
