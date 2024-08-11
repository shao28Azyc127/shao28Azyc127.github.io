#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int c, t, n, m, k, d;
long long f[1005][1005];
struct node {
  int x, y, v;
  friend bool operator <(node &A, node &B) {
    if(A.x != B.x) return A.x < B.x;
    return A.y < B.y;
  }
} a[100005];

int main() {
  freopen("run.in", "r", stdin);
  freopen("run.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> c >> t;
  while(t--) {
    cin >> n >> m >> k >> d;
    /*for(int i = 1; i <= n; i++)
      for(int j = 1; j <= k; j++)
        f[i][j] = 0;*/
    memset(f, 0, sizeof f);
    for(int i = 1; i <= m; i++)
      cin >> a[i].x >> a[i].y >> a[i].v;
    sort(a+1, a+m+1);

    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
      while(l <= m && a[l].x < i) l++;
      f[i][0] = *max_element(f[i-1], f[i-1]+min(i, k+1));
      r = l;
      for(int j = 1, sm = 0; j <= min(i, k); j++) {
        f[i][j] = f[i-1][j-1] - d;
        while(r <= m && a[r].x == i && a[r].y <= j) sm += a[r].v, r++;
        f[i][j] += sm;
      }
      l = r;
    }

    cout << *max_element(f[n], f[n]+n+1) << '\n';
  }
}