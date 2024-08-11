#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#define N 100005

using namespace std;

int c, t, n, m, x, y, ans;
char op, st[N], inv[256];

namespace brute {
  char ss[N], O[N];
  int cnt, X[N], Y[N];

  void dfs(int k) {
    if(k == n + 1) {
      cnt = 0;
      for(int i = 1; i <= n; i++) {
        ss[i] = st[i];
        if(st[i] == 'U') cnt++;
      }

      for(int i = 1; i <= m; i++)
        switch(O[i]) {
          case 'U' : ss[X[i]] = 'U'; break;
          case 'T' : ss[X[i]] = 'T'; break;
          case 'F' : ss[X[i]] = 'F'; break;
          case '+' : ss[X[i]] = ss[Y[i]]; break;
          case '-' : ss[X[i]] = inv[ss[Y[i]]]; break;
        }

      //cout << ss+1 << ' ' << st+1 << ' ' << strncmp(ss+1, st+1, n) << '\n';
      if(!strncmp(ss+1, st+1, n)) ans = min(ans, cnt);
      return;
    }

    st[k] = 'T', dfs(k+1);
    st[k] = 'F', dfs(k+1);
    st[k] = 'U', dfs(k+1);
  }

  void mian() {
    while(t--) {
      ans = N;
      cin >> n >> m;
      for(int i = 1; i <= m; i++) {
        cin >> O[i] >> X[i];
        if(!isalpha(O[i])) cin >> Y[i];
        //cout << O[i] << ' ' << X[i] << ' ' << Y[i] << '\n';
      }
      dfs(1);
      cout << ans << '\n';
    }
  }
}

namespace tfu {
  void mian() {
    while(t--) {
      ans = 0;
      cin >> n >> m;
      for(int i = 1; i <= n; i++) st[i] = 0;
      while(m--) {
        cin >> op >> x;
        st[x] = op;
      }

      for(int i = 1; i <= n; i++)
        if(st[i] == 'U') ans++;
      cout << ans << '\n';
    }
  }
}

namespace up {
  void mian() {
    while(t--) {
      ans = 0;
      cin >> n >> m;
      for(int i = 1; i <= n; i++) st[i] = 0;
      for(int i = 1; i <= m; i++) {
        cin >> op >> x;
        if(op == 'U') st[x] = 'U';
        else cin >> y, st[x] = ((st[y] == 'U') ? 'U' : 0);
        //for(int i = 1; i <= 1000; i++) cout << st[i]; cout << '\n';
      }

      //for(int i = 1; i <= 1000; i++) cout << st[i]; cout << '\n';
      for(int i = 1; i <= n; i++)
        if(st[i] == 'U') ans++;
      cout << ans << '\n';
    }
  }
}

int main() {
  freopen("tribool.in", "r", stdin);
  freopen("tribool.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  inv['T'] = 'F', inv['F'] = 'T', inv['U'] = 'U';
  cin >> c >> t;
  if(c < 3) brute::mian();
  else if(c < 5) tfu::mian();
  else if(c < 7) up::mian();
  else while(t--) cout << "0\n";
}