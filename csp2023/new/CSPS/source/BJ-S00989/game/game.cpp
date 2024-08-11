#include <bits/stdc++.h>
using namespace std;

bool is (string s)
{
    string tmp;
    int cnt = 1;

    while (cnt != 0 && s.size() > 1) {
        cnt = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] != s[i + 1]) {
                tmp += s[i];
            } else {
                i++;
                cnt++;
            }
        }
        if (s[s.size() - 2] != s[s.size() - 1]) tmp += s[s.size() - 1];
        s = tmp;
        tmp = "";
    }

    return !s.size();
}

int main ()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n, cnt = 0;
    string s, tmp;

    cin >> n;

    cin >> s;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            tmp = s.substr(i, j - i + 1);
            if (is(tmp)) {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}