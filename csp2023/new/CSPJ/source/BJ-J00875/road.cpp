#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll n, d, v[N], a[N];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for(int i = 1; i < n; i ++) scanf("%lld", &v[i]);
    for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    ll ld = (ll)ceil(v[1] * 1.0 / d) * d - v[1], lp = a[1], cnt = 2;
    ll sum = (ll)ceil(v[1] * 1.0 / d) * a[1];
    while(cnt < n) {
        if(a[cnt] < lp) lp = a[cnt];
        sum += (ll)ceil((v[cnt] - ld) * 1.0 / d) * lp;
        ld = (ll)ceil((v[cnt] - ld) * 1.0 / d) * d + ld - v[cnt];
        cnt ++;
    }
    printf("%lld\n", sum);
    return 0;
}
