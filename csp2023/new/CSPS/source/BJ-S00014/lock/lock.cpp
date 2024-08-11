#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cur[1 + 5];
int b[1 + 5];
int a[1 + 8][1 + 5];

int md(int x) { return (x % 10 + 10) % 10; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("lock.in", "r", stdin);
  freopen("lock.out", "w", stdout);
  
  cin >> n;
  for(int i = 1; i <= n; i += 1) {
    for(int j = 1; j <= 5; j += 1) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for(int A = 0; A <= 9; A += 1) {
    for(int B = 0; B <= 9; B += 1) {
      for(int C = 0; C <= 9; C += 1) {
        for(int D = 0; D <= 9; D += 1) {
          for(int E = 0; E <= 9; E += 1) {
            cur[1] = A;
            cur[2] = B;
            cur[3] = C;
            cur[4] = D;
            cur[5] = E;
            int flg = 1;
            for(int i = 1; i <= n; i += 1) {
              int cnt = 0;
              for(int j = 1; j <= 5; j += 1) {
                if(cur[j] != a[i][j]) {
                  cnt += 1; b[j] = 1;
                }
                else b[j] = 0;
              }
              if(cnt == 0 || cnt > 2) { flg = 0; break; }
              if(cnt == 1) continue;
              int ok = 0;
              for(int j = 2; j <= 5; j += 1) {
                if(b[j] && b[j - 1]) {
                  ok = 1;
                  if(md(cur[j] - cur[j - 1]) != md(a[i][j] - a[i][j - 1])) {
                    ok = 0;
                  }
                }
              }
              if(!ok) { flg = 0; break; }
            }
            if(flg) ans += 1;
          }
        }
      }
    }
  }
  cout << ans << "\n";
  
  return 0;
}
