#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5, M = 1005;
int C, T, n, m, k, d, f[M][M], sum[M][M];
signed main() {
  freopen("run.in", "r", stdin);
  freopen("run.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> C >> T;
  if (C <= 9) {
    while (T--) {
      cin >> n >> m >> k >> d;
      for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= k; j++) sum[i][j] = 0;
        f[i][0] = 0;
      }
      for (int i = 1; i <= m; i++) {
        int x, y, val; cin >> x >> y >> val;
        sum[x][y] += val;
      }
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
          sum[i][j] += sum[i][j - 1];
      for (int i = 1; i <= n; i++) {
        f[i + 1][0] = max(f[i + 1][0], f[i][0]);
        for (int j = 1; j <= k; j++) {
          f[i][j] = f[i - 1][j - 1] - d + sum[i][j];
          f[i + 1][0] = max(f[i + 1][0], f[i][j]);
        }
      }
      cout << f[n + 1][0] << '\n';
    }
    return 0;
  }
  if (C == 17 || C == 18) {
    while (T--) {
      cin >> n >> m >> k >> d;
      int ans = 0;
      for (int i = 1; i <= m; i++) {
        int x, y, val; cin >> x >> y >> val;
        if (y <= k) ans += max(0ll, val - y * d);
      }
      cout << ans << '\n';
    }
    return 0;
  }
  return 0;
}