#include <bits/stdc++.h>
using namespace std;
int a[100050];
double v[100050], dp[100050], s = 0, cs = 0;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> v[i];
		v[i] = v[i] / d;
		s += v[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cs = 0;
	for (int i = 0; i < (int)(ceil(v[0])); i++)
		dp[i] = a[0] * v[0];
	for (int i = (int)(ceil(v[0])); i <= s; i++)
		dp[i] = a[0] * i;
	for (int i = 1; i < n - 1; i++)
	{
		cs += v[i];
		for (int j = 0; j < (int)ceil(v[i]); j++)
		{
			dp[j] = min(dp[0]+a[i]*v[i], a[i] * ceil(v[i]));
		}
		for (int j = (int)ceil(v[i]); j < (int)ceil(s - cs); j++)
		{
			dp[j] = min(dp[j + (int)ceil(v[i-1])], dp[0]+a[i]*j);
		}
	}
	printf("%d", (int)ceil(dp[0]));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

