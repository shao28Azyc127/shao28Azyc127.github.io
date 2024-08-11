#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int v[100010], a[100010];
int dp[100010];

int sum(int x, int y)
{
	int ans = 0;
	for (int i = x; i < y; i++)
	{
		ans += v[i];
	}
	return ans;
}

int main()
{
	freopen("road2.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 2147483647;
		for (int j = 1; j <= i - 1; j++)
		{
			dp[i] = min(dp[i], dp[j] + (sum(j, i) - sum(1, j) % d + d - 1) / d * a[j]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}