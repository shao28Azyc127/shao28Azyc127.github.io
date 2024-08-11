#include <iostream>
#include <cstdio>
using namespace std;

int n;
double d;
int v[100010], a[100010];
int ans;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		v[i] = v[i - 1] + x;
	}
	bool flagA = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] < a[1]) flagA = false;
	}
	if (flagA)
	{
		cout << v[n] * 1.0 / d * a[1] << endl;
		return 0;
	}
	double less = 0;
	int i = 1;
	while (i < n)
	{
		int pos = n + 1;
		for (int j = i; j <= n - 1; j++)
			if (a[j] < a[i])
			{
				pos = j;
				break ;
			}
		if (pos == n + 1)
		{
			double need = (v[n] - v[i]) * 1.0 / d - less;
			if (int(need) == need) 
				ans += int(need) * a[i];
			else
				ans += int(need + 1) * a[i];
			cout << ans << endl;
			return 0;
		}
		else
		{
			double need = (v[pos] - v[i]) * 1.0 / d;
			if (int(need) == need) 
				ans += int(need) * a[i];
			else 
			{
				ans += int(need + 1) * a[i];
				less += int(need + 1) - need;
			}
			i = pos;
		}
	}
    cout << ans << endl;
	return 0;
}