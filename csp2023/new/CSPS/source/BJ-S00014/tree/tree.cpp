#include <iostream>
#include <algorithm>
#include <utility>
#include <tuple>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int n;
long long int a[1 + 100000];
long long int b[1 + 100000];
long long int c[1 + 100000];
vector<int> net[1 + 100000], tg;

long long int tsk[1 + 100000];
long long int lft[1 + 100000];
int vis[1 + 100000];

long long int take(long long int a, long long int b, long long int c, long long int up = 1000000000) {
  long long int res = 0;
  long long int L = 0, R = up;
  while(L <= R) {
    long long int mid = (L + R) >> 1;
    long long int grow = (b + c + b + c + mid) * mid / 2;
    if(grow >= a) res = mid, R = mid - 1;
    else L = mid + 1; 
  }
  return res;
}

int check(long long int mid) {
  for(int i = 1; i <= n; i += 1) {
    lft[i] = mid - tsk[i];
    if(lft[i] <= 0) return 0;
    vis[i] = 0;
  }
  set<pair<long long int, int>> buf;
  buf.insert({lft[1], 1});
  for(int i = 1; i <= n; i += 1) {
    int u = buf.begin()->second;
    buf.erase(buf.begin());
    if(lft[u] < i) return 0;
    vis[u] = 1;
    for(int e : net[u]) {
      if(vis[tg[e]]) continue;
      buf.insert({lft[tg[e]], tg[e]});
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("tree.in", "r", stdin);
  freopen("tree.out", "w", stdout);
  
  cin >> n;
  for(int i = 1; i <= n; i += 1) {
    cin >> a[i] >> b[i] >> c[i];
    long long int now = 0;
    tsk[i] = 0;
    if(c[i] >= 0) {
      tsk[i] = take(a[i], b[i], c[i]);
    }
    else {
      long long int ptdn = b[i] / -c[i];
      long long int bef = (b[i] + c[i] + b[i] + ptdn * c[i]) * ptdn / 2;
      bool too_big = (b[i] + c[i] + b[i] + ptdn * c[i]) > a[i] / ptdn * 2;
      if(too_big || bef >= a[i]) tsk[i] = take(a[i], b[i], c[i], ptdn);
      else {
        tsk[i] = ptdn;
        tsk[i] += a[i] - bef;
      }
    }
  }
  
  for(int i = 1; i < n; i += 1) {
    int u, v; cin >> u >> v;
    net[u].emplace_back(tg.size());
    tg.emplace_back(v);
    net[v].emplace_back(tg.size());
    tg.emplace_back(u);
  }
  
  long long int ans = -1;
  long long int L = 0, R = 1000000000;
  while(L <= R) {
    long long int mid = (L + R) >> 1;
    if(check(mid)) ans = mid, R = mid - 1;
    else L = mid + 1;
  }
  cout << ans << "\n";
  
  return 0;
}
