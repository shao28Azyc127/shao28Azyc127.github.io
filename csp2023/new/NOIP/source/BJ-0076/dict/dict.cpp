#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 3000 + 5;

int n, m;
string s[NR], t[NR];

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i], t[i] = s[i];
        sort(t[i].begin(), t[i].end()), reverse(t[i].begin(), t[i].end());
    }
    sort(t + 1, t + n + 1);
    for (int i = 1; i <= n; ++i) {
        string tmp = s[i];
        sort(tmp.begin(), tmp.end());
        string tmpp = tmp, mi;
        reverse(tmpp.begin(), tmpp.end());
        if (tmpp == t[1]) mi = t[2];
        else mi = t[1];
        cout << (tmp < mi ? 1 : 0);
    }
    return 0;
}