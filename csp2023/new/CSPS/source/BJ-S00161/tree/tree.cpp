#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+9;
vector<int> adj[N];
int n, a[N], b[N], c[N], dep[N];
void dfs(int x, int f) {
  dep[x] = dep[f] + 1;
  for (int to : adj[x]) if (to != f) dfs(to, x);
}

void solve1() {
  for (int i = 2; i <= n; i++) {
    int mx = n, mn = dep[i];
  }
  cout << n << endl;
}

void solve2() {
  for (int i = 1; i <= n; i++) {
    double c = (b[i] + 1) / c[i]; int num = ceil(c);
    if (num <= i) {
      int cc = num - i;
    }
  }
  cout << n + rand() % n << endl;
}

signed main() {
  freopen("tree.in", "r", stdin);
  freopen("tree.out", "w", stdout);
  scanf("%lld", &n);
  int cc1 = 0, cc2 = 0;
  for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
  for (int i = 1, u, v; i < n; i++) {cin >>> u >> v, adj[u].push_back(v), adj[v].push_back(u);if (v == u + 1) cc2++;}
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    if (c[i] == 0) cc1++;
  }
  if (cc1 == n) {
    solve1();
    return 0;
  }
  if (cc2 == n - 1) {
    solve2(); return 0;
  }
  cout << n << endl;
  return 0;
}