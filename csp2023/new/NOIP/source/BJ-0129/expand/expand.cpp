#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2005;
int sid, n, m, q;
int x[N];
int y[N];
int kx, ky;
int xx[N];
int yy[N];
int ans[65];
int tim;
int dp[N][N];
void solve() {
    tim++;
    if(xx[1] == yy[1]) {
        ans[tim] = 0;
        return;
    }
    int n1, m1;
    n1 = n, m1 = m;
    if(xx[1] > yy[1]) {
        for(int i = 1; i <= max(n, m); i++) {
            swap(xx[i], yy[i]);
        }
        swap(n, m);
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(xx[i] < yy[j]) {
                dp[i][j] |= dp[i][j - 1] | dp[i - 1][j] | dp[i - 1][j - 1];
            }
        }
    }
    ans[tim] = dp[n][m];
    n = n1, m = m1;
}
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> sid >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> y[i];
    }
    for(int i = 1; i <= n; i++) {
        xx[i] = x[i];
    }
    for(int j = 1; j <= m; j++) {
        yy[j] = y[j];
    }
    solve();
    for(int qi = 1; qi <= q; qi++) {
        for(int i = 1; i <= n; i++) {
            xx[i] = x[i];
        }
        for(int j = 1; j <= m; j++) {
            yy[j] = y[j];
        }
        cin >> kx >> ky;
        int ps, vl;
        for(int i = 1; i <= kx; i++) {
            cin >> ps >> vl;
            xx[ps] = vl;
        }
        for(int i = 1; i <= ky; i++) {
            cin >> ps >> vl;
            yy[ps] = vl;
        }
        solve();
    }
    for(int i = 1; i <= q + 1; i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
