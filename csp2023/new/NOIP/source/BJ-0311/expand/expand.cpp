#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 2005;
int C, n, m, q, a[N], b[N], ca[N], cb[N];
bool f[M][M], t[M][M], flag;
inline void solve() {
  if (a[1] == b[1] || a[n] == b[m]) { cout << 0; return; }
  if (a[1] < b[1] && a[n] > b[m]) { cout << 0; return; }
  if (a[1] > b[1] && a[n] < b[m]) { cout << 0; return; }
  if (a[1] < b[1]) flag = 1;
  if (a[1] > b[1]) flag = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (flag) t[i][j] = (a[i] < b[j]);
      else t[i][j] = (a[i] > b[j]);
    }
  f[1][1] = t[1][1];
  for (int i = 2; i <= n; i++) f[i][1] = (t[i][1] && f[i - 1][1]);
  for (int i = 2; i <= m; i++) f[1][i] = (t[1][i] && f[1][i - 1]);
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= m; j++)
      f[i][j] = (t[i][j] && (f[i - 1][j] || f[i][j - 1]));
  cout << (f[n][m] ? 1 : 0);
}
int main() {
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> C >> n >> m >> q;
  for (int i = 1; i <= n; i++) cin >> a[i], ca[i] = a[i];
  for (int i = 1; i <= m; i++) cin >> b[i], cb[i] = b[i];
  if (C <= 7) {
    solve();
    while (q--) {
      int kx, ky; cin >> kx >> ky;
      for (int i = 1; i <= kx; i++) {
        int id, x; cin >> id >> x;
        a[id] = x;
      }
      for (int i = 1; i <= ky; i++) {
        int id, x; cin >> id >> x;
        b[id] = x;
      }
      solve();
      for (int i = 1; i <= n; i++) a[i] = ca[i];
      for (int i = 1; i <= m; i++) b[i] = cb[i];
    }
    cout << '\n';
    return 0;
  }
  return 0;
}