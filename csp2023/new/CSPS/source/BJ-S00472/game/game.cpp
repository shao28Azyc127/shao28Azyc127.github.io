#include <iostream>
#include <cstdio>

using namespace std;

int n, f[8005][8005];
char s[2000005];
long long ans;

int main() {
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> s+1;

  for(int i = 1, r; i <= n; i++) {
    for(int l = 1; l+i-1 <= n; l++) {
      r = l + i - 1;
      if(l == r) continue;
      else if(r - l == 1) {if(s[l] == s[r]) f[l][r] = 1;}
      else {
        if(s[l] == s[r] && f[l+1][r-1]) f[l][r] = 1;
        else for(int k = l+1; k < r; k++)
          if(f[l][k] && f[k+1][r]) f[l][r] = 1;
      }
    }
  }

  for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++)
      if(f[i][j]) ans++;
  cout << ans << '\n';
}