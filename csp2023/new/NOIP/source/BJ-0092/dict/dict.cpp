#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 3000 + 5;

int n, m, cnt[26];
string s, mn[MAXN], mx[MAXN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < m; j++) cnt[s[j] - 'a']++;
        for (char ch = 'a'; ch <= 'z'; ch++)
            for (int j = 1; j <= cnt[ch - 'a']; j++) mn[i] += ch;
        for (char ch = 'z'; ch >= 'a'; ch--)
            for (int j = 1; j <= cnt[ch - 'a']; j++) mx[i] += ch;
    }
    for (int i = 1; i <= n; i++) {
        bool flag = 1;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (mn[i] >= mx[j]) {flag = 0; break;}
        }
        cout << flag;
    }
    cout << '\n';
    return 0;
}