#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;
int n, ans;
string s;
bool f[8005][8005];
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i < n; i++) f[i][i + 1] = (s[i] == s[i + 1]);
    while (1) {
        bool newadd = false;
        for (int i = 4; i <= n; i += 2) {
            for (int l = 1; l + i - 1 <= n; l++) {
                int r = l + i - 1;
                if (!f[l][r] && s[l] == s[r] && f[l + 1][r - 1]) {
                    newadd = true;
                    f[l][r] = f[l + 1][r - 1];
                }
            }
        }
        for (int l = 1; l <= n; l++) {
            int now = l;
            for (int r = l; r <= n; r++) {
                if (!f[l][r] && f[now][r]) {
                    newadd = true;
                    f[l][r] = true, now = r + 1;
                } else if (f[now][r]) {
                    now = r + 1;
                }
            }
        }
        if (!newadd) break;
    }
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            ans += f[l][r];
        }
    }
    cout << ans << '\n';
	return 0;
}

