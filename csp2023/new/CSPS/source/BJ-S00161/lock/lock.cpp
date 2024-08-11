#include <bits/stdc++.h>
#define add(x, y) (x = (x + y) % 10)
using namespace std;
const int MOD = 10;
int mp[19][9], n, id[1000009], ans = 0;
int calc(int i) {
  int cur = 0;
  for (int j = 1; j <= 5; j++) cur = cur * 10 + mp[i][j];
  return cur;
}

int main() {
  freopen("lock.in", "r", stdin);
  freopen("lock.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= 5; j++) cin >> mp[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      for (int k = 1; k <= 10; k++) {
        int tmp = mp[i][j];
        add(mp[i][j], k);
        id[calc(i)]++;
        //if (id[calc(i)] == n) ans++;
        mp[i][j] = tmp;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 4; j++) {
      int k = j + 1;
      for (int l = 1; l <= 10; l++) {
        int tmp1 = mp[i][j], tmp2 = mp[i][k];
        add(mp[i][j], l); add(mp[i][k], l);
        id[calc(i)]++;
        //if (id[calc(i)] == n) ans++;
        mp[i][j] = tmp1, mp[i][k] = tmp2;
      }
    }
  }

  for (int i = 0; i < 1000000; i++) {
    if (id[i] == n) ans++;
  }
  cout << ans << endl;

  return 0;
}