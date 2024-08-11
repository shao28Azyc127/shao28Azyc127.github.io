#include<bits/stdc++.h>
using namespace std;
char s[2000010];
bool dp[810][810];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    scanf("%d%s", &n, s + 1);
    for(int len = 2; len <= n; len++)
    {
        for(int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            if(len > 2) dp[l][r] = dp[l + 1][r - 1] && (s[l] == s[r]);
            else dp[l][r] = (s[l] == s[r]);
            for(int k = l; k < r; k++)
            {
                dp[l][r] |= (dp[l][k] && dp[k + 1][r]);
            }
            //printf("%d %d %d\n", l, r, dp[l][r]);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++) res += (int)(dp[i][j]);
    }
    printf("%d", res);
    return 0;
}
