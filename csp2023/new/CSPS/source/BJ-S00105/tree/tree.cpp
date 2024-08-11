#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, x, y, a[N], b[N], c[N];
int tot, head[N], nxt[N << 1], to[N << 1];
inline void Add(int x, int y) {
    tot++, nxt[tot] = head[x], head[x] = tot, to[tot] = y;
}
bool f1 = 1;

namespace n1 {
    inline void Solve(void) {
        for (int i = 1; i <= n; i++)
            a[i] = ceil(1.0 * a[i] / b[i]);
        sort(a + 1, a + n + 1);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, a[i] + (n - i));
        cout << ans << endl;
    }
}

signed main(void) {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        f1 &= (c[i] == 0);
    }
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        Add(x, y), Add(y, x);
    }
    if (f1) n1::Solve();
    return 0;
}
