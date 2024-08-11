#include <bits/stdc++.h>
using namespace std;
const int N = 3006;
int n, m, cnt[N][26], ans;
char sml[N];
string s[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i]; sml[i] = 'z';
        for (int j = 0; j < m; ++j) {
            cnt[i][s[i][j] - 'a']++;
            sml[i] = min(sml[i], s[i][j]);
        }
    }
    if (n == 1) {cout << 1; return 0;}
    for (int i = 1; i <= n; ++i) {  // this = aabbcc
        bool flg = false;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            bool flag = false;
            for (int k = sml[i] - 'a' + 1; k < 26; ++k)
                if (cnt[j][k]) {flag = true; break;}
            if (flag) continue;
            flg = true; cout << 0; break;
        }
        if (!flg) cout << 1;
    }
    return 0;
}
