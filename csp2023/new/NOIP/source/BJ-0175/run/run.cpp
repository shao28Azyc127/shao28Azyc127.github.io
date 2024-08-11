#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+9;
int n, m, k, d, dp[N][2];
struct node {
  int x, y, v;
  friend bool operator < (node a, node b) {
    return a.y > b.y;
  }
} op[N];
vector<node> g[N];
vector<vector<int>> v;
set<int> s;
void solve() {
  memset(dp, 0xcf, sizeof(dp));
  s.clear();
  for (int i = 1; i < N; i++) g[i].clear();
  cin >> n >> m >> k >> d;
  for (int i = 1; i <= m; i++) {
    cin >> op[i].x >> op[i].y >> op[i].v;
    if (op[i].y <= k) g[op[i].x].push_back(op[i]);
  }
  for (int i = 1; i < N; i++) sort(g[i].begin(), g[i].end());
  // v.resize(s.size() + 2);
  // for (int i = 1; i < N; i++) {
  //   if (g[i].size()) v[i].resize(g[i].size() + 2);
  //   int sum = 0;
  //   v[i][0] = g[i][0].v;
  //   for (int j = 0; j < g[i].size(); j++) {
  //     v[i][j + 1] = v[i][j] + g[i][j].v;
  //   }
  // }
  dp[0][0] = dp[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]); dp[i][0] = 0;
    for (int j = max(0ll, i - k); j < i; j++) {
      int mx = dp[j][1] - d * (i - j);
      for (int l = i; l > j; l--) {
        for (node p : g[l]) {
          if (p.x - p.y + 1 <= j) continue;
          mx += p.v;
        }
      }
      dp[i][0] = max(dp[i][0], mx);
      //cout << i << " " << j << " " << mx << endl;
    }
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
}

signed main() {
  double bg = clock();
  freopen("run.in", "r", stdin);
  freopen("run.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(0);
  int c, t; cin >> c >> t;
  while (t--) {
    solve();
  }
  double ed = clock(); 
  //cerr << (ed - bg) / CLOCKS_PER_SEC << endl;

  return 0;
}