#include <bits/stdc++.h>
using namespace std;

string strs[30] = {"", "aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj", "kk", "ll", "mm", "nn", "oo", "pp", "qq", "rr", "ss", "tt", "uu", "vv", "ww", "xx", "yy", "zz"};
bool has(string s) {
    for (int i = 1; i <= 26; i++) {
        if (s.find(strs[i]) != string :: npos) {
            return 1;
        }
    }
    return 0;
}
bool check(string s) {
    //cout << s << "   after delete: ";
    while (has(s)) {
        //cout << has(s) << ", ";
        for (int i = 1; i <= 26; i++) {
            auto it = s.find(strs[i]);
            if (it != string :: npos) {
                s.erase(it, 2);
            }
        }
    }
    //cout << s << '\n';
    return s == "";
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    int ans = 0;
    for (int len = 2; len <= n; len += 2) {
        for (int i = 1; i <= n - len + 1; i++) {
            string str = s.substr(i, len);
            ans += check(str);
        }
    }
    cout << ans;
    return 0;
}
