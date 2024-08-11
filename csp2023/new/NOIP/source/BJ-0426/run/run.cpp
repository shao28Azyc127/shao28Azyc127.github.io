#include <bits/stdc++.h>
using namespace std;
int c, t, n, m, k, d, cha[10005][5], ans;
void dfs(int ti, int lian, int now) {
    if (now > n) {
        ans = max(ans, ti);
        return ;
    }
    dfs(ti, 0, now + 1);

    if (lian >= k) return ;

    lian++;
    if (lian >= cha[now][1]) ti += cha[now][2];
    dfs(ti - d, lian, now + 1);
}
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> m >> k >> d;
        memset(cha, 0, sizeof cha);
        for (int i = 1; i <= n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            cha[a][1] = b;
            cha[a][2] = c;
        }
        ans = 0;
        dfs(0, 0, 1);
        cout << ans << endl;
    }
    return 0;
}
