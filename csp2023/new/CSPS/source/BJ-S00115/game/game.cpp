#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int maxn = 8e3 + 5;
int n;
string s;
inline bool check(string str) {
    int len = str.size();
    // if (len) cout << str << '\n';
    // else cout << "EMPTY\n";
    if (!len) return 1;
    string t = "";
    bool flag = 0;
    for (int i = 0; i < len; i++) {
        while (str[i] == str[i+1]) i += 2, flag = 1;
        if (i >= len) break;
        t += str[i];
    }
    return flag ? check(t) : 0;
}
inline int solve1() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string t = "";
            for (int k = i; k <= j; k++) t += s[k];
            if (check(t)) ans++;
        }
    }
    return ans;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    // check("ccbbaadbaaccbd");
    // return 0;
    cin >> n >> s;
    printf("%d\n", solve1());
    return 0;
}
