//about 40pts
#include <iostream>
#include <cstdio>
using namespace std;
int C, T, n, m, a[100005], b[100005], ans;
char op[100005]; int x[100005], y[100005];
void dfs(int pos, int utot) {
    if (utot > ans) return;
    if (pos == n + 1) {
        for (int i = 1; i <= n; i++) b[i] = a[i];
        for (int i = 1; i <= m; i++) {
            if (op[i] == 'T') b[x[i]] = 1;
            else if (op[i] == 'F') b[x[i]] = 0;
            else if (op[i] == 'U') b[x[i]] = 2;
            else if (op[i] == '+') b[x[i]] = b[y[i]];
            else if (op[i] == '-') {
                if (b[y[i]] == 2) b[x[i]] = 2;
                else b[x[i]] = 1 - b[y[i]];
            }
        }
        for (int i = 1; i <= n; i++)
            if (a[i] != b[i]) return;
        ans = min(ans, utot);
        return;
    }
    for (int i = 0; i <= 2; i++) {
        a[pos] = i;
        dfs(pos + 1, utot + (int)(i == 2));
    }
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> C >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> op[i] >> x[i];
            if (op[i] == '+' || op[i] == '-') cin >> y[i];
        }
        if (C == 1 || C == 2) {
            ans = n;
            dfs(1, 0);
            cout << ans << '\n';
        } else if (C == 3 || C == 4) {
            for (int i = 1; i <= n; i++) a[i] = 0;
            for (int i = 1; i <= m; i++) {
                if (op[i] == 'T') a[x[i]] = 1;
                else if (op[i] == 'F') a[x[i]] = 0;
                else if (op[i] == 'U') a[x[i]] = 2;
            }
            ans = 0;
            for (int i = 1; i <= n; i++) ans += (int)(a[i] == 2);
            cout << ans << '\n';
        } else if (C == 5 || C == 6) {
            cout << "...\n";
        } else {
            cout << "...\n";
        }
    }
    return 0;
}
