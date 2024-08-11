#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string str;
long long int dp[1 + 8000][1 + 8000];


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  
  cin >> n >> str;
  str = " " + str;
  long long int ans = 0;
  for(int i = 1; i <= n; i += 1) {
    if(str[i] == str[i + 1]) {
      dp[i][i + 1] = 1;
      ans += 1;
    }
  }
  for(int len = 3; len <= n; len += 1) {
    for(int l = 1, r = len; r <= n; l++, r++) {
      if(str[l] == str[r]) {
        dp[l][r] |= (dp[l + 1][r - 1]);
      }
      for(int k = l; k < r; k += 1) {
        dp[l][r] |= (dp[l][k] & dp[k + 1][r]);
      }
      if(dp[l][r]) ans += 1;
    }
  }
  cout << ans << "\n";
  
  return 0;
}
