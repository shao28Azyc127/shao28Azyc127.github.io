#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int chk(int d)
{
	int r = 1;
	for (int i = 1; i <= sqrt(d); i++)
	{
		if (d % (i * i) == 0)
		{
			r = i;
		}
	}
	return r;
}

int gcd(int x, int y)
{
	if (x < 0 && y > 0)
	{
		return  -1 * gcd(x * -1, y * -1);
	}
	x = abs(x);
	y = abs(y);
	if (x == 0 || y == 0)
	{
		return 1;
	}
	if (max(x, y) % min(x, y) == 0)
	{
		return min(x, y);
	}
	return (min(x, y), max(x, y) % min(x, y));
}

int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a, b, c;
	int delta, x, y, ans;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
		delta = b * b - a * c * 4;
		if (delta < 0)
		{
			cout << "NO" << endl;
		}
		else
		{
			x = chk(delta);
			if (x * x == delta || delta == 0)
			{
				if (delta != 0)
				{
					b += x * -1;
				}
				if (b % (a * 2) == 0)
				{
					ans = b / (a * 2) * -1;
					cout << ans << endl;
				}
				else
				{
					y = gcd(a * 2, b);
					cout << b / y * -1 << "/" << a * 2 / y << endl;
				}
			}
			else
			{
				if (b % (a * 2) == 0)
				{
					ans = b / (a * 2) * -1;
					cout << ans;
				}
				else
				{
					y = gcd(a * 2, b);
					cout << b / y * -1 << "/" << a * 2 / y;
				}
				cout << "+";
				delta /= (x * x);
				a = abs(a * 2);
				y = gcd(a, x);
				a /= y;
				x /= y;
				if (x == 1)
				{
					cout << "sqrt(" << delta << ")";
				}
				else
				{
					cout << x << "*sqrt(" << delta << ")";
				}
				if (a != 1)
				{
					cout << "/" << a;
				}
				cout << endl;
			}
		}
	}
	return 0;
}