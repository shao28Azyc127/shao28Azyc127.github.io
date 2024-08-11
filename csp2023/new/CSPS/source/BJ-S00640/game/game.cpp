#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstring>

using namespace std;

/*
a b a a b a b a b b a a b b a b a a
*/

const int N = 8000 + 5;
bool f[N][N];
int n;
char s[N];

int main() {
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n;
  cin >> s + 1;

  int ans = 0;
  for(int len = 2; len <= (n / 2) * 2; len += 2) {
    for(int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      if(s[i] == s[j]) {
	if(len == 2) {
	  f[i][j] = true;
	  ans++;
	}
	else {
	  if(f[i + 1][j - 1])
	    f[i][j] = true, ans++;
	}
      }
      else {
	for(int k = i + 1; k < j - 1; k += 2)
	  f[i][j] |= f[i][k] & f[k + 1][j];
	if(f[i][j]) ans++;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
