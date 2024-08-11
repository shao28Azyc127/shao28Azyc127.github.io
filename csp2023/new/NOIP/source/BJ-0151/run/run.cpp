#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

using ll = long long;

namespace sub2 {

  const int N = 200'010;

  struct Node { ll mx, atag; };

  int n, m, k, d;
  Node t[N * 4 + 10];
  vector<pair<int, int>> a[N + 10];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

  inline void pushup(int i) { t[i].mx = max(t[ls(i)].mx, t[rs(i)].mx); }
  inline void pusha(int i, ll atag) {
    t[i].mx += atag, t[i].atag += atag;
  }
  inline void pushdown(int i) {
    if (t[i].atag) {
      pusha(ls(i), t[i].atag);
      pusha(rs(i), t[i].atag);
      t[i].atag = 0;
    }
  }

  void modify(int i, int l, int r, int ql, int qr, ll x) {
    if (ql <= l && r <= qr) return pusha(i, x), void();
    int mid = (l + r) >> 1;
    pushdown(i);
    if (ql <= mid) modify(ls(i), l, mid, ql, qr, x);
    if (qr > mid) modify(rs(i), mid + 1, r, ql, qr, x);
    pushup(i);
  }

  ll query(int i, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return t[i].mx;
    int mid = (l + r) >> 1; ll res = 0;
    pushdown(i);
    if (ql <= mid) res = max(res, query(ls(i), l, mid, ql, qr));
    if (qr > mid) res = max(res, query(rs(i), mid + 1, r, ql, qr));
    return res;
  }

#undef ls
#undef rs

  void mainimpl() {
    scanf("%d%d%d%d", &n, &m, &k, &d);
    for (int i = 1; i <= m; i++) {
      int x, y, v; scanf("%d%d%d", &x, &y, &v);
      a[x].emplace_back(y, v);
    }
    int shift = n + 1;
    for (int i = 1; i <= n; i++) {
      ll x = query(1, 1, 2 * (n + 1), shift, shift + k);
      modify(1, 1, 2 * (n + 1), shift - 1, shift - 1, x);
      modify(1, 1, 2 * (n + 1), shift, shift + k - 1, -d);
      for (auto x : a[i]) {
        int y = x.first, v = x.second;
        modify(1, 1, 2 * (n + 1), shift - 1 + y, shift - 1 + k, v);
      }
      shift--;
    }
    printf("%lld\n", query(1, 1, 2 * (n + 1), shift, shift + k));
  }

  void main() {
    int T; scanf("%d", &T);
    while (T--) {
      for (int i = 1; i <= n; i++) a[i].clear();
      for (int i = 1; i <= 8 * n; i++) t[i].mx = t[i].atag = 0;
      mainimpl();
    }
  }

} // namespace sub2

int main() {
  freopen("run.in", "r", stdin);
  freopen("run.out", "w", stdout);
  int taskid; scanf("%d", &taskid);
  if (taskid <= 14) sub2::main();
  return 0;
}