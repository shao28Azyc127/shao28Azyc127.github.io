#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 2005;
int a[N], b[N];
int a1[N], b1[N];
bool dp[N][N];
int c, n, m, q;

void solve(bool f) {
  memset(dp, false, sizeof dp);
  dp[0][0] = true;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if((a[i] < b[j]) != f || a[i] == b[j])
	continue;
      dp[i][j] |= (dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1]);
    }
  }
}

int main() {
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> c >> n >> m >> q;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    a1[i] = a[i];
  }
  for(int j = 1; j <= m; j++) {
    cin >> b[j];
    b1[j] = b[j];
  }

  bool f = (a[1] < b[1]);
  solve(f);
  cout << dp[n][m];

  while(q--) {
    int kx, ky; cin >> kx >> ky;
    for(int i = 1; i <= kx; i++) {
      int p, v; cin >> p >> v;
      a[p] = v;
    }
    for(int j = 1; j <= ky; j++) {
      int p, v; cin >> p >> v;
      b[p] = v;
    }
    
    bool f = (a[1] < b[1]);
    solve(f);
    cout << dp[n][m];

    for(int i = 1; i <= n; i++)
      a[i] = a1[i];
    for(int j = 1; j <= m; j++)
      b[j] = b1[j];
  }
  cout << '\n';
  return 0;
}
