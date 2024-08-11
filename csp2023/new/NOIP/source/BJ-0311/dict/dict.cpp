#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, m, cnt[30], fid, sid;
string s[N], t[N], fi, se;
int main() {
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (auto ch : s[i]) cnt[ch - 'a']++;
    for (int j = 25; j >= 0; j--) {
      for (int k = 1; k <= cnt[j]; k++)
        t[i] += (char)(j + 'a');
      cnt[j] = 0;
    }
    s[i] = t[i];
    reverse(s[i].begin(), s[i].end());
    if (!fid || fi > t[i]) fid = i, fi = t[i];
    else if (!sid || se > t[i]) sid = i, se = t[i];
  }
  for (int i = 1; i <= n; i++) {
    if (fid == i) cout << (s[i] < se ? 1 : 0);
    else cout << (s[i] < fi ? 1 : 0);
  }
  cout << '\n';
  return 0;
}