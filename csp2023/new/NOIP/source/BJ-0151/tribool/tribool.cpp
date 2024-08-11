#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 100'000;

struct Op { char op; int x, y; };

int taskid;

namespace sub1 {

  const int N = 10;

  int n, m; Op a[N + 10];
  int b[N + 10], c[N + 10];
  int ans = 100;

  inline int check() {
    for (int i = 1; i <= n; i++) c[i] = b[i];
    for (int i = 1; i <= m; i++) {
      if (a[i].op == 'T') c[a[i].x] = 1;
      else if (a[i].op == 'F') c[a[i].x] = 0;
      else if (a[i].op == 'U') c[a[i].x] = 2;
      else if (a[i].op == '+') c[a[i].x] = c[a[i].y];
      else {
        if (c[a[i].y] == 2) c[a[i].x] = 2;
        else c[a[i].x] = c[a[i].y] ^ 1;
      }
    }
    for (int i = 1; i <= n; i++)
      if (b[i] != c[i]) return -1;
    int res = 0;
    for (int i = 1; i <= n; i++)
      if (b[i] == 2) res++;
    return res;
  }

  void dfs(int x) {
    if (x == n + 1) {
      int tmp = check();
      if (tmp != -1) ans = min(ans, tmp);
      return;
    }
    b[x] = 0; dfs(x + 1);
    b[x] = 1; dfs(x + 1);
    b[x] = 2; dfs(x + 1);
  }

  void mainimpl() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
      char s[5];
      scanf("%s", s);
      a[i].op = s[0];
      scanf("%d", &a[i].x);
      if (a[i].op == '+' || a[i].op == '-') scanf("%d", &a[i].y);
    }
    ans = 100;
    dfs(1);
    printf("%d\n", ans);
  }

  void main() {
    int T; scanf("%d", &T);
    while (T--) mainimpl();
  }
  
} // namespace sub1

namespace sub2 {

  const int N = 100'000;

  int n, m; Op a[N + 10];
  bool vis[N + 10];

  void mainimpl() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
      char s[5];
      scanf("%s", s);
      a[i].op = s[0];
      scanf("%d", &a[i].x);
      if (a[i].op == '+' || a[i].op == '-') scanf("%d", &a[i].y);
    }
    int cnt = 0;
    for (int i = m; i >= 1; i--) {
      char op = a[i].op; int x = a[i].x;
      if (vis[x]) continue;
      vis[x] = 1;
      if (op == 'U') cnt++;
    }
    printf("%d\n", cnt);
  }

  void main() {
    int T; scanf("%d", &T);
    while (T--) {
      for (int i = 1; i <= n; i++) vis[i] = 0;
      mainimpl();
    }
  }

} // namespace sub2

int main() {
  freopen("tribool.in", "r", stdin);
  freopen("tribool.out", "w", stdout);
  scanf("%d", &taskid);
  if (taskid <= 2) sub1::main();
  else if (taskid <= 4) sub2::main();
  return 0;
}