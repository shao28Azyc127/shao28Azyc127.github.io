#include<bits/stdc++.h>
using namespace std;
const int MX = 8005;
typedef long long LL;
int n;
string s;
LL ans, dp[MX];
bool flag[MX][MX];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == s[i + 1]) flag[i][i + 1] = 1;
    for (int l = 3; l <= n; l++)
        for (int i = 0; i + l - 1 < n; i++)
        {
            int j = i + l - 1;
            if (s[i] == s[j]) flag[i][j] |= flag[i + 1][j - 1];
            for (int k = i + 1; k < j - 1; k++) flag[i][j] |= (flag[i][k] & flag[k + 1][j]);
        }
 //   for (int i = 1; i <= n; i++)
 //       for (int j = i - 1; j >= 0; j--)
 //           if (flag[j][i - 1])
 //           {
 //               dp[i] = dp[j] + 1;
 //               break;
 //           }
 //   for (int i = 1; i <= n; i++) ans += dp[i];
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) if (flag[i][j]) ans++;
    cout << ans << endl;
    return 0;
}