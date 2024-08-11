#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define int long long

int ans = 0;

string mysub(int l, int r, string s) {
    string ret = "";
    for (int i = l;i <= r;i++) {
        ret += s[i];
    }
    return ret;
}
bool check(string s) {
    while (!s.empty()) {
        bool flag = 0;
        for (int i = 0;i < s.size() - 1;i++) {
            if (s[i] == s[i + 1]) {
                s.erase(i, 2);
                flag = 1;
                break;
            }
        }
        if (!flag) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
if (n == 1) { cout << 0 << endl; return 0; }
    string s;
    cin >> s;
    int cnt = 0;
    for (int l = 0;l <= s.size() - 2;l++) {
        for (int r = l + 1;r < s.size();r += 2) {
            if (check(mysub(l, r, s))) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
