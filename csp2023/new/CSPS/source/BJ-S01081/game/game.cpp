#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
const int mxn = 8010;
int n, ans;
char c[mxn];
bool dp[mxn][mxn];
int cnt[mxn][30];
int main()
{
	ios::sync_with_stdio(0);
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	F(i, 1, n)
	{
		F(j, 0, 25) cnt[i][j] = cnt[i-1][j];
		cin >> c[i];
		cnt[i][(int)c[i]-'a']++;
	}
	F(i, 1, n-1)if (c[i] == c[i+1]) dp[i][i+1] = 1;
	
	for (int len = 4; len <= n; len += 2)
	{
		F(l, 1, n - len + 1)
		{
			int r = l + len - 1;
			if (dp[l+1][r-1] && c[l] == c[r]) dp[l][r] = 1;
			if (dp[l][(r+l)>>1] && dp[((r+l)>>1)+1][r]) dp[l][r] = 1;
			bool tag = 1;
			F(i, 0, 25)
				if ((cnt[r][i] - cnt[l-1][i]) & 1) {tag = 0; break;}
			if (tag && !dp[l][r])
			{
				for (int mid = l + 1; mid <= r; mid += 2)
					if (dp[l][mid] == 1 && dp[mid+1][r] == 1)
						{dp[l][r] = 1; break; }
			}
		}
	}
	F(i, 1, n) F(j, i+1, n) ans += dp[i][j];
	cout << ans;
	return 0;
}