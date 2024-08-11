#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

using ll = long long;

class Type {
public:
  string name;
  vector<Type> members;
  vector<string> membername;
  int align_;
  ll memsize_;

  Type() : align_(-1), memsize_(-1) { }
  Type(const string &, const vector<pair<string, string>> &);

  int align();
  ll memsize();
  bool ispri();
};

class Instance {
public:
  Type type;
  string name;
  vector<Instance> members;
  map<string, size_t> mp;
  vector<ll> startpos;
  ll memstart = -1;

  Instance() : memstart(-1) { }
  Instance(const string &, const Type &);

  ll lookup(const vector<string> &);
  string lookup(ll);
};

ll memptr = 0;
vector<ll> startpos;
map<string, Type> types;
map<string, Instance> instances;
map<size_t, string> mp;

Type::Type(const string &name_, const vector<pair<string, string>> &members_) : align_(-1), memsize_(-1) {
  name = name_;
  for (auto x : members_) {
    members.emplace_back(types[x.first]);
    membername.emplace_back(x.second);
  }
}

inline int Type::align() {
  if (align_ != -1) return align_;
  if (name == "byte") align_ = 1;
  else if (name == "short") align_ = 2;
  else if (name == "int") align_ = 4;
  else if (name == "long") align_ = 8;
  else {
    align_ = 0;
    for (auto x : members)
      align_ = max(align_, x.align());
  }
  return align_;
}

inline ll Type::memsize() {
  if (memsize_ != -1) return memsize_;
  if (name == "byte") memsize_ = 1;
  else if (name == "short") memsize_ = 2;
  else if (name == "int") memsize_ = 4;
  else if (name == "long") memsize_ = 8;
  else {
    memsize_ = 0;
    for (auto x : members) {
      while (memsize_ % x.align()) memsize_++;
      memsize_ += x.memsize();
    }
  }
  while (memsize_ % align()) memsize_++;
  return memsize_;
}

inline bool Type::ispri() {
  return name == "byte" || name == "short" || name == "int" || name == "long";
}

Instance::Instance(const string &name_, const Type &type_) : memstart(-1) {
  name = name_, type = type_;
  while (memptr % type.align()) memptr++;
  memstart = memptr;
  if (type.ispri()) {
    startpos.emplace_back(memptr);
    if (type.name == "byte") memptr += 1;
    else if (type.name == "short") memptr += 2;
    else if (type.name == "int") memptr += 4;
    else if (type.name == "long") memptr += 8;
    while (memptr % type.align()) memptr++;
    return;
  }
  for (size_t i = 0; i < type.members.size(); i++) {
    const string &n = type.membername[i];
    Type &t = type.members[i];
    mp[n] = i;
    while (memptr % t.align()) memptr++;
    startpos.emplace_back(memptr);
    Instance member(n, t);
    members.emplace_back(member);
  }
  while (memptr % type.align()) memptr++;
}

ll Instance::lookup(const vector<string> &names) {
  if (names.size() == 0) return memstart;
  string n = names[0];
  vector<string> passdown;
  for (size_t i = 1; i < names.size(); i++)
    passdown.emplace_back(names[i]);
  return members[mp[n]].lookup(passdown);
}

string Instance::lookup(ll addr) {
  if (type.ispri()) {
    if (type.name == "byte") return addr - memstart <= 0 ? "" : "ERR";
    else if (type.name == "short") return addr - memstart <= 1 ? "" : "ERR";
    else if (type.name == "int") return addr - memstart <= 3 ? "" : "ERR";
    else if (type.name == "long") return addr - memstart <= 7 ? "" : "ERR";
  }
  size_t p = upper_bound(startpos.begin(), startpos.end(), addr) - startpos.begin() - 1;
  string res = members[p].lookup(addr);
  if (res == "ERR") return "ERR";
  else return type.membername[p] + (res == "" ? "" : "." + res);
}

pair<int, ll> opt1(const string &name, const vector<pair<string, string>> members) {
  types[name] = Type(name, members);
  return make_pair(types[name].align(), types[name].memsize());
}

ll opt2(const string &name, const string &tpname) {
  ll res = memptr;
  mp[startpos.size()] = name;
  startpos.emplace_back(memptr);
  instances[name] = Instance(name, types[tpname]);
  return res;
}

ll opt3(const string &name) {
  vector<string> split;
  string now, first;
  bool flg = 0;
  for (size_t i = 0; i < name.size(); i++) {
    if (name[i] == '.') {
      if (first.size() == 0) first = now;
      else split.emplace_back(now);
      now = "";
      flg = 1;
    } else now += name[i];
  }
  if (flg == 0) return instances[now].memstart;
  split.emplace_back(now);
  return instances[first].lookup(split);
}

string opt4(ll addr) {
  if (addr >= memptr) return "ERR";
  size_t p = upper_bound(startpos.begin(), startpos.end(), addr) - startpos.begin() - 1;
  string res = instances[mp[p]].lookup(addr);
  if (res == "ERR") return "ERR";
  else return instances[mp[p]].name + (res == "" ? "" : "." + res);
}

int main() {
  freopen("struct.in", "r", stdin);
  freopen("struct.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  vector<pair<string, string>> empty;
  types["byte"] = Type("byte", empty);
  types["short"] = Type("short", empty);
  types["int"] = Type("int", empty);
  types["long"] = Type("long", empty);
  int q; cin >> q;
  for (int i = 1; i <= q; i++) {
    int opt; cin >> opt;
    if (opt == 1) {
      string s; int k; vector<pair<string, string>> x;
      cin >> s >> k;
      while (k--) {
        string t, n; cin >> t >> n;
        x.emplace_back(t, n);
      }
      auto res = opt1(s, x);
      cout << res.second << ' ' << res.first << endl;
    } else if (opt == 2) {
      string t, n; cin >> t >> n;
      cout << opt2(n, t) << endl;
    } else if (opt == 3) {
      string s; cin >> s;
      cout << opt3(s) << endl;
    } else {
      ll addr; cin >> addr;
      cout << opt4(addr) << endl;
    }
  }
  return 0;
}