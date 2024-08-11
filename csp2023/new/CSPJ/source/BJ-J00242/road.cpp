# include <bits/stdc++.h>
using namespace std;

int n, d, v[100005], a[100005];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	long long sum = 0;
	for (int i = 1; i < n; i++)
	{	
		cin >> a[i];
		sum += a[i];
	}
	cin >> v[1];
	bool f = 1;
	for (int i = 2; i <= n; i++)
	{
		cin >> v[i];
		if (v[i] < v[1]) f = 0;
	}
	if (f)
	{
		if (sum % d == 0)
			cout << v[1] * (sum / d);
		else cout << v[1] * (sum / d + 1);
	}
	return 0;
}
