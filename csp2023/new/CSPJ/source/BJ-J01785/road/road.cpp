#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], v[N], mn[N], d;
long long l[N], ans, oil;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    mn[0] = 0x3f3f3f3f;
    scanf("%d%d", &n, &d);
    for(int i = 1; i < n; ++i) {
        scanf("%d", v + i);
        l[i + 1] = l[i] + v[i];
    } for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        mn[i] = mn[i - 1] < a[i] ? mn[i - 1] : a[i];
    } for(int i = 1; i <= n;) {
        while(l[i] <= oil && i <= n + 1) ++i;
        --i;
        long long plus = (l[i + 1] - oil + d - 1) / d;
        oil += plus * d;
        ans += 1ll * plus * mn[i];
        //cout<<i<<" "<<plus<<" "<<ans<<endl;
    }
    printf("%lld", ans);
    return 0;
}