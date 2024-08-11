#include <bits/stdc++.h>
using namespace std;

bool dp[1001][1001];

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n;
	scanf("%d", &n);
	string str;
	cin >> str;
	str = " " + str;
	int res = 0;
	for(int i = 1;i < n;i++)
    {
        dp[i][i + 1] = (str[i] == str[i + 1]);
        if(dp[i][i + 1])
        {
            res++;
        }
    }
    for(int len = 4;len <= n;len += 2)
    {
        for(int i = 1;i + len - 1 <= n;i++)
        {
            int j = i + len - 1;
            if(str[i] == str[j])
            {
                dp[i][j] |= dp[i + 1][j - 1];
            }
            for(int k = i + 1;k <= j;k += 2)
            {
                if(dp[i][j])
                {
                    break;
                }
                dp[i][j] |= (dp[i][k] & dp[k + 1][j]);
            }
            if(dp[i][j])
            {
                res++;
            }
        }
    }
    printf("%d\n", res);
	return 0;
}
