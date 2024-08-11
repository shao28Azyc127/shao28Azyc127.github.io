#include <iostream>
#include <algorithm>
#include <vector>
#define f first
#define g second

using namespace std;

/*
1  2  3  4  5  6  7  8  9  10
-2 7  9  -3 -4 -5 10 -6 -8 2
*/

const int N = 1e5 + 5;
int c, t;
int n, m;
pair<int, bool> E[N];
vector<pair<int, bool>> E1[N];
bool unk[N];
int vis[N], cnt[N];

/*
void dfs1(int u, int cc) {
  vis[u] = 1;
  int v = E[u].f;
  bool w = E[u].g;
  cout << u << ' ' << v << ' ' << cc << ' ' << w << endl;
  
  if(v == n + 1)
    unk[u] = unk[v] = true;
  else if(v == 0)
    unk[u] = unk[v] = false;
  else if(vis[v] == 1) {
    if((cc - cnt[v]) & 1) {
      unk[u] = unk[v] = true;
    }
  }
  else if(vis[v] == 2)
    unk[u] = unk[v];
  else {
    cnt[v] = cc;
    dfs1(v, cc - (~w));
    unk[u] = unk[v];
  }
  vis[u] = 2;
}
*/

int main() {
  freopen("tribool.in", "r", stdin);
  freopen("tribool.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> c >> t;
  while(t--) {
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++) {
      char v; cin >> v;
      if(v == '+' || v == '-') {
	int i, j; cin >> i >> j;
	if(v == '+') E[i] = {j, true};
	else E[i] = {j, false};
      }
      else {
	int i; cin >> i;
	if(v == 'T') E[i] = {0, true};
	if(v == 'F') E[i] = {0, false};
	if(v == 'U') E[i] = {n + 1, true};
      }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
      if(E[i].f == n + 1) ans++;
    }
    cout << ans << '\n';
    
    /*
    for(int i = 1; i <= n; i++) {
      E1[E[i].f].push_back({i, E[i].g});
      cout << i << ' ' << E[i].g << ' ' << E[i].f << endl;
    }

    //dfs(n + 1);
    
    for(int i = 1; i <= n; i++) {
      if(!vis[i]) dfs1(i, 0);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
      ans += unk[i];
    cout << ans << '\n';

    for(int i = 1; i <= n; i++)
      E[i] = {0, true};
    */
    for(int i = 0; i <= n + 1; i++) {
      E1[i].clear();
      unk[i] = false; vis[i] = 0; cnt[i] = 0;
    }
  }
  
  return 0;
}
