#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int caseid, tt;
int n, m;
int val[1 + 100003];
int vis[1 + 100000];

int fa[1 + 100000];
int siz[1 + 100000];
int root(int u) { return fa[u] == u ? u : fa[u] = root(fa[u]); }
int ans;
int cur;
int sgn;

int dfs(int u) {
  if(vis[u] == 2) return 0;
  if(vis[u] == 1) {
    cur = u;
    sgn = 1;
    return 1;
  }
  vis[u] = 1;
  if(abs(val[u]) == n + 3) {
    ans += siz[root(u)];
    return 0;
  }
  if(abs(val[u]) <= n) {
    if(dfs(abs(val[u]))) {
      vis[u] = 2;
      if(val[u] < 0) sgn = -sgn;
      if(u == cur) {
        if(sgn == -1) {
          ans += siz[root(u)];
        }
        return 0;
      }
      else {
        return 1;
      }
    }
  }
  vis[u] = 2;
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("tribool.in", "r", stdin);
  freopen("tribool.out", "w", stdout);
  
  cin >> caseid >> tt;
  while(tt--) {
    cin >> n >> m;
    ans = 0;
    for(int i = 1; i <= n; i += 1) {
      val[i] = i;
      vis[i] = 0;
      fa[i] = i;
      siz[i] = 1;
    }
    val[n + 1] = n + 1;
    val[n + 2] = n + 2;
    val[n + 3] = n + 3;
    for(int t = 1; t <= m; t += 1) {
      string op; cin >> op;
      if(op[0] == '+') {
        int u, v; cin >> u >> v;
        val[u] = val[v];
      }
      else if(op[0] == '-') {
        int u, v; cin >> u >> v;
        val[u] = -val[v];
      }
      else {
        int u; cin >> u;
        if(op[0] == 'T') {
          val[u] = n + 1;
        }
        else if(op[0] == 'F') {
          val[u] = n + 2;
        }
        else {
          val[u] = n + 3;
        }
      }
    }
    //
    for(int i = 1; i <= n; i += 1) {
      if(abs(val[i]) <= n) {
        if(root(i) != root(abs(val[i]))) {
          siz[root(abs(val[i]))] += siz[root(i)];
          fa[root(i)] = root(abs(val[i]));
        }
      }
    }
    for(int i = 1; i <= n; i += 1) {
      if(!vis[i]) {
        cur = 0;
        sgn = 0;
        dfs(i);
      }
    }
    cout << ans << "\n";
  }
  
  return 0;
}
