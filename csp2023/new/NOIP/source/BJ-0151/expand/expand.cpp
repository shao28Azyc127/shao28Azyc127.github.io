#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 500'000;

int taskid, n, m, q, a[N + 10], b[N + 10];

namespace sub1 {

  const int N = 2'000;
  constexpr int inf = 0x3f3f3f3f;

  int f[N + 10], sum[N + 10];
  int aa[N + 10], bb[N + 10];

  void mainimpl() {
    if (a[1] == b[1] || a[n] == b[m]) return printf("0"), void();
    if ((a[1] < b[1]) ^ (a[n] < b[m])) return printf("0"), void();
    bool flg = a[1] > b[1];
    int mn = inf, mx = ~inf;
    for (int j = 1; j <= m; j++) {
      mn = min(mn, b[j]), mx = max(mx, b[j]);
      if (flg ? a[1] > mx : a[1] < mn) f[j] = 1;
      else f[j] = 0;
    }
    sum[0] = 0;
    for (int j = 1; j <= m; j++)
      sum[j] = sum[j - 1] + f[j];
    for (int i = 2; i <= n; i++) {
      int k = -1;
      for (int j = 1; j <= m; j++) {
        if (!(flg ? a[i] > b[j] : a[i] < b[j])) k = -1;
        else if (k == -1) k = j;
        if (k == -1) { f[j] = 0; continue; }
        int r = k == 1 ? 0 : k - 2;
        if (sum[j] - sum[r] > 0) f[j] = 1;
        else f[j] = 0;
      }
      sum[0] = 0;
      for (int j = 1; j <= m; j++)
        sum[j] = sum[j - 1] + f[j];
    }
    printf("%d", f[m]);
  }

  void main() {
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]), aa[i] = a[i];
    for (int j = 1; j <= m; j++)
      scanf("%d", &b[j]), bb[j] = b[j];
    mainimpl();
    for (int k = 1; k <= q; k++) {
      for (int i = 1; i <= n; i++) a[i] = aa[i];
      for (int j = 1; j <= m; j++) b[j] = bb[j];
      int kx, ky; scanf("%d%d", &kx, &ky);
      while (kx--) {
        int p, x; scanf("%d%d", &p, &x);
        a[p] = x;
      }
      while (ky--) {
        int p, x; scanf("%d%d", &p, &x);
        b[p] = x;
      }
      for (int i = 0; i <= m; i++) f[i] = sum[i] = 0;
      mainimpl();
    }
    puts("");
  }

} // namespace sub1

int main() {
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
  scanf("%d%d%d%d", &taskid, &n, &m, &q);
  if (taskid <= 7) sub1::main();
  return 0;
}