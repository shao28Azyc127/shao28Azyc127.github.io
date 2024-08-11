#include <iostream>

using namespace std;

const int maxn = 2000005;

bool candistroy(string s) {
    if (s.length() & 1) return false;
    while (s.length() > 2) {
        bool flag = false;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                s = s.substr(0, i - 1) + s.substr(i + 1, s.length() - i - 1);
                flag = true;
                break;
            }
        }
        if (!flag) return false;
    }
    return s[0] == s[1];
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j += 2) {
            if (candistroy(s.substr(i, j - i + 1))) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}