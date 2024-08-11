#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;
ll d;
ll dp[1001][1001];
struct bon
{
	int r, y;
	ll v;
	bon (int _r, int _y, ll _v)
	{
		r = _r, y = _y, v = _v;
	}
};
vector <bon> lis[1001];

void Solve()
{
	int r, y, v;
	cin >> n >> m >> k >> d;
	for (int i = 1; i <= n; i++) lis[i].clear();
	for (int i = 1; i <= m; i++)
	{
		cin >> r >> y >> v;
		if (y <= k) lis[r].push_back(bon(r, y, v));
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= min(n, k); j++)
		{
			dp[i][j] = -2e18;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= min(i - 1, k); j++) dp[i][0] = max(dp[i][0], dp[i - 1][j]);
//		cerr << dp[i][0] << ' ';
		for (int j = 1; j <= min(i, k); j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] - d);
			for (auto it : lis[i])
			{
				if (j >= it.y) dp[i][j] += it.v;
			}
//			cerr << dp[i][j] << ' ';
		}
//		cerr << endl;
	}
	ll ans = -2e18;
	for (int i = 0; i <= min(n, k); i++)
	{
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl;
}

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) Solve();
	return 0;
}