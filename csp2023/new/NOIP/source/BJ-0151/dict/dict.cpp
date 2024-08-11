#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 3'000;

int n, m;
char s[N + 10][N + 10];

int main() {
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    sort(s[i] + 1, s[i] + m + 1, [](char x, char y) { return x > y; });
  }
  for (int i = 1; i <= n; i++) {
    sort(s[i] + 1, s[i] + m + 1);
    bool ok = 1;
    for (int j = 1; j <= n; j++)
      if (j != i) {
        if (!lexicographical_compare(s[i] + 1, s[i] + m + 1, s[j] + 1, s[j] + m + 1)) {
          ok = 0;
          break;
        }
      }
    if (!ok) printf("0");
    else printf("1");
    sort(s[i] + 1, s[i] + m + 1, [](char x, char y) { return x > y; });
  }
  puts("");
  return 0;
}