#include <iostream>
using namespace std;
const int maxn = 2000 + 10;
const int maxm = 2e5 + 10;
int n, ans;
bool f[maxn][maxn], g[maxm][40];
char s[maxm];
int main() {
    ios::sync_with_stdio(false);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s + 1;
    if (n <= 2000) {
        for (int i = 2; i <= n; i++) if (s[i] == s[i - 1]) f[i - 1][i] = true;
        for (int len = 4; len <= n; len += 2)
            for (int l = 1; l <= n - len + 1; l++) {
                int r = l + len - 1;
                if (s[l] == s[r]) f[l][r] = f[l + 1][r - 1];
                for (int k = l + 1; k < r; k += 2)
                    if (f[l][r]) break;
                    else if (f[l][k] && f[k + 1][r]) f[l][r] = true;
            }
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (f[i][j]) ++ans;
    } else {
        for (int i = 2; i <= n; i++) if (s[i] == s[i - 1]) g[i - 1][2] = true;
        for (int len = 4; len <= 30; len += 2)
            for (int l = 1; l <= n - len + 1; l++)
                for (int j = 2; j < len; j += 2) g[l][len] |= g[l][j] & g[l + j][len - j];
        for (int len = 2; len <= 30; len += 2)
            for (int i = 1; i <= n - len + 1; i++)
                if (g[i][len]) ++ans;
    }
    cout << ans << '\n';
    return 0;
}