#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, c[40];
string s;
stack< char > st;
bool fun(string str) {
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (c[str[i]-'a'] % 2 == 0 || st.empty() || st.top() != str[i]) {
            st.push(str[i]);
            c[str[i]-'a']++;
        } else {
            c[str[i]-'a']++;
            st.pop();
        }
    }
    if (st.empty()) return true;
    while (!st.empty()) st.pop();
    return false;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    for (int i = 2; i <= n; i += 2) {
        for (int j = 0; j <= n - i; j++) {
            memset(c, 0, sizeof(c));
            if (fun(s.substr(j, i))) cnt++;
        }
    }

    cout << cnt;
    return 0;
}
