#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, ans;
string s;
stack < char > t;

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s, s = " " + s;
    for (int i = 1; i <= n; ++i) {
        while (!t.empty()) t.pop();
        for  (int j = i; j <= n; ++j) {
            if (!t.empty() && t.top() == s[j]) t.pop();
            else t.push(s[j]);
            if (t.empty()) ans ++;
        }
    }
    cout << ans << '\n';
    return 0;
}