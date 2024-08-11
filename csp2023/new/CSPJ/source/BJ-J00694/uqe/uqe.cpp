#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int t, m, a, b, c;

int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> t >> m;
	while (t--)
	{
		cin >> a >> b >> c;
		if (b == 0 && c == 0) 
		{
			cout << 0;
			return 0;
		}
		int nu = b * b - 4 * a * c;
		if (nu < 0) cout << "NO" << endl;
		if (nu == 0)
		{
			int x = sqrt(nu);
			if (x * x == nu) 
			{
				if (x % a == 0 && (x / a) % 2 == 0) cout << x / a / 2 << endl; 
				if (x % a == 0 && (x / a) % 2 != 0) cout << x / a << "/2" << endl; 
				if (x % a != 0 && (x / a) % 2 == 0) cout << x / gcd(max(x / 2, a), min(x / 2, a)) << "/" << a / gcd(max(x / 2, a), min(x / 2, a)) << endl; 
				if (x % a != 0 && (x / a) % 2 != 0) cout << x / gcd(max(x / 2, 2 * a), min(x / 2, 2 * a)) << "/" << 2 * a /gcd(max(x / 2, 2 * a), min(x / 2, 2 * a)) << endl;
			}
			else cout << "sqrt(" << nu << ")" << endl;
		}
		if (nu > 0)
		{
			cout << 1 << endl;
		}
	}
	return 0;
}