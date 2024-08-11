#include<bits/stdc++.h>
using namespace std;
int v[100010], a[100010];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	for(int i = 1; i < n; i++)
	{
		cin >> v[i];
		v[i] += v[i - 1];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans = 1e9;
	for(int i = 1; i <= n; i++)
	{
		ans = min(ans, v[i - 1] / d * a[1] + (v[n - 1] - v[i - 1]) / d * a[i]);
	}
	cout << ans << endl;
	return 0;
}