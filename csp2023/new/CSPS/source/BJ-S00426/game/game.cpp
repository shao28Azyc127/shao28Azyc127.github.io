#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 9;
int n;
string s;
void planC() {
    int ans = 0;
    for (int d = 1; d <= n; d += 2) {
        for (int i = 1; i <= n - d; ++i) {
            bool flag = true;
            for (int j = i; j <= i + d / 2; ++j) {
                if (a[j] != a[i + d - j + 1]) {
                    flag = false;
                }
            }
            if (flag) ans++;
        }
    }
    cout << ans;
}
ll planB(int l, int r, ll &g, ll &h) { // [ g][h ]
    if (l == r - 1) {
        if (s[l] == s[r]) {
            g = 1, h = 1;
            return 1;
        } else {
            return 0;
        }
    }
    int mid = (l + r) / 2;
    ll ans = 0;
    ll gg, hh, _;
    ans += planB(l, mid, gg, _);
    ans += planB(mid + 1, r, _, hh);
}
void planA() {  // dp
//    for (int i = 1; i <= n; ++i) {
//        int tmpc = 0;
//        while (s[i - tmpc] == s[i + 1 + tmpc]) f[i - tmpc][i + 1 + tmpc] = f[i - tmpc + 1][i + tmpc] + 1, tmpc++;
//        if (s[i] == s[i + 1]) f[i][i + 1] = 1;
//        for (int j = i + 3; j <= n; j += 2) {
//            for (int k = i; k < j; ++k) {
//                f[i][j] += f[i][k] + f[k+1][j];
//            }
//        }
//    }
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            cout << f[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << f[1][n] << endl;
//    for (int d = 1; d <= n; d += 2) {
//        for (int i = 1; i <= n - d; ++i) {
//            if (s[i] == s[i + d]) {
//                a[i][i + d] = true;
//                f[i][i + d] = f[i + 1][i + d - 1] + 1;
//            }
//        }
//    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    s = '*' + s;
    ll _, __;
//    if (n <= 8000) {
        cout << planC();
//    }
    return 0;
}
/*
qqrqerrwwrwqeq
*/
