#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
const int M = 1e5 + 4;
int c, t;
int n, m, k, d;
int dp[N][M];
struct goal
{
	int x, y, v;
}a[N];
bool cmp(goal a, goal b)
{
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}
int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> m >> k >> d;
		for(int i = 1; i <= m; i ++) cin >> a[i].x >> a[i].y >> a[i].v;
		sort(a + 1, a + 1 + m, cmp);
		memset(dp, 0, sizeof(dp));
		int sta = 1;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j < k; j ++) dp[i][j] = dp[i - 1][j + 1];
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			for(int j = sta; j <= m; j ++)
			{
				if(a[j].x > i) break;
				if(a[j].x == i)
				{
					sta ++;
					for(int p = k; p >= a[i].y; p --)
						dp[i][p] = max(dp[i][p], dp[i - a[j].y][p - a[j].y] - a[j].y * d + a[j].v);
				}
			}
		}

		int ans = 0;
		for(int i = 0; i <= k; i ++) ans = max(ans, dp[n][i]);
		cout << ans << endl;
	}

	return 0;
}