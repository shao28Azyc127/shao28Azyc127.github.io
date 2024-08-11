#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s, a;
bool check (int l, int r) {
    int cnt = r - l + 1;
    while (cnt > 0) {
        int size1 = cnt;
        for (int i = l; i <= r; i++) {
            int j = i + 1;
            while (j <= r && a[j] == '*') j++;
            if (j <= r && a[i] == a[j] && a[i] != '*') {
                cnt -= 2;
                a[i] = a[j] = '*';
            }
        }
        if (size1 == cnt) {
                //cout << "???\n";
                return 0;
        }
    }
    return 1;
}
int main () {
    freopen ("game.in", "r", stdin);
    freopen ("game.out", "w", stdout);
    cin >> n >> s;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            a = s;
            if (check (l, r)) ans++;
            //cout << a << endl;
        }
    }
    cout << ans << endl;
    return 0;
}/*
    *
   * *
  *   *
  *???*
  *   *
  *   *
*/
