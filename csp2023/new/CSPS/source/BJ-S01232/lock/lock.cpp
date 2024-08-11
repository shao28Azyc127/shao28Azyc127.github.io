#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, ans, a[10][6], b[6];

inline bool check(int x) {
    int tot = 0;
    for (int i = 1; i <= 5; ++i) tot += (b[i] != a[x][i]);
    if (tot == 0 || tot > 2) return 0;
    if (tot == 1) return 1;
    for (int i = 1; i <= 4; ++i)
        if (a[x][i] != b[i] && a[x][i + 1] != b[i + 1] && ((a[x][i] - b[i]) % 10 + 10) % 10 == ((a[x][i + 1] - b[i + 1]) % 10 + 10) % 10) return 1;
    return 0;
}

inline void dfs(int x) {
    if (x == 6) {
        bool flg = 1;
        for (int i = 1; i <= n; ++i) flg &= check(i);
        if (flg) ans ++;
        return;
    }
    for (int i = 0; i <= 9; ++i) b[x] = i, dfs(x + 1);
}

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0);
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= 5; ++j) cin >> a[i][j];
    dfs(1);
    cout << ans << '\n';
    return 0;
}