#include <algorithm>
#include <cstdio>
using namespace std;

inline void enc(int a[5], int &x) {
  x = 0;
  for (int i = 0; i < 5; i++)
    x = x * 10 + a[i];
}

inline void dec(int x, int a[5]) {
  for (int i = 0; i < 5; i++)
    a[i] = x % 10, x /= 10;
}

inline int calc1(int x, int y) {
  if (x < y) return y - x;
  else return y + 10 - x;
}

inline int calc2(int x, int y) {
  if (x > y) return x - y;
  else return x + 10 - y;
}

bool check(int a[5], int b[5]) {
  int cnt = 0;
  for (int i = 0; i < 5; i++)
    if (a[i] == b[i]) cnt++;
  if (cnt != 3 && cnt != 4) return 0;
  if (cnt == 4) return 1;
  int p = -1;
  for (int i = 0; i < 4; i++)
    if (a[i] != b[i] && a[i + 1] != b[i + 1]) {
      p = i;
      break;
    }
  if (p == -1) return 0;
  if (calc1(a[p], b[p]) == calc1(a[p + 1], b[p + 1])) return 1;
  if (calc2(a[p], b[p]) == calc2(a[p + 1], b[p + 1])) return 1;
  return 0;
}

int n, a[10][5], b[5];

int main() {
  freopen("lock.in", "r", stdin);
  freopen("lock.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 5; j++)
      scanf("%d", &a[i][j]);
  int ans = 0;
  for (int i = 0; i <= 99'999; i++) {
    dec(i, b);
    bool flg = 1;
    for (int i = 1; i <= n; i++)
      if (!check(a[i], b)) flg = 0;
    ans += flg;
  }
  printf("%d\n", ans);
  return 0;
}