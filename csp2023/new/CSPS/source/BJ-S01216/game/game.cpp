#include <bits/stdc++.h>
#define ll long long
using namespace std;
int f[2000010], dp[2000010][30];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    ll ans = 0;
    dp[1][s[1] - 'a'] = 1;
    for (int i = 2; i <= n; i++)
    {
        int x = dp[i - 1][s[i] - 'a'];
        if (x >= 1)
        {
            f[i] = f[x - 1] + 1;
            for (int j = 0; j < 26; j++) dp[i][j] = dp[x - 1][j];
        }
        dp[i][s[i] - 'a'] = i;
        ans += f[i];
    }
    cout << ans << endl;
    return 0;
}