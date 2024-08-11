#include <bits/stdc++.h>
using namespace std;
int a[5005], b[5005], c[5005], derta[5005];
int gcd(int x, int y)
{
	if(x < 0)
		x *= -1;
	if(y < 0)
		y *= -1;
	if(y > x)
		swap(x, y);
	if(x % y == 0)
		return y;
	return gcd(y, x % y);
}
int main()
{
	int m, n;
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i] >> c[i];
		derta[i] = (b[i] * b[i]) - (4 * a[i] * c[i]);
		if(derta[i] < 0)
			cout << "NO" << endl;
		else if(derta[i] == 0)
		{
			int mu, zi;
			mu = 2 * a[i];
			zi = -1 * b[i];
			if(zi == 0)
				cout << "0" << endl;
			else if(zi % mu == 0)
				cout << zi / mu << endl;
			else
				cout << zi / gcd(zi, mu) << "/" << mu / gcd(zi, mu) << endl;
		}
		else
		{
			int mu, zi;
			double q1, q2;
			mu = 2 * a[i];
			zi = -1 * b[i];
			int k = sqrt(derta[i]);
			while(k > 0)
			{
				if(derta[i] % (k * k) == 0)
					break;
				k--;
			}
			int d = derta[i] / (k * k);
			if(zi % mu == 0 && zi != 0)
				cout << zi / mu << "+";
			else if(zi != 0)
				cout << zi / gcd(zi, mu) << "/" << mu / gcd(zi, mu) << "+";
			if(d == 1)
			{
				if(k % mu == 0)
					cout << k / mu << endl;
				else
					cout << k / gcd(mu, k) << "/" << mu / gcd(mu, k) << endl;
			}
			else
			{
				if(k == 1)
					cout << "sqrt(" << d << ")/" << mu << endl;
				else if(k == mu)
					cout << "sqrt(" << d << ")" << endl;
				else if(k % mu == 0)
					cout << k / mu << "*sqrt(" << d << ")" << endl;
				else
				{
					if(k == gcd(mu, k))
						cout << "sqrt(" << d << ")/" << mu / gcd(mu, k) << endl;
					else
						cout << k / gcd(mu, k) << "*sqrt(" << d << ")/" << mu / gcd(mu, k) << endl;
				}
			}
		}
	}
	return 0;
}