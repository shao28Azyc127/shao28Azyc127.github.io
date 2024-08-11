#include <iostream>
#include <cstdio>

using namespace std;

int n, d, a[100050], b[100050];

int mmin (int b, int a)
{
	if (a < b)
		return a;
	return b;
}

void gailu ()
{
	int i;
	b[0] = 2e9;
	for (i = 1; i < n; i++)
	{
		if (a[i] > 0)
		{
			a[i + 1] -= (d - (a[i] % d)) % d;
			a[i] = ((a[i] / d) + (a[i] % d != 0)) * d;
		}
		else
		{
			a[i + 1] += a[i];
			a[i] = 0;
		}
		b[i] = mmin(b[i - 1], b[i]);
	}
}

int main ()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	int i;
	long long int ans;
	cin >> n >> d;
	for (i = 1; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	gailu ();
	ans = 0;
	for (i = 1; i < n; i++)
	{
		//cout << a[i] << " " << b[i] << endl;
		ans += a[i] / d * b[i];
	}
	cout << ans << endl;
	return 0;
}