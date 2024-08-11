#include <algorithm>
#include <cstdio>
using namespace std;

using ll = long long;

const int N = 8'000;

int n, a[N + 10];
char s[N + 10];
int stk[N + 10], top;

int main() {
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++)
    a[i] = s[i] - 'a' + 1;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    top = 0;
    for (int j = i; j <= n; j++) {
      if (top && stk[top] == a[j]) top--;
      else stk[++top] = a[j];
      if (top == 0) ans++;
    }
  }
  printf("%lld\n", ans);
  return 0;
}