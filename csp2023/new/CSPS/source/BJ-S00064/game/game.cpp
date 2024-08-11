#include<bits/stdc++.h>
using namespace std;
bool dp[1005][1005];
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n > 1000)
    {
		cout << 0;
		return 0;
	}
    s = " " + s;
	int ans = 0;
	for(int i = 1; i < n; i ++)
	{
		if(s[i] == s[i + 1])
		{
			dp[i][i + 1] = 1;
		}
	}
	for(int len = 3; len <= n; len ++)
	{
		for(int i = 1, j = i + len; j <= n; i ++, j ++)
		{
			if(s[i] == s[j])
			{
				dp[i][j] |= dp[i + 1][j - 1];
			}
			for(int k = i + 1; k < j; k ++)
			{
				if(dp[i][k] && dp[k + 1][j])
				{
					dp[i][j] = 1;
				}
			}
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			if(dp[i][j])
			{
				ans ++;
			}
		}
	}
	cout << ans;
    return 0;
}
