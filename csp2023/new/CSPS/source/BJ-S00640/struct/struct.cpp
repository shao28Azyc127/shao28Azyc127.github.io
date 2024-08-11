#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

struct typ {
  string t;
  int s;
};

struct elet {
  string t, n;
  int s, p;
};

struct eles {
  string t, n;
  int s, p;
  vector<elet> v;
};

struct stt {
  string t;
  vector<elet> v;
  int s, a;
};

vector<stt> S;
vector<elet> ET;
vector<eles> ES;
vector<typ> T;
int P;

void query(string str) {
  string cur1, cur2;
  bool f = false;
  for(int i = 0; i < str.length(); i++) {
    if(str[i] == '.') {
      f = true;
      continue;
    }
    if(f) cur2 += str[i];
    else cur1 += str[i];
  }

  if(f) {
    for(auto es : ES) {
      if(es.n != cur1) continue;
      for(auto et : es.v) {
	if(et.n != cur2) continue;
	cout << et.p << endl;
	break;
      }
      break;
    }
  }
  else {
    for(auto et : ET) {
      if(et.n != cur1) continue;
      cout << et.p << endl;
      break;
    }
  }
}

int main() {
  freopen("struct.in", "r", stdin);
  freopen("struct.out", "w", stdout);
  
  T.push_back({"byte", 1});
  T.push_back({"short", 2});
  T.push_back({"int", 4});
  T.push_back({"long", 8});
  
  int N; cin >> N;
  while(N--) {
    int op; cin >> op;
    if(op == 1) {
      stt s; cin >> s.t;
      int k; cin >> k;
      int p = 0;
      s.a = 0;
      for(int i = 1; i <= k; i++) {
	elet ct; cin >> ct.t >> ct.n;
	for(auto t : T) {
	  if(t.t == ct.t) {
	    ct.s = t.s;
	  }
	}
	if(p % ct.s) ct.p = (p / ct.s + 1) * ct.s;
	else ct.p = p;
	p = ct.p + ct.s - 1;
	s.v.push_back(ct);
	s.a = max(s.a, ct.s);
      }
      //cout << p + 1 << ' ' << s.a << endl;
      if((p + 1) % s.a) s.s = ((p + 1) / s.a + 1) * s.a - 1;
      else s.s = p + 1;
      S.push_back(s);
      cout << s.s << ' ' << s.a << endl;
    }
    if(op == 2) {
      string str, n; cin >> str >> n;
      bool f = false;
      for(auto t : T) {
	if(t.t == str) {
	  elet ct;
	  ct.t = t.t; ct.n = n; ct.s = t.s;
	  if(P % ct.s) ct.p = (P / ct.s + 1) * ct.s;
	  else ct.p = P;
	  P = ct.p + ct.s - 1;
	  ET.push_back(ct);
	  cout << ct.p << endl;
	  f = true; break;
	}
      }
      if(f) continue;
      for(auto s : S) {
	if(s.t == str) {
	  eles cs;
	  cs.t = s.t; cs.n = n; cs.s = s.s;
	  if(P % s.a) cs.p = (P / s.a + 1) * s.a;
	  else cs.p = P;
	  P = cs.p + cs.s - 1;
	  for(auto t : s.v) {
	    auto t1 = t;
	    t1.p += cs.p;
	    cs.v.push_back(t1);
	  }
	  ES.push_back(cs);
	  cout << cs.p << endl;
	  break;
	}
      }
    }
    if(op == 3) {
      string str; cin >> str;
      query(str);
    }
    if(op == 4) {
      int addr; cin >> addr;
      bool f = false;
      for(auto es : ES) {
	if(es.p > addr || addr >= es.p + es.s)
	  continue;
	for(auto et : es.v) {
	  if(et.p > addr || addr >= et.p + et.s)
	    continue;
	  cout << es.n << '.' << et.n << endl;
	  f = true;
	}
      }
      for(auto et : ET) {
	if(et.p > addr || addr >= et.p + et.s)
	  continue;
	cout << et.n << endl;
	f = true;
      }
      if(!f) cout << "ERR" << endl;
    }
  }
  return 0;
}
