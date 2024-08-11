#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#define ll long long

using namespace std;

int n, op;
ll addr;
string s, t1, t2; // shared
map<string, ll> sz;

struct tp {
  ll siz, qi;
  vector<string> stp, snm;
  tp() : siz(0), qi(0) {}
};
map<string, tp> typ;

struct obj {
  ll siz, fad;
  string tpe, nme;
};
vector<obj> o;
map<string, obj> ol;

ll getaddr(ll adddr, ll siz) {
  return (adddr % siz) ? ((adddr / siz + 1) * siz) : adddr;
}

int main() {
  freopen("struct.in", "r", stdin);
  freopen("struct.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sz["byte"] = 1, sz["short"] = 2, sz["int"] = 4, sz["long"] = 8;

  for(cin >> n; n; --n) {
    cin >> op;
    if(op == 1) {
      int k; tp T;
      cin >> s >> k;
      for(int i = 0; i < k; i++) {
        cin >> t1 >> t2;
        T.qi = max(T.qi, sz[t1]);
        T.stp.push_back(t1), T.snm.push_back(t2);
      }
      for(int i = 0; i < k; i++) {
        //cerr << sz[T.stp[i]] << '\n';
        T.siz = getaddr(T.siz, sz[T.stp[i]]) + sz[T.stp[i]];
      }
      sz[s] = T.siz;
      typ[s] = T;

      cout << T.siz << ' ' << T.qi << '\n';
      //cerr << "ok 1\n";
    } else if(op == 2) {
      cin >> t1 >> t2;

      obj O;
      O.siz = sz[t1], O.tpe = t1, O.nme = t2;
      //cerr << O.siz;
      O.fad = getaddr(addr, O.siz);
      addr = O.fad + O.siz;
      o.push_back(O);
      ol[t2] = o.back();

      cout << O.fad << '\n';
    } else if(op == 3) {
      cin >> s;
      bool flag = false;
      t1.clear(), t2.clear();
      for(char &ch : s) {
        if(ch == '.') { flag = true; continue; }
        if(flag) t2.push_back(ch);
        else t1.push_back(ch);
      }

      if(t2.empty()) cout << ol[t1].fad << '\n';
      else {
        //cerr << "noe hwew";
        ll ans = ol[t1].fad;
        vector<string> &v = typ[ol[t1].tpe].snm, &w = typ[ol[t1].tpe].stp;
        for(int i = 0; i < v.size(); i++) {
          if(v[i] != t2) ans = getaddr(ans+sz[w[i]], sz[w[i+1]]);
          else break;
          //cerr << v[i] << ' ' << t2 << ' ' << w[i] << ' ' << sz[w[i]] << '\n';
        }

        cout << ans << '\n';
      }
    } else {
      ll pos;
      bool flg = false;
      cin >> pos;
      if(pos >= addr) { cout << "ERR\n"; continue; }

      for(int i = 0, h, t; i < o.size(); i++) {
        h = o[i].fad;
        if(o[i].tpe == "byte" || o[i].tpe == "short" || o[i].tpe == "int" || o[i].tpe == "long") {
          t = h + sz[o[i].tpe];
          if(h <= pos && pos < t) cout << o[i].nme << '\n', flg = true;
        } else {
          vector<string> &v = typ[o[i].tpe].snm, &w = typ[o[i].tpe].stp;
          for(int j = 0; j < v.size(); j++) {
            t = h + sz[w[j]];
            //cerr << h << ' ' << t << '\n';
            if(h <= pos && pos < t) cout << o[i].nme << '.' << v[j] << '\n', flg = true;
            if(j + 1 != v.size()) h = getaddr(t, sz[w[j+1]]);
          }
        }
      }

      if(!flg) cout << "ERR\n";
    }
  }
}