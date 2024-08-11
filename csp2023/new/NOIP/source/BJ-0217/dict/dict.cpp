#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 3005

using namespace std;

int n, m;
char s[N][N], ma[N], mi[N];

int pd(int x) {
  for(int i = 1; i <= n; i++)
    if(i != x && mi[x] >= ma[i]) return 0;
  return 1;
}

int main() {
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> s[i];
    ma[i] = *max_element(s[i], s[i]+m);
    mi[i] = *min_element(s[i], s[i]+m);
  }

  for(int i = 1; i <= n; i++) cout << pd(i);
}