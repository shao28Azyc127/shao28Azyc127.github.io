#include <bits/stdc++.h>
using namespace std;
string s;
bool d[15], flag;
int n, ans;
void dfs(int l, int r, int len) {
    if (len == 0) {
        flag = true;
        return;
    }
    int lst = -1;
    for (int i = l; i <= r; ++i) {
        if (!d[i]) {
            if (lst == -1) lst = i;
            else if (s[lst] == s[i]) {
                d[lst] = true;
                d[i] = true;
                dfs(l, r, len - 2);
                d[lst] = false;
                d[i] = false;
            }
        } 
    }
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = 0; k < n; ++k) d[k] = false;
            flag = false;
            dfs(i, j, j - i + 1);
            if (flag) ++ans;
        }
    }
    cout << ans;
    return 0;
}