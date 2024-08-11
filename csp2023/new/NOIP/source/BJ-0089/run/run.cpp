#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;
#define int long long

int read()
{
	int s = 0, f = 1, ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * f;
}

struct mission
{
	int x, y, v;
	friend bool operator < (mission a, mission b)
	{
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	}
}a[N * 100];
int c, t, n, m, k, d;
int dp[N][N];

signed main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	c = read(); t = read();
	while(t--)
	{
		memset(dp, 0, sizeof(dp));
		n = read(); m = read(); 
		k = read(); d = read();
		for(int i = 1; i <= m; i++)
			a[i].x = read(), a[i].y = read(), a[i].v = read();
		if(c == 17 || c == 18)
		{
			int ans = 0;
			for(int i = 1; i <= m; i++)
				if(a[i].v > a[i].y * d && a[i].y <= k) ans += (a[i].v - a[i].y * d);
			cout << ans << endl;
			continue;
		}
		sort(a + 1, a + 1 + m);
		int pt = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j <= min(i - 1, k); j++)
				dp[i][0] = max(dp[i][0], dp[i - 1][j]);
			int bonus = 0;
			for(int j = 1; j <= min(i, k); j++)
			{
				while(a[pt].x == i && a[pt].y <= j && pt <= m)
				{
					bonus += a[pt].v;
					pt++;
				}
				dp[i][j] = dp[i - 1][j - 1] - d + bonus;
			}
		}
		int ans = 0;
		for(int j = 0; j <= k; j++)
			ans = max(ans, dp[n][j]);
		cout << ans << endl;
	}
	return 0;
}
