#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, M = 8005;
int n, ans;
bitset<M> f[M];
string s;
int main() {
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  cin >> n >> s;
  if (n >= (int)2e5) {
    for (int i = 0; i < n - 1; i++)
      if (s[i] == s[i + 1]) ans++;
    cout << ans << '\n';
    return 0;
  }
  s = '%' + s;
  for (int i = 1; i < n; i++)
    if (s[i] == s[i + 1]) f[i][i + 1] = 1;
  for (int k = 4; k <= n; k += 2)
    for (int i = 1; i + k - 1 <= n; i++) {
      int j = i + k - 1;
      if (f[i + 1][j - 1] && s[i] == s[j]) {
        f[i][j] = 1;
        continue;
      }
      int c = i;
      for (int p = i; p <= j; p++)
        if (f[c][p]) c = p + 1;
      if (c == j + 1) f[i][j] = 1;
    }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j += 2)
      if (f[i][j]) ans++;
  cout << ans << '\n';
  return 0;
}