#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>'
#include <cstring>
using namespace std;
int n;
bool dp[2005][2005];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w",stdout);
    scanf("%d", &n);
    string s;
    cin >> s;
    s = ' ' + s;
    for(int i = 1;i <= n;i ++) dp[i][i] = 0;
    for(int i = 1;i < n;i ++) dp[i][i + 1] = (s[i] == s[i + 1]);
    for(int len = 3;len <= n;len ++)
    {
        for(int i = 1;i + len - 1 <= n;i ++)
        {
            int j = i + len - 1;
            if(s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = true;
            else
            {
                for(int k = i + 1;k < j - 1;k ++)
                {
                    if(dp[i][k] && dp[k + 1][j])
                    {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
    }
    long long ans = 0;
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            ans += dp[i][j];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
