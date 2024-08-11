#include <bits/stdc++.h>
using namespace std;
int l = 0;
long long cnt = 0;
bool check(string s) {
    for (int i = 0; i < s.size() - 1; ++i)
        if (s[i] == s[i + 1])
            return false;
    return true;
}
bool po(string s) {
    string s1 = s;
    while (!check(s))
        for (int i = 0; i < s.size() - 1; ++i) {
            int tmp = 0;
            bool flag = 0;
            for (int j = i + 1; j < s.size() && s[j] == s[i]; ++j) ++tmp, flag = 1;
            if (i + tmp + 1 == s.size())
                if (!flag) s = s.substr(0, i + 1);
                else s = s.substr(0, i);
            else
                if (!flag) s = s.substr(0, i) + s.substr(i + tmp + 1);
                else s = s.substr(0, i + 1) + s.substr(i + tmp + 1);
            if (!s.size()) {
                return true;
            }
        }
    if (!s.size()) return true;
    return false;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    string s = "";
    cin >> l >> s;
    for (int i = 0; i < l - 1; ++i)
        for (int j = i + 1; j < l; ++j)
            if (po(s.substr(i, j - i + 1)))
                ++cnt;
    cout << cnt << endl;
    return 0;
}
