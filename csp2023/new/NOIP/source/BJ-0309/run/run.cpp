#include<iostream>
#include<cstring>
using namespace std;
#define int long long
const int maxn = 2e3 + 5;
const int inf = 1e18 + 5;
int c, t, n, m, k, d, tmp, ans, now, last, p, a[maxn], f[maxn], x[maxn], y[maxn], v[maxn];
void solve(int i){
    p = 1;
    now = 0;
    tmp = i;
    for(int j = 1; j <= n; ++j) a[j] = tmp % 2, tmp /= 2;
    for(int j = 1; j <= n; ++j){
        if(a[j]) last++;
        else last = 0;
        if(last > k) return;
        if(a[j]) now -= d * k;
        if(j > x[p]) p++;
        if(j == x[p]) now += (last >= y[p]) * v[p], p++;
    }
    ans = max(ans, now);
}
signed main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--){
        ans = -inf;
        memset(f, 0, sizeof(f));
        scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
        for(int i = 1; i <= m; ++i) scanf("%d%d%d", &x[i], &y[i], &v[i]);
            for(int i = 0; i <= (1 << n - 1); ++i){
                solve(i);
            }
            printf("%lld\n", ans);
    }
    return 0;
}
