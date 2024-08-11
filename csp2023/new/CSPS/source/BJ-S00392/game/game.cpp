#include <bits/stdc++.h>
using namespace std;
bool check(string x) {
    for (int i = 0;i < x.size() / 2;i++) {
        if (x[i] != x[x.size() - 1 - i]) return false;
    }
    return true;
}
int main() {
    freopen("game.in","r",stdin);
    freopen("game.out", "w", stdout);
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0;i < s.size();i++) {
        for (int j = 2;j <= s.size() - i;j++) {
            string tmp = s.substr(i, j);
            //cout << tmp << " ";
            if (check(tmp)) cnt++;
            //cout << cnt << endl;
        }
    }
    cout << cnt + 1;
    return 0;
}