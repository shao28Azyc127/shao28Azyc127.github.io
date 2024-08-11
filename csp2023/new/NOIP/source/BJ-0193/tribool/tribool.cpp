#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int c, t, n, m, ans, nxt[3], ch[100], cur[maxn], a[maxn], x[maxn], y[maxn];
char op[maxn];
bool check() {
    for (int i = 1; i <= n; i++) a[i] = cur[i];
    for (int i = 1; i <= m; i++) {
        if (ch[op[i]] < 3) a[x[i]] = ch[op[i]];
        else if (op[i] == '+') a[x[i]] = a[y[i]];
        else a[x[i]] = nxt[a[y[i]]];
    }
    for (int i = 1; i <= n; i++) if (a[i] != cur[i]) return false;
    return true;
}
void dfs(int k) {
    if (k > n) {
        if (check()) ans = min(ans, (int)count(cur + 1, cur + n + 1, 1));
        return;
    } for (int i = 0; i < 3; i++) cur[k] = i, dfs(k + 1);
}
int main() {
    ios::sync_with_stdio(false);
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t; nxt[0] = 2; nxt[1] = 1; ch['F'] = 2; ch['U'] = 1; ch['+'] = 3; ch['-'] = 4;
    while (t--) {
        cin >> n >> m; ans = n;
        for (int i = 1; i <= m; i++) {
            cin >> op[i] >> x[i]; cur[x[i]] = ch[op[i]];
            if (cur[x[i]] > 2) cin >> y[i];
        }
        if (c <= 2) dfs(1), cout << ans << '\n';
        else if (c <= 4) cout << count(cur + 1, cur + n + 1, 1) << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}