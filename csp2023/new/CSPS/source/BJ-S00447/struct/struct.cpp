#include <bits/stdc++.h>
using namespace std;
const int N = 110, S = 5e5 + 5;
struct tp {
  int val, sz;
  string name;
  vector<pair<string, string>> v;
} a[N];
pair<string, string> p[N];
int q, tot, totp, me;
string sp[S];
int main() {
  freopen("struct.in", "r", stdin);
  freopen("struct.out", "w", stdout);
  tot++, a[tot].val = a[tot].sz = 1, a[tot].name = "byte";
  tot++, a[tot].val = a[tot].sz = 2, a[tot].name = "short";
  tot++, a[tot].val = a[tot].sz = 4, a[tot].name = "int";
  tot++, a[tot].val = a[tot].sz = 8, a[tot].name = "long";
  cin >> q;
  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      string s; int k; cin >> s >> k;
      tot++;
      a[tot].name = s;
      while (k--) {
        string x, y; cin >> x >> y;
        a[tot].v.push_back({x, y});
        for (int i = 1; i < tot; i++)
          if (a[i].name == x) {
            a[tot].val = max(a[tot].val, a[i].val);
            while (a[tot].sz % a[i].val) a[tot].sz++;
            a[tot].sz += a[i].val;
          }
      }
      while (a[tot].sz % a[tot].val) a[tot].sz++;
      cout << a[tot].sz << ' ' << a[tot].val << '\n';
    }
    if (op == 2) {
      cout << me << '\n';
      totp++;
      cin >> p[totp].first >> p[totp].second;
      for (int i = 1; i <= 4; i++)
        if (a[i].name == p[totp].first)
          for (int j = 0; j < a[i].sz; j++)
            sp[me++] = p[totp].second;
      for (int i = 5; i <= tot; i++)
        if (a[i].name == p[totp].first)
          for (auto ele : a[i].v)
            for (int j = 1; j <= 4; j++)
              if (a[j].name == ele.first) {
                while (me % a[j].val) me++;
                for (int k = 0; k < a[j].sz; k++)
                  sp[me++] = p[totp].second + "." + ele.second;
              }
    }
    if (op == 3) {
      string s; cin >> s;
      for (int i = 0; i < me; i++)
        if (sp[i].find(s) != sp[i].npos) {
          cout << i << '\n';
          break;
        }
    }
    if (op == 4) {
      int x; cin >> x;
      if (sp[x] == "") cout << "ERR" << '\n';
      else cout << sp[x] << '\n';
    }
  }
  return 0;
}

// addr: ll!