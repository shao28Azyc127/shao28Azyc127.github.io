#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s;
char now;
bool f;
bool check(int st, int len) {
    stack<char> sta;
    for (int i = st + len - 1; i >= st; i--) {
        if (sta.empty()) {
            sta.push(s[i]);
            continue;
        }
        if (sta.top() == s[i]) sta.pop();
        else sta.push(s[i]);
    }
    if (sta.empty()) return true;
    return false;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    s = " " + s;
    ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 2; j <= n - i + 1; j += 2) {
            if (check(i, j)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
