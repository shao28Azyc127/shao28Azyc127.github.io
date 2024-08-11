#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[5], b[5], ans;
bitset<N> vis[8];
int main() {
  freopen("lock.in", "r", stdin);
  freopen("lock.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) cin >> b[j];
    for (int j = 0; j < N - 5; j++) {
      for (int k = 0; k < 5; k++) a[k] = b[k];
      int cj = j;
      for (int k = 0; k < 5; k++) a[k] -= cj % 10, cj /= 10;
      int cnt = 0;
      for (int k = 0; k < 5; k++)
        if (a[k]) cnt++;
      if (cnt == 2)
        for (int k = 0; k < 4; k++)
          if (a[k] && a[k + 1] && a[k] == a[k + 1] || abs(a[k] - a[k + 1]) == 10) vis[i][j] = 1;
      if (cnt == 1) vis[i][j] = 1;
    }
  }
  for (int i = 0; i < N - 5; i++) {
    bool ok = 1;
    for (int j = 0; j < n; j++) ok &= vis[j][i];
    if (ok) ans++;
  }
  cout << ans << '\n';
  return 0;
}