#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], b[N];
long long sum[N], ans, minn, tmp;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 2; i <= n; i++) {
        cin >> a[i], sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for(int i = 2; i <= n; i++) {
        long long ttmp = 0;
        if(i == 2) {
            ttmp = 1LL * (sum[i] - sum[i - 1] + m - 1) / m;
            ans += 1LL * ttmp * b[1], minn = b[1], tmp = ttmp * m - sum[2];
        } else {
            ttmp = 1LL * (sum[i] - sum[i - 1] - tmp + m - 1) / m;
            minn = min(minn, 1LL * b[i - 1]), ans += ttmp * minn, tmp = tmp + ttmp * m - sum[i] + sum[i - 1];
        }
    }
    printf("%lld", ans);
    return 0;
}
