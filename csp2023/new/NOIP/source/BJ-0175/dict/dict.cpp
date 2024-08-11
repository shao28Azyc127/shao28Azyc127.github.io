#include <bits/stdc++.h>
using namespace std;
const int N = 10009;
string arr[N];
struct node {
  int id; string str;
}pre[N];
int n, m, ans[N], cc[N], buc[29];
bool cmp(node one, node two) {
  if (one.str == two.str) return one.id < two.id;
  return one.str < two.str;
}

string b(string solo) {
  memset(buc, 0, sizeof(buc));
  for (char c : solo) buc[c - 'a' + 1]++;
  string res = "";
  for (int i = 1; i <= 26; i++) {
    for (int j = 1; j <= buc[i]; j++) {
      res += (char) (i + 'a' - 1);
    }
  }
  return res;
}

int main() {
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);
  double bg = clock();
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i]; pre[i + n].id = i + n; 
    string s = arr[i]; s = b(s); pre[i].str = s;
    string cur = s; reverse(cur.begin(), cur.end()); pre[i + n].str = cur;
    pre[i].id = i;
  }
  
  sort(pre + 1, pre + n + n + 1, cmp);
  int cnt = 0;
  for (int i = n + n; i >= 1; i--) {
    //cout << pre[i].id << " " << pre[i].str << endl;
    if (pre[i].id > n) {
      //for (int j = 1; j <= n; j++) cc[j]++;
      //cc[pre[i].id - n]--;
      cnt++;
    } else {
      ans[pre[i].id] = (cnt == n);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << endl;
  return 0;
}