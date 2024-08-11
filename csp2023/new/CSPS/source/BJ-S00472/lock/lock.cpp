#include <iostream>
#include <cstdio>

using namespace std;

int n, c, ans, a[10][6], b[114][6], cnt[114];

void fil(int ad, int bd) {
  for(int i = 1; i <= 5; i++)
    b[bd][i] = a[ad][i];
}

void fin(int p) {
  for(int i = 1; i <= c; i++) {
    for(int j = 1; j <= 5; j++)
      if(a[p][j] != b[i][j]) goto fail;
    cnt[i]++;
    fail:;
  }
}

int main() {
  freopen("lock.in", "r", stdin);
  freopen("lock.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= 5; j++)
      cin >> a[i][j];

  for(int i = 1; i <= 5; i++)
    for(int j = 0; j < 10; j++) {
      a[1][i] = (a[1][i] + 1) % 10;
      if(j != 9) c++, fil(1, c);
    }

  for(int i = 1; i <= 4; i++)
    for(int j = 0; j < 10; j++) {
      a[1][i] = (a[1][i] + 1) % 10, a[1][i+1] = (a[1][i+1] + 1) % 10;
      if(j != 9) c++, fil(1, c);
    }

  // for(int i = 1; i <= c; i++)
  //   for(int j = 1; j <= 5; j++)
  //     cout << b[i][j] << " \n"[j == 5];

  for(int k = 2; k <= n; k++) {
    for(int i = 1; i <= 5; i++)
      for(int j = 0; j < 10; j++) {
        a[k][i] = (a[k][i] + 1) % 10;
        if(j != 9) fin(k);
      }

    for(int i = 1; i <= 4; i++)
      for(int j = 0; j < 10; j++) {
        a[k][i] = (a[k][i] + 1) % 10, a[k][i+1] = (a[k][i+1] + 1) % 10;
        if(j != 9) fin(k);
      }
  }

  for(int i = 1; i <= c; i++)
    if(cnt[i] == n - 1) ans++;
  cout << ans << '\n';
}