#include <iostream>
#include <string>
using namespace std;
string s;
int n;
bool dp[805][805];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> s;
    s = ' ' + s;
    for (int len = 2;len <= n;len++)
    {
        if (len % 2 != 0) continue;
        for (int i = 1;i <= n - len + 1;i++)
        {
            int j = i + len - 1;
            dp[i][j] = 0;
            if (len == 2 && s[i] == s[j]) dp[i][j] = 1;
            if (len == 2) continue;
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            for (int k = i + 1;k <= j;k++)
            {
                if (dp[i][k - 1] && dp[k][j]) dp[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            if (dp[i][j]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}