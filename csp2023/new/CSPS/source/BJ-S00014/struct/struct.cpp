#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <deque>
#include <map>
using namespace std;

int n;

long long int aline_to(long long int pre, long long int len) {
  return pre + (len - (pre % len)) % len;
}

struct Struct {
  string name;
  long long int siz, fmt; int ch_cnt;
  vector<int> ch;
  vector<long long int> addto;
  map<string, int> chname;
  vector<string> rechname;
} typs[1 + 10000];
int typ_cnt;

map<string, int> mp;
map<string, int> ee;

struct Variable {
  string name; int typ; long long int pos, siz;
} vars[1 + 10000];
int var_cnt;

void build_struct() {
  // create new type
  int u = ++typ_cnt;
  Struct &cur = typs[u];
  //
  cin >> cur.name >> cur.ch_cnt;
  mp[cur.name] = u;
  cur.ch.assign(1 + cur.ch_cnt, 0);
  cur.addto.assign(1 + cur.ch_cnt, 0);
  cur.rechname.assign(1 + cur.ch_cnt, "");
  // get ch & fmt
  for(int i = 1; i <= cur.ch_cnt; i += 1) {
    string subtype, subname; cin >> subtype >> subname;
    int subid = mp[subtype];
    cur.ch[i] = subid;
    cur.chname[subname] = i;
    cur.rechname[i] = subname;
    // update fmt
    cur.fmt = max(typs[u].fmt, typs[cur.ch[i]].fmt);
  }
  // set delta
  for(int i = 2; i <= cur.ch_cnt; i += 1) {
    cur.addto[i] = cur.addto[i - 1] + typs[cur.ch[i - 1]].siz;
    cur.addto[i] = aline_to(cur.addto[i], typs[cur.ch[i]].fmt);
  }
  cur.siz = cur.addto.back() + typs[cur.ch.back()].siz;
  cur.siz = aline_to(cur.siz, cur.fmt);
  cout << cur.siz << " " << cur.fmt << "\n";
}

void build_variable() {
  int u = ++var_cnt;
  Variable &cur = vars[u];
  string typname;
  cin >> typname >> cur.name;
  cur.typ = mp[typname];
  // allocate pos
  ee[cur.name] = u;
  cur.pos = vars[u - 1].pos + vars[u - 1].siz;
  cur.pos = aline_to(cur.pos, typs[cur.typ].fmt);
  cur.siz = typs[cur.typ].siz;
  cout << cur.pos << "\n";
}

void get_addr(deque<string> &to) {
  to.clear();
  string line; cin >> line; line += ".";
  string cur = "";
  for(char one : line) {
    if(one == '.') to.push_back(cur), cur = "";
    else cur += one;
  }
}

void put_addr(deque<string> &to) {
  for(int i = 0; i < (int)to.size(); i += 1) {
    if(i != 0) cout << ".";
    cout << to[i];
  }
}

void visit_variable() {
  deque<string> addr; get_addr(addr);
  int cur = ee[addr.front()];
  long long int res = vars[cur].pos; addr.pop_front();
  cur = vars[cur].typ;
  // it
  while(addr.size()) {
    string v = addr.front(); addr.pop_front();
    int i = typs[cur].chname[v];
    res += typs[cur].addto[i];
    cur = typs[cur].ch[i];
  }
  cout << res << "\n";
}

void visit_location() {
  long long int pos; cin >> pos;
  deque<string> res;
  for(int i = 1; i <= var_cnt; i += 1) {
    if(vars[i].pos <= pos && vars[i].pos + vars[i].siz > pos) {
      res.push_back(vars[i].name);
      break;
    }
  }
  if(res.empty()) { cout << "ERR\n"; return; }
  // set base
  int cur = ee[res.front()];
  pos -= vars[cur].pos;
  cur = vars[cur].typ;
  // it
  while(cur > 4) {
    int j = 0;
    for(int i = 1; i <= typs[cur].ch_cnt; i += 1) {
      if(typs[cur].addto[i] <= pos && typs[cur].addto[i] + typs[typs[cur].ch[i]].siz > pos) {
        j = i;
        break;
      }
    }
    if(j == 0) { cout << "ERR\n"; return; }
    pos -= typs[cur].addto[j];
    res.push_back(typs[cur].rechname[j]);
    cur = typs[cur].ch[j];
  }
  //
  put_addr(res); cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("struct.in", "r", stdin);
  freopen("struct.out", "w", stdout);
  
  typ_cnt = 4;
  mp["byte"] = 1;
  mp["short"] = 2;
  mp["int"] = 3;
  mp["long"] = 4;
  typs[1] = {"byte", 1, 1, 0, {0}, {0}, {}};
  typs[2] = {"short", 2, 2, 0, {0}, {0}, {}};
  typs[3] = {"int", 4, 4, 0, {0}, {0}, {}};
  typs[4] = {"long", 8, 8, 0, {0}, {0}, {}};
  
  cin >> n;
  for(int t = 1; t <= n; t += 1) {
    int op; cin >> op;
    if(op == 1) build_struct();
    if(op == 2) build_variable();
    if(op == 3) visit_variable();
    if(op == 4) visit_location();
  }
  
  return 0;
}
