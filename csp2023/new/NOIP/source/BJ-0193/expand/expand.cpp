#include <iostream>
using namespace std;
const int maxn = 2e3 + 10;
int c, n, m, q, p, v, a[maxn], b[maxn], x[maxn], y[maxn];
bool f[maxn][maxn][2];
bool solve(int na, int nb) {
    for (int i = 1; i <= n; i++) x[i] = a[i];
    for (int i = 1; i <= m; i++) y[i] = b[i];
    for (int i = 1; i <= na; i++) cin >> p >> v, x[p] = v;
    for (int i = 1; i <= nb; i++) cin >> p >> v, y[p] = v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j][0] = f[i][j][1] = false;
    f[0][0][0] = f[0][0][1] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (x[i] < y[j]) f[i][j][0] = f[i - 1][j][0] || f[i][j - 1][0] || f[i - 1][j - 1][0];
            else if (x[i] > y[j]) f[i][j][1] = f[i - 1][j][1] || f[i][j - 1][1] || f[i - 1][j - 1][1];
    return f[n][m][0] || f[n][m][1];
}
int main() {
    ios::sync_with_stdio(false);
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    cout << solve(0, 0);
    while (q--) {
        int na, nb; cin >> na >> nb;
        cout << solve(na, nb);
    }
    return 0;
}