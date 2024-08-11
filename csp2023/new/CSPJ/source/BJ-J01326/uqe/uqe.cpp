#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int a, b, c, t, m;

bool gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b, a%b);
}

int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	for (int k = 1; k <= t; k++)
	{
		cin >> a >> b >> c;
		int z = b * b - 4 * a * c;
		if (z < 0) cout << "NO" << endl;
		else
		{
			int x = max(1.0*(0-b + sqrt(z)) / 2*a, 1.0*(0-b - sqrt(z)) / 2*a);
			for (int q = 1; q <= m; q++)
				for (int p = 1; p <= m; p++)
					if (gcd(q, p) == 1 & p / q == x)
			if (q == 1) cout << p << endl;
			else cout << p / q << endl;
		}
	}
	
	return 0;
}