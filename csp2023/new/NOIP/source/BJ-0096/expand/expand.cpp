#include <iostream>
#include <algorithm>
using namespace std;

int caseid, n, m, q;
int x[1 + 500000];
int y[1 + 500000];
int px[1 + 500000];
int py[1 + 500000];
int vx[1 + 500000];
int vy[1 + 500000];

int f[2][1 + 500000];

int cal() {
  for(int j = 1; j <= m; j += 1) {
    f[0][j] = 0;
  }
  f[0][0] = 1;
  if(x[1] == y[1]) return 0;
  if(x[n] == y[m]) return 0;
  if(x[1] < y[1]) {
    if(x[n] > y[m]) return 0;
    for(int i = 1; i <= n; i += 1) {
      int ii = i & 1;
      f[ii][0] = 0;
      for(int j = 1; j <= m; j += 1) {
        f[ii][j] = (x[i] < y[j]) && (f[!ii][j] | f[!ii][j - 1] | f[ii][j - 1]);
      }
    }
    return f[n & 1][m];
  }
  else {
    if(x[n] < y[m]) return 0;
    for(int i = 1; i <= n; i += 1) {
      int ii = i & 1;
      f[ii][0] = 0;
      for(int j = 1; j <= m; j += 1) {
        f[ii][j] = (x[i] > y[j]) && (f[!ii][j] | f[!ii][j - 1] | f[ii][j - 1]);
      }
    }
    return f[n & 1][m];
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
  
  cin >> caseid >> n >> m >> q;
  for(int i = 1; i <= n; i += 1) {
    cin >> x[i];
  }
  for(int j = 1; j <= m; j += 1) {
    cin >> y[j];
  }
  
  cout << cal();
  for(int t = 1; t <= q; t += 1) {
    int kx, ky; cin >> kx >> ky;
    for(int i = 1; i <= kx; i += 1) {
      cin >> px[i] >> vx[i];
      swap(x[px[i]], vx[i]);
    }
    for(int j = 1; j <= ky; j += 1) {
      cin >> py[j] >> vy[j];
      swap(y[py[j]], vy[j]);
    }
    cout << cal();
    for(int i = 1; i <= kx; i += 1) {
      swap(x[px[i]], vx[i]);
    }
    for(int j = 1; j <= ky; j += 1) {
      swap(y[py[j]], vy[j]);
    }
  }
  cout << "\n";
  
  return 0;
}
