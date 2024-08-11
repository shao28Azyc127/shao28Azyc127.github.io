#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
int x[N], y[N], arr[N], c, n, m, q;
bool ans, chk;

void dfs(int step) {
  if (ans) return;
  if (step == n) {
    int a = 1, b = 1;
    for (int i = 1; i <= max(n, m); i++) {
      if (i > n) arr[i] = i;
      //cout << x[i] << " " << y[arr[i]] << endl;
      if (i > 1 && arr[i] - arr[i - 1] > 1) {
        for (int j = arr[i] - 1; j > arr[i - 1]; j--) {
          int al = 1, bl = 1, ar = 1, br = 1;
          for (int p = arr[i] - 1; p > arr[i - 1]; p--) {
            if (p <= j && x[i - 1] <= y[j]) {
              al = 0;
            } if (p > j && x[i] >= y[j]) {
              bl = 0;
            }if (p <= j && x[i - 1] >= y[j]) {
              ar = 0;
            } if (p > j && x[i - 1] >= y[j]) {
              br = 0;
            } 
          }
          a &= (al && ar); 
          b &= (bl && br);
        }
      }
      if (x[i] <= y[arr[i]]) {
        a = 0;
      }
      if (x[i] >= y[arr[i]]) {
        b = 0;
      }
    }
    if (a == 1 || b == 1) ans = 1;
    return;
  }
  if (arr[step] > m) return;
  for (int i = arr[step]; i <= m; i++) {
    //if ((x[step] > y[step]) ^ chk == 0) {
      arr[step + 1] = i;
      dfs(step + 1);
      arr[step + 1] = 0;
    //}
  }
}
void solve() {
  ans = 0;
  memset(arr, 0, sizeof(arr));
  arr[1] = 1;
  if (x[1] == y[1]) {
    cout << '0';
    return;
  }
  if (n == m && n == 1) {
    cout << '1';
  }
  chk = (x[1] > y[1]);
  dfs(1);
  cout << ans;
}

int main() {
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> c >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> y[i];
  }
  solve();
  for (int i = 1; i <= q; i++) {
    int kx, ky; cin >> kx >> ky;
    for (int j = 1; j <= kx; j++) {
      int px, py; cin >> px >> py; x[px] = py;
    }
    for (int j = 1; j <= ky; j++) {
      int px, py; cin >> px >> py; y[px] = py;
    }
    // for (int i = 1; i <= n; i++) {
    //   cout << x[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= m; i++) {
    //   cout << y[i] << " ";
    // }
    // cout << endl;
    solve();
  }
  cout << endl;
  return 0;
}