#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int c, t, n, m;
void solve() {
  while (t--) {
    cin >> n >> m;
    int cc = 0;
    for (int i = 1; i <= m; i++) {
      char u; int v, w; cin >> u >> v; if (u == '+' || u == '-') cin >> w;
      if (u == 'T' || u == 'F') cc++;
    }
    cout << m - cc << "\n";
  }
}

int cv(char c) {
  if (c == 'T') return 0;
  if (c == 'F') return 1;
  if (c == 'U') return 2;
  if (c == '+') return 3;
  if (c == '-') return 4;
  return -1;
}

int arr[19], x[19];
struct node {
  int type, x1, x2, t;
} op[N];

void getarr(int cur) {
  for (int i = 1; i <= n; i++) {
    arr[i] = cur % 3; cur /= 3;
    //cout << arr[i] << " ";
  }
  //cout << endl;
}

int rev(int cur) {
  if (cur < 2) return 1 - cur;
  return cur;
}

void solve2() {
  while (t--) {
    cin >> n >> m;
    int ans = INT_MAX;
    for (int i = 1; i <= m; i++) {
      char u; int v, w; cin >> u >> v; w = 0;
      if (u == '+' || u == '-') cin >> w;
      op[i] = {cv(u), v, w};
    }
    int mx = pow(3, n) - 1;
    for (int i = 0; i <= mx; i++) {
      getarr(i);
      for (int j = 1; j <= n; j++) {
        x[j] = arr[j];
        //cout << arr[i] << " ";
      }
      //cout << endl;
      for (int j = 1; j <= m; j++) {
        if (op[j].type < 3) x[op[j].x1] = op[j].type;
        else if (op[j].type == 3) x[op[j].x1] = x[op[j].x2];
        else x[op[j].x1] = rev(x[op[j].x2]);
      }
      bool flg = true; int cc = 0;
      for (int j = 1; j <= n; j++) {
        if (x[j] != arr[j]) flg = false;
        cc += (x[j] == 2);
      }
      if (!flg) continue;
      // for (int j = 1; j <= n; j++) {
      //   cout << arr[j] << " ";
      // }
      // cout << endl;
      ans = min(ans, cc);
    }
    cout << ans << "\n";
  }
}

vector<int> adj[N];
int vis[N];
void dfs(int cur) {
  vis[cur] = 1;
  for (int to : adj[cur]) if (!vis[to]) dfs(to);
}

void dfs2(int cur) {
  if (vis[cur] == 2) return;
  vis[cur] = 2;
  for (int to : adj[cur]) dfs2(to);
}

void solve3() {
  while (t--) {
    cin >> n >> m;
    int ans = n, cc = 0;
    for (int i = 1; i < N; i++) {
      adj[i].clear(); vis[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      char u; int v, w; cin >> u >> v; w = 0;
      if (u == '+' || u == '-') cin >> w;
      op[i] = {cv(u), v, w, i};
      if (w != 0) {
        adj[v].push_back(w);
      }
    }
    for (int i = 1; i <= m; i++) {
      if (op[i].x2 == 0) {
        //cout << i << ":" << op[i].type << " " << op[i].x1 << " " << op[i].x2 << endl;
        vis[op[i].x1] = 1;
        //cout << op[i].x1 << " U" << endl;
        continue;
      } else if (vis[op[i].x2] == 1) {
        //cout << i << ":" << op[i].type << " " << op[i].x1 << " " << op[i].x2 << endl;
        vis[op[i].x1] = 1;
        //cout << op[i].x1 << " U from" << " " << op[i].x2 << endl;
        continue;
      }
      //cout << i << ":" << op[i].type << " " << op[i].x1 << " " << op[i].x2 << endl;
      //vis[op[i].x1] = 0;
      //cout << op[i].x1 << " T from" << " " << op[i].x2 << endl;
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 1) {
        dfs(i);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 1) {
        cc++;
      }
    }
    cout << cc << "\n";
  }
}

int main() {
  freopen("tribool.in", "r", stdin);
  freopen("tribool.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> c >> t;
  if (c == 3 || c == 4) {
    solve();
    return 0;
  }
  if (c == 1 || c == 2) {
    solve2();
    return 0;
  }

  if (c == 5 || c == 6) {
    solve3();
    return 0;
  }

  return 0;
}