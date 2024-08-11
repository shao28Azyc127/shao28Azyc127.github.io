#include<bits/stdc++.h>
using namespace std;
const int MX = 2005;
typedef long long LL;
int c, n, m, q, x[MX], y[MX], xx[MX], yy[MX], kx, ky, p, v;
bool dp[MX][MX];
void solve()
{
    bool sw = 0;
    if (xx[1] == yy[1]) {
        cout << 0;
        return;
    }
    if (xx[1] < yy[1]) {
        sw = 1;
        swap(xx, yy);
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int r = 1; r <= n; r++) {
            int mn = INT_MAX;
            for (int l = r; l >= 1; l--) {
                mn = min(mn, xx[l]);
                if (mn <= yy[i]) break;
                dp[r][i] |= (dp[l][i - 1] | dp[l - 1][i - 1]);
            }
        }
    if (sw) cout << dp[m][n];
    else cout<< dp[n][m];
}
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> c >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= m; i++) cin >> y[i];
    memcpy(xx, x, sizeof(x));
    memcpy(yy, y, sizeof(y));
    solve();
    while (q--) {
        memcpy(xx, x, sizeof(x));
        memcpy(yy, y, sizeof(y));
        cin >> kx >> ky;
        for (int i = 1; i <= kx; i++) {
            cin >> p >> v;
            xx[p] = v;
        }
        for (int i = 1; i <= ky; i++) {
            cin >> p >> v;
            yy[p] = v;
        }
        solve();
    }
    return 0;
}
