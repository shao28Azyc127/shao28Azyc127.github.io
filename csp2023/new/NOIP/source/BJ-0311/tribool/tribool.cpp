#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
  char op;
  int x, y;
} q[N];
int C, T, n, m, ans;
char s[N], t[N];
inline char trans(char c) {
  if (c == 'U') return 'U';
  return c == 'T' ? 'F' : 'T';
}
void dfs(int u) {
  if (u > n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      t[i] = s[i];
      if (t[i] == 'U') cnt++;
    }
    for (int i = 1; i <= m; i++) {
      if (q[i].op == '+') t[q[i].x] = t[q[i].y];
      else if (q[i].op == '-') t[q[i].x] = trans(t[q[i].y]);
      else t[q[i].x] = q[i].op;
    }
    for (int i = 1; i <= n; i++)
      if (s[i] != t[i]) return;
    ans = min(ans, cnt);
    return;
  }
  s[u] = 'T', dfs(u + 1);
  s[u] = 'F', dfs(u + 1);
  s[u] = 'U', dfs(u + 1);
}
int main() {
  freopen("tribool.in", "r", stdin);
  freopen("tribool.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> C >> T;
  if (C == 1 || C == 2) {
    while (T--) {
      cin >> n >> m;
      for (int i = 1; i <= m; i++) {
        cin >> q[i].op >> q[i].x;
        if (q[i].op == '+' || q[i].op == '-') cin >> q[i].y;
      }
      ans = n, dfs(1);
      cout << ans << '\n';
    }
    return 0;
  }
  if (C == 3 || C == 4) {
    while (T--) {
      cin >> n >> m;
      for (int i = 1; i <= m; i++) {
        char op; int x; cin >> op >> x;
        s[x] = op;
      }
      ans = 0;
      for (int i = 1; i <= n; i++)
        if (s[i] == 'U') ans++;
      cout << ans << '\n';
    }
    return 0;
  }
  return 0;
}