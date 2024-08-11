#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
  string content;
  int type, l, r, len;//struct.0 byte.1 short.2 int.3 long.4
};
vector<node> v, s;
map<string, int> mp;
int chk(string s) {
  if (s[0] == 'b') return 1;
  if (s[0] == 's') return 2;
  if (s[0] == 'i') return 3;
  if (s[0] == 'l') return 4;
  return -1;
}
int n, l = 0, r = 0, cc = 0;
int nxt(int mx) {
  return (r = (r / mx + 1) * mx);
}

signed main() {
  freopen("struct.in", "r", stdin);
  freopen("struct.out", "w", stdout);
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    int op; scanf("%lld", &op);
    int maxlen = 0;
    // if (op == 1) {
    //   int m; node a;
    //   int maxlen = 0;
    //   cin >> a.content >> m;
    //   for (int j = 1; j <= m; j++) {
    //     node* cur; string s;
    //     cin >> s >> cur.content;
    //     if (chk(s) != -1) {
    //       cur.type = chk(s);
    //       cur.l = nxt(1 << (cur.type - 1));
    //       maxlen = max(maxlen, 1 << (cur.type - 1));
    //       cur.r = cur.l + (1 << (cur.type - 1)) - 1; r = cur.r;
    //       a.adj.push_back(cur);
    //     }
    //   }
    //   a.len = maxlen;
    //   s.push_back(a);
    //   mp[a.content] = s.size();
    // }
    if (op == 2) {
      node cur; string s;
        cin >> s >> cur.content;
        //if (chk(s) != -1) {
          cur.type = chk(s);
          if (r != 0) cur.l = nxt(1 << (cur.type - 1));
          else cur.l = 0;
          maxlen = max(maxlen, 1ll << (cur.type - 1));
          cur.r = cur.l + (1ll << (cur.type - 1)) - 1; r = cur.r;
          v.push_back(cur);
        //}
        mp[cur.content] = cur.l;
        cout << cur.l << "\n";
    }
    if (op == 3) {
      string s;
      cin >> s;
      cout << mp[s] << "\n";
    }
    if (op == 4) {
      int addr; cin >> addr; bool flg = true;
      for (auto cur : v) {
        if (cur.l <= addr && cur.r >= addr) {
          cout << cur.content << "\n";
          flg = false;
          break;
        }
      }
      if (flg) {cout << "ERR\n";}
    }
  }
  return 0;
}