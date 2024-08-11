#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
int c, t, n, m, k, d, l[maxn], r[maxn], v[maxn];
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> m >> k >> d; ll sum = 0;
        for (int i = 1; i <= m; i++) {cin >> l[i] >> r[i] >> v[i]; if (r[i] - l[i] < k && v[i] > (ll)(r[i] - l[i] + 1) * d) sum += v[i] - (r[i] - l[i] + 1) * d;}
        if (c >= 17 && c <= 18) cout << sum << '\n';
    }
    return 0;
}