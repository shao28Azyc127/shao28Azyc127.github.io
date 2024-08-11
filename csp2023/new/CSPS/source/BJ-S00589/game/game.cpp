#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
    int len = (int)s.size();
    if (len & 1)
        return false;
    if (len == 2) 
        return s[0] == s[1];
    for (int i = 0; i < len - 1; ++i)
        if (s[i] == s[i + 1]) {
            s.erase(i, 2);
            return check(s);
        }
    return false;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    string s;
    scanf("%d", &n);
    cin >> s;
    int ans = 0;
    for (int len = 2; len <= n; len += 2) 
        for (int i = 0; i + len - 1 < n; ++i) 
            if (check(s.substr(i, len))) 
                ++ans;
    printf("%d\n", ans);
    return 0;
}