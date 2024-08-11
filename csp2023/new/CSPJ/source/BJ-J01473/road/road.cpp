#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int v[N], a[N], n, d;
int sum1[N];
long long sum = 0;
int dfs(int ans1)
{
	int minx = INT_MAX, ansx = 0;
	for(int i = 1;i < ans1;i++)
		if(a[i] < minx)
	 		minx = a[i], ansx = i;
	if(ansx == 1)
	{
		int f = ((sum1[ans1] - sum1[ansx]) + d - 1) / d;
		int fl = f * d - (sum1[ans1] - sum1[ansx]);
		sum += f * a[ansx];
		return fl;
	}
	int r = dfs(ansx);
	int f = ((sum1[ans1] - sum1[ansx]) + d - 1 - r) / d;
	int fl = f * d - (sum1[ans1] - sum1[ansx] - r);
	sum += f * a[ansx];
	return fl;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for(int i = 1;i < n;i++)
		cin >> v[i], sum1[i + 1] = sum1[i] + v[i];
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sum1[n + 1] = sum1[n];
	dfs(n + 1);
	cout << sum;
	return 0;
}