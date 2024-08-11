#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n, cnt, cur, a[8005];
bool f[8005][8005];
string s;
char ch[8005];
int max(int x, int y) {return x > y ? x : y;}
bool chk(string chks) {
    int maxs = 8005;
    while (chks.size() > 0 && maxs > 1) {
        int m = chks.size(); maxs = 0;
        chks = " " + chks; cur = 1;
        a[1] = 1; ch[1] = chks[1];
        for (int i = 2; i <= m; ++i)
            if (chks[i] == chks[i - 1]) ++a[cur];
            else maxs = max(maxs, a[cur]), a[++cur] = 1, ch[cur] = chks[i];
        string ss = "";
        for (int i = 1; i <= cur; ++i)
            if (a[i] & 1) ss += ch[i];
        chks = ss;
    } return chks.size() == 0;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s; s = " " + s;
    for (int l = 1; l < n; ++l) {
        string nows;
        for (int r = l + 1; r <= n; r += 2) {
            nows += s[r - 1]; nows += s[r];
            if (r != l + 1 && f[l][r - 2]) {
                f[l][r] = (s[r] == s[r - 1]);
                if (f[l][r]) ++cnt, nows = "";
                continue;
            } f[l][r] = chk(nows);
            if (f[l][r]) ++cnt, nows = "";
        }
    } cout << cnt << endl;
    return 0;
}