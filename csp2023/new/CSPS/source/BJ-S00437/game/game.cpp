

#include <iostream>
#include <stack>

#define int long long
#define endl '\n'

using namespace std;

const int MAXI = 8009;
int n, ans = 0;
string s;
bool dp[MAXI][MAXI];

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n >> s, s = ' ' + s;

    for (int len = 2; len <= n; len += 2) {
        for (int i = 1, j = len; j <= n; i++, j++) {
            if (len == 2) {
                if (s[i] == s[j]) dp[i][j] = 1, ans++;
                continue;
            }
            if (s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = 1;
            for (int k = i; k < j; k++) dp[i][j] |= dp[i][k] & dp[k + 1][j];
            ans += dp[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}
