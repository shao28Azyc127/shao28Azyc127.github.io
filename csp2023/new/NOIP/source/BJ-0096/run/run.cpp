#include <iostream>
#include <algorithm>
#include <utility>
#include <tuple>
#include <vector>
using namespace std;

int caseid, tt;
int n, m, k, d;
struct Plan {
  int l, r; long long int v;
  bool operator<(const Plan &uu) const {
    if(r != uu.r) return r < uu.r;
    return l < uu.l;
  }
} p[1 + 100000];

int lsh[1 + 400000]; int lsh_cnt;
int disc(int x) { return lower_bound(&lsh[1], &lsh[lsh_cnt + 1], x) - &lsh[0]; }

int mq[1 + 400000]; int mqL, mqR;
long long int f[1 + 400000];

vector<int> st[1 + 400000];
vector<int> ed[1 + 400000];

long long int pot[1 + 400000];

/*long long int bit[1 + 400000];
inline void upd(int u, long long int k) {
  while(1 <= u && u <= lsh_cnt) { bit[u] += k; u += u & -u; }
}
inline long long int pfx(int u) {
  long long int res = 0;
  while(1 <= u && u <= lsh_cnt) { res += bit[u]; u -= u & -u; }
  return res;
}
inline long long int qry(int u) {
  return pfx(lsh_cnt) - pfx(u - 1);
}*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("run.in", "r", stdin);
  freopen("run.out", "w", stdout);
  
  cin >> caseid >> tt;
  while(tt--) {
    cin >> n >> m >> k >> d;
    lsh_cnt = 0;
    for(int i = 1; i <= m; i += 1) {
      int x, y; cin >> x >> y >> p[i].v;
      p[i].l = x - y + 1;
      p[i].r = x;
      lsh[++lsh_cnt] = p[i].l;
      lsh[++lsh_cnt] = p[i].r;
    }
    // lsh
    sort(&lsh[1], &lsh[lsh_cnt + 1]);
    lsh_cnt = unique(&lsh[1], &lsh[lsh_cnt + 1]) - &lsh[1];
    for(int i = 1; i <= m; i += 1) {
      p[i].l = disc(p[i].l);
      p[i].r = disc(p[i].r);
    }
    sort(&p[1], &p[m + 1]);
    // init
    for(int t = 0; t <= lsh_cnt; t += 1) {
      pot[t] = 0;
      st[t].clear();
      ed[t].clear();
      f[t] = 0;
    }
    for(int i = 1; i <= m; i += 1) {
      st[p[i].l].emplace_back(i);
      ed[p[i].r].emplace_back(i);
    }
    
    // BF
    for(int t = 1; t <= lsh_cnt; t += 1) {
      if((int)ed[t].size()) {
        for(int i : ed[t]) {
          pot[p[i].l] += p[i].v;
        }
        long long int sum = 0;
        for(int s = t; s >= 1; s -= 1) {
          if((lsh[t] - lsh[s] + 1) > k) break;
          sum += pot[s];
          long long int cur = sum - 1LL * (lsh[t] - lsh[s] + 1) * d;
          if(lsh[s - 1] + 1 < lsh[s]) cur += f[s - 1];
          else if(s > 1 && lsh[s - 2] + 1 < lsh[s]) cur += f[s - 2];
          f[t] = max(f[t], cur);
        }
      }
      f[t] = max(f[t], f[t - 1]);
    }
    
    cout << f[lsh_cnt] << "\n";
  }
  
  return 0;
}
