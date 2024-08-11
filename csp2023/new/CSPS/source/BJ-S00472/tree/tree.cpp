#include <iostream>
#include <vector>
#define N 100005
#define ll long long

using namespace std;

int n;
ll a[N], b[N], c[N], ans;
vector<int> e[N];

namespace chain {
  bool judge() {
    for(int i = 1; i < n; i++) {
      //cerr << i << ' ' << e[i].size() << ' ' << e[i][0] << '\n';
      if(e[i].size() != 1 || e[i][0] != i + 1) return false;
    }
    return true;
  }

  ll erf(int x) {
    ll l = 1, r = 1000000000, m;
    while(r - l > 5) {
      m = (l + r) / 2;
      if(m * b[x] + m * (m+1) / 2 * c[x] < a[x]) l = m;
      else if(m * b[x] + m * (m+1) / 2 * c[x] > a[x]) r = m;
      else return m;
    }
    for(int i = l; i <= r; i++)
      if(i * b[x] + i * (i+1) / 2 * c[x] >= a[x]) return i;
    return -114;
  }

  void mian() {
    for(int i = 1; i <= n; i++) {
      if(c[i] <= 0) ans = max(ans, i - 1 + ((a[i] % b[i]) ? (a[i] / b[i] + 1) : (a[i] / b[i])));
      else ans = max(ans, i - 1 + erf(i));
    }
    cout << ans << '\n';
  }
}

int main() {
  freopen("tree.in", "r", stdin);
  freopen("tree.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> a[i] >> b[i] >> c[i];
  for(int i = 1, u, v; i < n; i++)
    cin >> u >> v, e[u].push_back(v);

  if(chain::judge()) chain::mian();
  else cout << n << '\n';
}