#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+9;
int n, last[8009];
bool match[8009];
char ch[N];
void solve1() {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    stack<char> s; s.push(ch[i]);
    for (int j = i + 1; j <= n; j++) {
      if (!s.size() || s.top() != ch[j]) s.push(ch[j]);
      else s.pop();
      if (s.size() == 0) ans++;
    } 
  }
  cout << ans << endl;
}

signed main() {
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  scanf("%lld", &n); scanf("%s", ch + 1);
  if (n <= 8000) {solve1(); return 0;}
  return 0;
}