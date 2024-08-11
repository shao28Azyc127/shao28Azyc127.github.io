#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 3005;
string s0[N];
string s1[N];
int n, m;

string getlst(string t) {
  int pos = 0;
  for(int i = 1; i < t.length(); i++)
    if(t[pos] > t[i]) pos = i;
  for(int i = 0; i < pos; i++)
    if(t[i] != t[pos]) {
      swap(t[i], t[pos]);
      break;
    }
  return t;
}

string getlrg(string t) {
  int pos = 0;
  for(int i = 1; i < t.length(); i++)
    if(t[pos] < t[i]) pos = i;
  for(int i = 0; i < pos; i++)
    if(t[i] != t[pos]) {
      swap(t[i], t[pos]);
      break;
    }
  return t;
}

bool grt(string a, string b) {
  for(int i = 0; i < a.length(); i++) {
    if(a[i] < b[i]) return false;
    if(a[i] == b[i]) continue;
    if(a[i] > b[i]) return true;
  }
  return false;
}

int main() {
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  string minl;
  for(int i = 1; i <= n; i++) {
    string t; cin >> t;
    s0[i] = getlst(t);
    s1[i] = getlrg(t);
    if(i == 1) minl = s1[i];
    else {
      if(grt(minl, s1[i]))
	minl = s1[i];
    }
  }
  
  for(int i = 1; i <= n; i++) {
    if(m == 1) {
      if(minl == s0[i]) cout << '1';
      else cout << '0';
    }
    else {
      if(grt(minl, s0[i])) cout << '1';
      else cout << '0';
    }
  }
  cout << '\n';
  
  return 0;
}
