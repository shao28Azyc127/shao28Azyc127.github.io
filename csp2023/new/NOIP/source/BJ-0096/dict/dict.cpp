#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int n, m;
string a[1 + 3000];
int cnt[1 + 3000][26];
int L[1 + 3000];
int R[1 + 3000];

inline int check(int i, int j) {
  if(L[i] < R[j]) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);
  
  cin >> n >> m;
  for(int i = 1; i <= n; i += 1) {
    cin >> a[i];
    for(int j = 1; j <= m; j += 1) {
      cnt[i][a[i][j - 1] - 'a'] += 1;
    }
    L[i] = 0; while(cnt[i][L[i]] == 0) L[i] += 1;
    R[i] = 25; while(cnt[i][R[i]] == 0) R[i] -= 1;
  }
  for(int i = 1; i <= n; i += 1) {
    int flg = 1;
    for(int j = 1; j <= n; j += 1) {
      if(j == i) continue;
      if(!check(i, j)) flg = 0;
    }
    cout << flg;
  }
  cout << "\n";
  
  return 0;
}
