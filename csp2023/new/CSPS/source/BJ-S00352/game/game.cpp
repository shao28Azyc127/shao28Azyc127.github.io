#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN = 8005;

int n;
char s[MAXN];
bool dp[MAXN][MAXN];
LL ans;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i+1])
        {
            dp[i][i+1] = true;
        }
    }

    for (int len = 4; len <= n; len += 2)
    {
        for (int l = 1; l+len-1 <= n; l++)
        {
            int r = l + len - 1;

            if (s[l] == s[r])
            {
                dp[l][r] = dp[l+1][r-1];
            }
            
            if (dp[l][r] == false)
            {
                for (int k = l+1; k < r; k++)
                {
                    dp[l][r] |= (dp[l][k] && dp[k+1][r]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (dp[i][j])
            {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}